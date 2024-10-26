#include <stdio.h>
#include <stdlib.h>
#include "listaD.c"
#include <locale.h>

int main(){
    Lista L;
    tipo_elem v;
    int chave;
    int op;
    definir(&L);

    do {

        printf("Lista\n\n");
        printf("1 - Verificar se a lista está vazia\n");
        printf("3 - Exibir lista\n");
        printf("2 - Destruir lista\n");
        printf("4 - Inserir no início\n");
        printf("5 - Inserir no final\n");
        printf("6 - Inserir de forma ordenada\n");
        printf("7 - Remover do início\n");
        printf("8 - Remover do final\n");
        printf("9 - Remover elemento pela chave\n");
        printf("10 - Ver tamanho da lista\n");
        printf("11 - Buscar chave\n");
        printf("0 - Sair\n");

        scanf("%d", &op);
        switch (op) {
            case 1:
                if (vazia(&L))
                    printf("Lista vazia\n");
                else
                    printf("Lista não está vazia\n");
            break;
            case 2:
                destruir(&L);
            break;
            case 3:
                exibir(&L);
                break;

            case 4:
                printf("Digite a chave para inserir no início: ");
                scanf("%d", &v.chave);
                inserirInicio(&L, v);
                break;

            case 5:
                printf("Digite a chave para inserir no final: ");
                scanf("%d", &v.chave);
                inserirFinal(&L, v);
                break;

            case 6:
                printf("Digite a chave para inserir de forma ordenada: ");
                scanf("%d", &v.chave);
                inserirOrdenada(&L, v);
                break;

            case 7:
                removerInicio(&L);
                break;

            case 8:
                removerFinal(&L);
                break;

            case 9:
                printf("Digite a chave para remover: ");
                scanf("%d", &chave);
                removerElemento(&L, chave);
                break;
            case 10:
                tamanho(&L);
                break;
            case 11:
                printf("digite a chave: ");
                scanf("%d", &chave);
                buscarLista(&L, chave);
                break;
        }
}while(op !=0);

return 0;
}
