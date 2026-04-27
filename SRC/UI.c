#include <stdio.h>
#include <stdlib.h>

#define RESET   "\033[0m"
#define CIANO   "\033[36m"
#define AMARELO "\033[33m"

void limpar_tela(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar(){
    printf("\nPressione Enter para continuar...");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
}

void mostrar_menu(){
    printf(CIANO "\n===== DAILY TRACKER =====\n" RESET);
    printf("1 - Adicionar tarefa\n");
    printf("2 - Listar tarefas\n");
    printf("3 - Concluir tarefa\n");
    printf("4 - Remover tarefa\n");
    printf("5 - Progresso\n");
    printf("6 - Buscar por data\n");
    printf("0 - Sair\n");
    printf(AMARELO "Escolha: " RESET);
}