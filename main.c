#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "queue.h"

void mostrarMenu(){
    printf("\nMENU OPCIONES - SELECCIONE UNA OPCIÓN:\n");
    printf("1. Ingresar ticket.\n");
    printf("2. Asignar prioridad.\n");
    printf("3. Mostrar lista de tickets pendientes.\n");
    printf("4. Procesar ticket.\n");
    printf("5. Buscar ticket.\n");
    printf("0. Salir.\n");
}

void ingresarTicket(ColaPrior *queue) {
    printf("Inserte ID del ticket:\n");
    char dato[100];
    char descripcion[1000];

    scanf("%s", dato);

    printf("Ingrese decripción:\n");
    scanf(" %[^\n]", descripcion);

    insertQueue(queue, dato);
    queue->tail->horaCreacion = time(NULL);
    strcpy(queue->tail->des, descripcion);
}

void asignarPrior(Prioridad *queue) {
    printf("Inserte ID del ticket:\n");
    char dato[100];
    scanf("%s", dato);

    Node* prev = NULL;
    Node* aux = queue->baja.head;

    while (aux != NULL)
    {
        if (strcmp(aux->id, dato) == 0) break;
        prev = aux;
        aux = aux->next;
    }

    if (aux == NULL) {
        printf("No se ha encontrado la ID.\n");
        return;
    }

    char prior[20];
    while (1)
    {
        printf("Ingrese prioridad (Alta, Media o Baja):\n");
        scanf("%s", prior);

        if (strcmp(prior, "Alta") == 0) {
            insertQueue(&queue->alta, dato);
            strcpy(queue->alta.tail->des, aux->des);
            queue->alta.tail->horaCreacion = aux->horaCreacion;
            break;
        }
        else if (strcmp(prior, "Media") == 0) {
            insertQueue(&queue->media, dato);
            strcpy(queue->media.tail->des, aux->des);
            queue->media.tail->horaCreacion = aux->horaCreacion;
            break;
        }
        else if (strcmp(prior, "Baja") == 0) return;
        else printf("Inténtelo de nuevo\n");
    }

    if (prev == NULL) queue->baja.head = aux->next;
    else prev->next = aux->next;
    if (queue->baja.tail == aux) queue->baja.tail = prev;
    free(aux->id);
    free(aux);
    queue->baja.size--;
}

void mostrarLista(Prioridad *queue) {
    Node* aux;
    bool hayTickets = false;

    
    printf("//TICKETS PENDIENTES//\n");
    aux = queue->alta.head;
    while (aux != NULL)
    {
        hayTickets = true;
        printf("Prioridad del ticket: ALTA\n");
        printf("ID: %s\n", aux->id);
        printf("Descripción: %s\n", aux->des);
        printf("Hora: %s\n", ctime(&aux->horaCreacion));
        printf("--------------------------\n");
        aux = aux->next;
    }

    aux = queue->media.head;
    while (aux != NULL)
    {
        hayTickets = true;
        printf("Prioridad del ticket: MEDIA\n");
        printf("ID: %s\n", aux->id);
        printf("Descripción: %s\n", aux->des);
        printf("Hora: %s\n", ctime(&aux->horaCreacion));
        printf("--------------------------\n");
        aux = aux->next;
    }
    
    aux = queue->baja.head;
    while (aux != NULL)
    {
        hayTickets = true;
        printf("Prioridad del ticket: BAJA\n");
        printf("ID: %s\n", aux->id);
        printf("Descripción: %s\n", aux->des);
        printf("Hora: %s\n", ctime(&aux->horaCreacion));
        printf("--------------------------\n");
        aux = aux->next;
    }
    if (!hayTickets) printf("No hay tickets pendientes.\n");
}

void procesarTicket(Prioridad *queue) {
    Node* aux;
    printf("//INICIO DE PROCESAMIENTO//\n");

    if ((aux = queue->alta.head)) {
        printf("Ticket encontrado:\n");
        printf("ID: %s\n", aux->id);
        printf("Descripción: %s\n", aux->des);
        printf("Prioridad: ALTA\n");

        char horaStr[100];
        struct tm *tm_info = localtime(&aux->horaCreacion);
        strftime(horaStr, sizeof(horaStr), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("Hora de creación: %s\n", horaStr);
        removeQueue(&queue->alta);

    } else if ((aux = queue->media.head)) { 
        printf("Ticket encontrado:\n");
        printf("ID: %s\n", aux->id);
        printf("Descripción: %s\n", aux->des);
        printf("Prioridad: MEDIA\n");

        char horaStr[100];
        struct tm *tm_info = localtime(&aux->horaCreacion);
        strftime(horaStr, sizeof(horaStr), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("Hora de creación: %s\n", horaStr);
        removeQueue(&queue->media);

    } else if ((aux = queue->baja.head)) {
        printf("Ticket encontrado:\n");
        printf("ID: %s\n", aux->id);
        printf("Descripción: %s\n", aux->des);
        printf("Prioridad: BAJA\n");

        char horaStr[100];
        struct tm *tm_info = localtime(&aux->horaCreacion);
        strftime(horaStr, sizeof(horaStr), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("Hora de creación: %s\n", horaStr);
        removeQueue(&queue->baja);

    } else printf("No hay tickets pendientes para procesar.\n");
}

void buscarTicket(Prioridad *queue) {
    char buscar[100];
    printf("Ingrese ID del ticket:\n");
    scanf("%s", buscar);

    Node* aux;

    aux = queue->alta.head;
    printf("//INICIO DE PROCESAMIENTO//\n");
    while (aux != NULL)
    {
        if (strcmp(aux->id, buscar) == 0) {
            printf("Ticket encontrado:\n");
            printf("ID: %s\n", aux->id);
            printf("Descripción: %s\n", aux->des);
            printf("Prioridad: ALTA\n");

            char horaStr[100];
            struct tm *tm_info = localtime(&aux->horaCreacion);
            strftime(horaStr, sizeof(horaStr), "%Y-%m-%d %H:%M:%S", tm_info);
            printf("Hora de creación: %s\n", horaStr);
            return;
        }
        aux = aux->next;
    }

    aux = queue->media.head;
    while (aux != NULL)
    {
        if (strcmp(aux->id, buscar) == 0) {
            printf("Ticket encontrado:\n");
            printf("ID: %s\n", aux->id);
            printf("Descripción: %s\n", aux->des);
            printf("Prioridad: MEDIA\n");

            char horaStr[100];
            struct tm *tm_info = localtime(&aux->horaCreacion);
            strftime(horaStr, sizeof(horaStr), "%Y-%m-%d %H:%M:%S", tm_info);
            printf("Hora de creación: %s\n", horaStr);
            return;
        }
        aux = aux->next;
    }
    
    aux = queue->baja.head;
    while (aux != NULL)
    {
        if (strcmp(aux->id, buscar) == 0) {
            printf("Ticket encontrado:\n");
            printf("ID: %s\n", aux->id);
            printf("Descripción: %s\n", aux->des);
            printf("Prioridad: BAJA\n");

            char horaStr[100];
            struct tm *tm_info = localtime(&aux->horaCreacion);
            strftime(horaStr, sizeof(horaStr), "%Y-%m-%d %H:%M:%S", tm_info);
            printf("Hora de creación: %s\n", horaStr);
            return;
        }
        aux = aux->next;
    }
    printf("No se encontró ningún ticket con la ID proporcionada.\n");
}

void ejecutarPrograma() {
    Prioridad prioridades;
    ColaPrior* baja = createQueue();
    ColaPrior* media = createQueue();
    ColaPrior* alta = createQueue();
    
    if (!baja || !media || !alta) {
        printf("Error al crear colas de prioridad.\n");
        return;
    }
    prioridades.baja = *baja;
    prioridades.media = *media;
    prioridades.alta = *alta;

    while (1)
    {
        mostrarMenu();
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "0") == 0 || strcmp(op, "salir") == 0) {
            printf("Saliendo del programa...\n");
            break;
        }

        if(strcmp(op,"1") == 0) ingresarTicket(&prioridades.baja);
        else if (strcmp(op, "2") == 0) asignarPrior(&prioridades);
        else if (strcmp(op, "3") == 0) mostrarLista(&prioridades);
        else if (strcmp(op, "4") == 0) procesarTicket(&prioridades);
        else if (strcmp(op, "5") == 0) buscarTicket(&prioridades);
        else printf("Respuesta inválida, inténtelo de nuevo.\n");
    }
    free(baja);
    free(media);
    free(alta);
}

int main(){
    ejecutarPrograma();
    return 0;
}