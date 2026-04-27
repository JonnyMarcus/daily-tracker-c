#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tarefa.h"

#define RESET   "\033[0m"
#define VERDE   "\033[32m"
#define VERMELHO "\033[31m"
#define AMARELO "\033[33m"

Tarefa* inserir_ordenado(Tarefa *lista, Tarefa *nova) {
    if (lista == NULL || strcmp(nova->data, lista->data) < 0) {
        nova->prox = lista;
        return nova;
    }

    Tarefa *aux = lista;

    while (aux->prox != NULL &&
           strcmp(aux->prox->data, nova->data) <= 0) {
        aux = aux->prox;
    }

    nova->prox = aux->prox;
    aux->prox = nova;

    return lista;
}

Tarefa* adicionar(Tarefa *lista, const char *desc, Prioridade prioridade, const char *data) {
    Tarefa *nova = malloc(sizeof(Tarefa));
    if (!nova) return lista;

    strncpy(nova->descricao, desc, sizeof(nova->descricao));
    nova->descricao[99] = '\0';

    nova->concluida = 0;
    nova->prioridade = prioridade;

    strncpy(nova->data, data, sizeof(nova->data));
    nova->data[10] = '\0';

    nova->prox = NULL;

    return inserir_ordenado(lista, nova);
}

void listar(Tarefa *lista) {
    int i = 0;

    while (lista != NULL) {
        printf("[%d] %s | %s | %s\n",
               i,
               lista->descricao,
               lista->concluida ? VERDE "Concluída" RESET : VERMELHO "Pendente" RESET,
               lista->data);

        lista = lista->prox;
        i++;
    }
}

void concluir(Tarefa *lista, int id) {
    int i = 0;

    while (lista != NULL) {
        if (i == id) {
            lista->concluida = 1;
            return;
        }
        lista = lista->prox;
        i++;
    }
}

Tarefa* remover(Tarefa *lista, int id) {
    Tarefa *aux = lista;
    Tarefa *ant = NULL;
    int i = 0;

    while (aux != NULL) {
        if (i == id) {
            if (ant == NULL) {
                Tarefa *novo = aux->prox;
                free(aux);
                return novo;
            } else {
                ant->prox = aux->prox;
                free(aux);
                return lista;
            }
        }
        ant = aux;
        aux = aux->prox;
        i++;
    }

    return lista;
}

int contar(Tarefa *lista) {
    int c = 0;
    while (lista) {
        c++;
        lista = lista->prox;
    }
    return c;
}

int contar_concluidas(Tarefa *lista) {
    int c = 0;
    while (lista) {
        if (lista->concluida) c++;
        lista = lista->prox;
    }
    return c;
}

void barra_progresso(int feitas, int total) {
    if (total == 0) {
        printf("Sem tarefas\n");
        return;
    }

    int percent = (feitas * 100) / total;

    printf("Progresso: [");

    for (int i = 0; i < 20; i++) {
        if (i < percent / 5)
            printf("#");
        else
            printf("-");
    }

    printf("] %d%%\n", percent);
}

void listar_por_data(Tarefa *lista, const char *data) {
    while (lista) {
        if (strcmp(lista->data, data) == 0) {
            printf("%s | %s\n", lista->descricao,
                   lista->concluida ? "OK" : "Pendente");
        }
        lista = lista->prox;
    }
}

int comparar(Tarefa *a, Tarefa *b) {
    return strcmp(a->data, b->data);
}

void data_atual(char *buffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    sprintf(buffer, "%04d-%02d-%02d",
            tm.tm_year + 1900,
            tm.tm_mon + 1,
            tm.tm_mday);
}

int esta_atrasada(Tarefa *t) {
    char hoje[11];
    data_atual(hoje);

    return strcmp(t->data, hoje) < 0 && !t->concluida;
}