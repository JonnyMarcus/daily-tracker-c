#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

#define ARQUIVO "data/tarefas.txt"

void salvar(Tarefa *lista){
    FILE *f = fopen(ARQUIVO, "w");

    if(!f){
        printf("ERRO ao abrir arquivo para salvar!\n");
        return;
    }

    while(lista){
        fprintf(f, "%s|%d|%d|%s\n",
            lista->descricao,
            lista->concluida,
            lista->prioridade,
            lista->data
        );

        lista = lista->prox;
    }

    fclose(f);
}

Tarefa* carregar(){
    FILE *f = fopen(ARQUIVO, "r");

    if(!f){
        return NULL;
    }

    Tarefa *lista = NULL;
    char linha[200];

    while(fgets(linha, sizeof(linha), f)){

        Tarefa *nova = calloc(1, sizeof(Tarefa));
        if(!nova) break;

        char *token = strtok(linha, "|");

        if(token){
            token[strcspn(token, "\r\n")] = 0;
            strncpy(nova->descricao, token, sizeof(nova->descricao)-1);
        }

        token = strtok(NULL, "|");
        if(token){
            nova->concluida = atoi(token);
        }

        token = strtok(NULL, "|");
        if(token){
            nova->prioridade = (Prioridade)atoi(token);
        }

        token = strtok(NULL, "|\n");
        if(token){
            token[strcspn(token, "\r\n")] = 0;
            strncpy(nova->data, token, sizeof(nova->data)-1);
        }

        nova->prox = NULL;

        // inserir no final da lista
        if(lista == NULL){
            lista = nova;
        } else {
            Tarefa *temp = lista;
            while(temp->prox != NULL){
                temp = temp->prox;
            }
            temp->prox = nova;
        }
    }

    fclose(f);
    return lista;
}