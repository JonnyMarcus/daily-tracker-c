#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tarefa.h"
#include "arquivo.h"
#include "UI.h"

void limpar_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(){
    Tarefa *lista = carregar();
    int opcao;

    while(1){
        limpar_tela();
        mostrar_menu();

        if(scanf("%d", &opcao) != 1){
            printf("Entrada invalida!\n");
            limpar_buffer();
            pausar();
            continue;
        }

        limpar_buffer();

        switch(opcao){

            case 1: {
                char desc[100];
                int prioridade;
                char data[11];

                printf("Descricao: ");
                fgets(desc, sizeof(desc), stdin);
                desc[strcspn(desc, "\n")] = 0;

                do{
                    printf("Prioridade (0=Baixa,1=Media,2=Alta): ");
                    if(scanf("%d", &prioridade) != 1){
                        printf("Entrada invalida!\n");
                        limpar_buffer();
                        prioridade = -1;
                        continue;
                    }
                    limpar_buffer();
                }while(prioridade < 0 || prioridade > 2);

                printf("Data (YYYY-MM-DD): ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = 0;

                lista = adicionar(lista, desc, prioridade, data);

                printf("Tarefa adicionada!\n");
                break;
            }

            case 2:
                listar(lista);
                break;

            case 3: {
                int id;

                printf("ID da tarefa: ");
                if(scanf("%d", &id) != 1){
                    printf("Entrada invalida!\n");
                    limpar_buffer();
                    break;
                }
                limpar_buffer();

                concluir(lista, id);
                break;
            }

            case 4: {
                int id;

                printf("ID da tarefa: ");
                if(scanf("%d", &id) != 1){
                    printf("Entrada invalida!\n");
                    limpar_buffer();
                    break;
                }
                limpar_buffer();

                lista = remover(lista, id);
                break;
            }

            case 5: {
                int total = contar(lista);
                int feitas = contar_concluidas(lista);
                barra_progresso(feitas, total);
                break;
            }

            case 6: {
                char data[11];

                printf("Digite a data (YYYY-MM-DD): ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = 0;

                listar_por_data(lista, data);
                break;
            }

            case 0:
                salvar(lista);
                printf("Salvando e saindo...\n");
                return 0;

            default:
                printf("Opcao invalida!\n");
        }

        pausar();
    }
}