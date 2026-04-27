#ifndef TAREFA_H
#define TAREFA_H

typedef enum {
    BAIXA,
    MEDIA,
    ALTA
} Prioridade;

typedef struct Tarefa {
    char descricao[100];
    int concluida;
    Prioridade prioridade;
    char data[11];
    struct Tarefa *prox;
} Tarefa;

Tarefa* adicionar(Tarefa *lista, const char *desc, Prioridade prioridade, const char *data);
void listar(Tarefa *lista);
void concluir(Tarefa *lista, int id);
Tarefa* remover(Tarefa *lista, int id);

int contar(Tarefa *lista);
int contar_concluidas(Tarefa *lista);

void listar_por_data(Tarefa *lista, const char *data);
void barra_progresso(int feitas, int total);

Tarefa* inserir_ordenado(Tarefa *lista, Tarefa *nova);
int comparar(Tarefa *a, Tarefa *b);

void data_atual(char *buffer);
int esta_atrasada(Tarefa *t);

#endif