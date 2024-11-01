#include <stdio.h>
#include <stdlib.h>
#include "listaD.c"
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "portuguese-brazilian");
    Lista L, lista_copia, lista3, lista_impares, lista_pares;
    ListaFreq L2;
    tipo_elem v;
    int chave;
    int op;
    int optemp; // op temporario para essa caso
    definir(&L);

    do
    {
        limparTela();
        printf("\nLista\n\n");
        printf("1 - Verificar se a lista está vazia\n");
        printf("2 - Destruir lista\n");
        printf("3 - Exibir lista\n");
        printf("4 - Inserir no início\n");
        printf("5 - Inserir no final\n");
        printf("6 - Inserir de forma ordenada\n");
        printf("7 - Remover do início\n");
        printf("8 - Remover do final\n");
        printf("9 - Remover elemento pela chave\n");
        printf("10 - Ver tamanho da lista\n");
        printf("11 - Buscar chave\n");
        printf("12 - Verificar se a lista está ordenada\n");
        printf("13 - Copiar lista (eliminando ou não repetidos)\n");
        printf("14 - Copiar lista Invertida\n");
        printf("15 - intercalar lista 1 e lista 2 em uma terceira (ambas tem que estar ordenadas)\n");
        printf("16 - Gerar lista de frequencia da lista 1\n");
        printf("17 - separar a lista em impar par\n");

        printf("0 - Sair\n");

        scanf("%d", &op);
        switch (op)
        {
        case 1:
            if (vazia(&L))
                printf("Lista vazia\n");
            else
                printf("Lista não está vazia\n");
            pausar();
            break;
        case 2:
            // limparTela();;
            destruir(&L);
            pausar();
            break;
        case 3:
            // limparTela();;
            exibir(&L);
            pausar();
            break;

        case 4:
            // limparTela();;
            printf("Digite a chave para inserir no início: ");
            scanf("%d", &v.chave);
            inserirInicio(&L, v);
            pausar();
            break;

        case 5:
            // limparTela();;
            printf("Digite a chave para inserir no final: ");
            scanf("%d", &v.chave);
            inserirFinal(&L, v);
            pausar();
            break;

        case 6:
            // limparTela();;
            printf("Digite a chave para inserir de forma ordenada: ");
            scanf("%d", &v.chave);
            inserirOrdenada(&L, v);
            pausar();
            break;

        case 7:
            // limparTela();;
            removerInicio(&L);
            
            break;

        case 8:
            // limparTela();;
            removerFinal(&L);
            break;

        case 9:
            // limparTela();;
            printf("Digite a chave para remover: ");
            scanf("%d", &chave);
            removerElemento(&L, chave);
            pausar();
            break;
        case 10:
            // limparTela();
            printf("Tamanho da lista: %d\n", tamanho(&L));
            // tamanho(&L);
            pausar();
            break;
        case 11:
            printf("digite a chave: ");
            scanf("%d", &chave);
            buscarLista(&L, chave);
            pausar();
            break;
        case 12:
            // limparTela();;
            if (verifOrdenada(&L))
            {
                printf("A lista está ordenada \n");
            }
            else
            {
                printf("A lista não está ordenada\n");
            }
            pausar();
            break;
        case 13:
            // limparTela();;
            printf("Deseja eliminar os elementos repetidos? (1-Sim, 0-Não): ");
            scanf("%d", &optemp);

            if (optemp == 1)
            {
                if (copiarListaUnica(&L, &lista_copia))
                {
                    printf("Lista copiada sem repetidos:\n");
                    exibir(&lista_copia);
                }
                else
                {
                    printf("Erro ao copiar a lista.\n");
                }
            }

            else
            {
                if (copiarLista(&L, &lista_copia))
                {
                    printf("Lista copiada com todos os elementos:\n");
                    exibir(&lista_copia);
                }
                else
                {
                    printf("Erro ao copiar a lista.\n");
                }
            }
            pausar();
            break;
        case 15:
            if (intercalaLista1Lista2(&L, &lista_copia, &lista3))
            {
                printf("Lista 3 criada com sucesso:\n");
                exibir(&lista3);
            }
            else
            {
                printf("Erro ao copiar a lista.\n");
            }
            pausar();
            break;

        case 14:
            if (copiarListaInvertida(&L, &lista_copia))
            {
                printf("Lista copiada sem repetidos: \n");
                exibir(&lista_copia);
            }
            else
            {
                printf("Erro ao copiar a lista.\n");
            }
            pausar();
            break;
        case 16:
            gerarListaDeFrequencia(&L, &L2);
            
            printf("Lista de Frequência:\n");
            exibirListaFrequencia(&L2);
            pausar();
            break;
        case 17:
            separarParesImpares(&L, &lista_pares, &lista_impares);
            printf("Lista de Pares:\n");
            exibir(&lista_pares);

            printf("\nLista de Impares:\n");
            exibir(&lista_impares);
            pausar();
            break;
        }
    } while (op != 0);
    destruir(&L);
    destruir(&lista_copia);        
    destruir(&lista3); 
    destruir(&lista_impares); 
    destruir(&lista_pares);
    destruirListaFreq(&L2);                
    return 0;
}
