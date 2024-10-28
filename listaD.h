
//tipo do dado
typedef struct{
	
	int chave;
	
}tipo_elem;

typedef struct
{
    tipo_elem info;
    struct No *prox;
}No;

//lista estatica essencial

typedef struct {
	
   No *head;
   
}Lista;




//operacoes

void definir(Lista *L);
void destruir(Lista *L);
int inserirInicio(Lista *L, tipo_elem v);
int inserirFinal(Lista *L, tipo_elem v);
int inserirOrdenada(Lista *L , tipo_elem v);
int removerInicio(Lista *L);
int removerFinal(Lista*L);
int removerElemento(Lista *L, int chave);
int buscarLista(Lista*L, int chave);
void exibir(Lista *L);
int tamanho(Lista*L);

int vazia(Lista*L);
int Busca_Bi(Lista *L, int chave);
int busc_seq_ord(Lista *L, int chave);

void verfOrdenada(Lista *L);

