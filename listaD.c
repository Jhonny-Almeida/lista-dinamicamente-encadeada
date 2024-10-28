
#include <stdio.h>
#include <stdlib.h>
#include "listaD.h"

void definir(Lista *L)
{
	L->head = NULL;
}

void destruir(Lista *L)
{
	No *p;
	while (L->head != NULL)
	{
		p = L->head;
		L->head = (L->head)->prox;
		free(p);
	}
}

int inserirInicio(Lista *L, tipo_elem v)
{
	No *p = (No *)malloc(sizeof(No));
	if (p == NULL)
		return 0;
	p->info = v;
	p->prox = L->head;
	L->head = p;
	return 1;
}

int inserirFinal(Lista *L, tipo_elem v)
{
	No *p, *k;
	if (vazia(L))
		return (inserirInicio(L, v));

	for (p = L->head; p->prox != NULL; p = p->prox)
		;
	{
		k = (No *)malloc(sizeof(No));

		if (k == NULL)
			return 0;
	}

	k->info = v;
	k->prox = NULL;
	p->prox = k;
	return 1;
}

int inserirOrdenada(Lista *L, tipo_elem v)
{
	No *q, *p, *k;
	if (vazia(L))
		return (inserirInicio(L, v));
	for (q = NULL, p = L->head; p != NULL && v.chave > p->info.chave; q = p, p = p->prox)
		;

	if (q == NULL)
		return (inserirInicio(L, v));

	k = (No *)malloc(sizeof(No));
	if (k == NULL)
		return 0;
	k->info = v;
	k->prox = p;
	q->prox = k;
	return 0;
}

int removerInicio(Lista *L)
{
	No *p;

	if (vazia(L))
		return 0;

	p = L->head;
	L->head = p->prox;
	free(p);
	return 1;
}

int removerFinal(Lista *L)
{
	No *p, *q;

	if (vazia(L))
		return 0;

	for (q = NULL, p = L->head; p->prox != NULL; q = p, p = p->prox)
		;
	free(p);
	if (p == NULL)
		L->head = NULL;
	else
		q->prox = NULL;
	return 1;
}
int removerElemento(Lista *L, int chave)
{
	if (vazia(L))
		return 0;
	No *p, *q;
	for (q = NULL, p = L->head; p->prox != NULL && chave != p->info.chave; p = p->prox, q = p)
		;

	if (p == NULL)
		return 0;

	if (q == NULL)
		L->head = p->prox;
	else
		q->prox = p->prox;
	free(p);

	return 1;
}

int buscarLista(Lista *L, int chave);

void exibir(Lista *L)
{
	No *p = L->head;
	while (p != NULL)
	{
		printf("%d", p->info.chave);
		p = p->prox;
	}
}

/*int Tamanho_rec (No *p){
	if(p==NULL)
		return 0:
}

int Tamanho(Lista *L){
	return(tamanho_rec(L->head));
}
*/
int tamanho(Lista *L)
{
	int cont;
	No *p;
	for (cont = 0, p = L->head; p != NULL; p = p->prox, cont++)
		; // recurcivo
	return cont;
}

int vazia(Lista *L)
{
	return (L->head == NULL);
}

int buscarLista(Lista *L, int chave)
{
	No *p;
	for (p = L->head; p != NULL && p->info.chave != chave; p = p->prox)
		;

	if (p == NULL)
		return 0;
	return 1;
}

int verifOrdenada(Lista *L)
{
	//No *p;

	if (vazia(L) || L->head->prox == NULL)
		return 1;

	No *p = L->head;

	while (p->prox != NULL)
	{

		if (p->info.chave > p->prox->info.chave)
			return 0;
		p = p->prox;
	}

	return 1;
}

int copiarLista(Lista *L, Lista *destino) {
    // Inicializa a lista destino como vazia
    definir(destino);

    // Verifica se a lista de origem está vazia
    if (vazia(L)) {
        return 1;  // Lista de origem vazia, nada a copiar
    }

    No *p = L->head;  // Ponteiro para percorrer a lista original
    tipo_elem elem;         // Elemento temporário para armazenar a chave

    // Percorre a lista de origem e insere cada elemento na lista destino
    while (p != NULL) {
        elem.chave = p->info.chave;  // Copia a chave do nó atual
        if (!inserirFinal(destino, elem)) {
            return 0;  // Erro ao alocar memória ou inserir
        }
        p = p->prox;  // Avança para o próximo nó
    }
    return 1;  // Copia bem-sucedida
}

int copiarListaUnica(Lista *L, Lista *destino) {
    definir(destino);  // Inicializa a lista destino como vazia

    if (vazia(L)) {
        return 1;  // Lista de origem vazia
    }

    No *p = L->head;
    tipo_elem elem;

    while (p != NULL) {
        elem.chave = p->info.chave;

        // Insere apenas se o elemento não estiver na lista destino
        if (!buscarLista(destino, elem.chave)) {
            if (!inserirFinal(destino, elem)) {
                return 0;  // Erro ao alocar memória
            }
        }
        p = p->prox;
    }
    return 1;  // Copia bem-sucedida
}

void pausar() { // nao aguento mais
    printf("\nPressione Enter para continuar...");
    getchar();  // Lê o caractere '\n' deixado pelo scanf
    getchar();  // Espera o usuário pressionar Enter
}

void limparTela() {
#ifdef _WIN32
    system("cls");  // Comando para Windows
#else
    system("clear");  // Comando para Linux/Mac
#endif
}