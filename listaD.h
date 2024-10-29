
//tipo do dado
typedef struct{
	
	int chave;
	
}tipo_elem;

typedef struct No
{
    tipo_elem info;
    struct No *prox;
}No;

//lista estatica essencial

typedef struct {
	
   No *head;
   
}Lista;

// estrutura de lista criada para questão F

typedef struct {
    int chave;
    int count;
} tipo_elem_freq;

typedef struct NoFreq {
    tipo_elem_freq info;
    struct NoFreq *prox;
} NoFreq;

typedef struct {
    NoFreq *head;
} ListaFreq;




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

int verifOrdenada(Lista *L);
int copiarLista(Lista *L, Lista *lista2);
int copiarListaUnica(Lista *L, Lista *lista2);

void pausar();
void limparTela();
int gerarListaDeFrequencia(Lista *L1, ListaFreq *L2);
int inserirFinalFreq(ListaFreq *L, tipo_elem_freq v);
void exibirListaFrequencia(ListaFreq *L2);
void destruirListaFreq(ListaFreq *L);
void separarParesImpares(Lista *L, Lista *par, Lista *impar);