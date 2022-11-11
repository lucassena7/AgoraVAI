/* Listas Encadeadas (listas por ponteiros)

			C	R	U	D
*/

//Importa��o de bibliotecas
#include <stdio.h>

//Defini��o de constantes
#define TRUE 1
#define FALSE 0

//Declara��o de tipos
//Criamos um nome provis�rio 'No' para o struct 'TNo', para que possamos manipular o struct.
typedef struct No{
	int valor; //Vale lembrar que � 'int' porque se trata de uma lista de inteiros. Pode ser float, string, struct...
	struct No* prox; //� um ponteiro para um struct, neste caso para um igual ao criado.
}TNo;

typedef TNo* TLista; //TLista � um ponteiro para TNo

// OBS: TLista* L1, L2; -- L1 e L2 s�o ponteiros para TLista
// OBS: TLista *L1, L2; -- L1 � um ponteiro para TLista e L2 � do tipo TLista.

//Prot�tipo das fun��es
int inserir (TLista * L, int numero); //Toda vez que eu mudar o valor de um par�metro, devo pass�-lo por refer�ncia e nao por valor.
								      //Para facilitar, criamos a vari�vel 'TLista'. Poderia ser tamb�m (TNo** L, int numero);
int removerTodasOcorrencias (TNo* L, int numero);
alterarTodasOcorrencias (TNo* L, int numAntigo, int numNovo);
buscar
exibir

//Main
void main  ()
{
	//Declara��o de vari�veis
	TNo * lista = NULL; //lista � um ponteiro para o struct. Ela armazena o endere�o do primeiro n�. 
}
