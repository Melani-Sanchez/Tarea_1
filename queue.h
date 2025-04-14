#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    char *id;
    char des[1000];
    struct Node* next;
    time_t horaCreacion;
} Node;

typedef struct ColaPrior {
    Node* head;
    Node* tail;
    int size;
} ColaPrior;

typedef struct {
    ColaPrior alta;
    ColaPrior media;
    ColaPrior baja;
} Prioridad;

Node* createNode(char* key); //Crea un nuevo nodo para ser insertado en una cola.

ColaPrior *createQueue(); //Crea e inicializa una nueva cola de prioridad vacía.

void insertQueue(ColaPrior *queue, char *dato); //Inserta un nuevo nodo con el identificador dato al final de la cola especificada.

void *removeQueue(ColaPrior *queue); //Elimina el primer nodo de la cola especificada (el más antiguo) y libera la memoria asociada a él.

Node* createNode(char* key) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) return NULL;

    newNode->id = (char*) malloc(strlen(key) + 1);
    if (newNode->id == NULL) {
        free(newNode);
        return NULL;
    }

    strcpy(newNode->id, key);
    newNode->next = NULL;

    return newNode;
}


ColaPrior *createQueue() {
    ColaPrior* queue = (ColaPrior*) malloc (sizeof(ColaPrior));
    if (queue == NULL) return NULL;

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

void insertQueue(ColaPrior *queue, char *dato) {
    Node* newNode = createNode(dato);
    if (newNode == NULL || queue == NULL) return;

    newNode->id = strdup(dato);
    if (newNode->id == NULL) {
        free(newNode);
        return;
    }

    if (queue->head == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size ++;
}

void *removeQueue(ColaPrior *queue) {
    if (queue == NULL || queue->head == NULL) return NULL;

    Node* aux = queue->head;
    char* dato = strdup(aux->id);
    if (dato == NULL) return NULL;

    queue->head = queue->head->next;
    if (queue->head == NULL) queue->tail = NULL; 

    free(aux->id);
    free(aux);
    queue->size--;
    return dato;
}
