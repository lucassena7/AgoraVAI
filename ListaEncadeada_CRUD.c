/* Listas Encadeadas (listas por ponteiros)

			C	R	U	D
*/

//Importação de bibliotecas
#include <stdio.h>

//Definição de constantes
#define TRUE 1
#define FALSE 0

//Declaração de tipos
//Criamos um nome provisório 'No' para o struct 'TNo', para que possamos manipular o struct.
typedef struct No{
	int valor; //Vale lembrar que é 'int' porque se trata de uma lista de inteiros. Pode ser float, string, struct...
	struct No* prox; //é um ponteiro para um struct, neste caso para um igual ao criado.
}TNo;

typedef TNo* TLista; //TLista é um ponteiro para TNo

// OBS: TLista* L1, L2; -- L1 e L2 são ponteiros para TLista
// OBS: TLista *L1, L2; -- L1 é um ponteiro para TLista e L2 é do tipo TLista.

//Protótipo das funções
int inserir (TLista * L, int numero); //Toda vez que eu mudar o valor de um parâmetro, devo passá-lo por referência e nao por valor.
								      //Para facilitar, criamos a variável 'TLista'. Poderia ser também (TNo** L, int numero);
int removerTodasOcorrencias (TNo* L, int numero);
alterarTodasOcorrencias (TNo* L, int numAntigo, int numNovo);
buscar
exibir

//Main
void main  ()
{
	//Declaração de variáveis
	TNo * lista = NULL; //lista é um ponteiro para o struct. Ela armazena o endereço do primeiro nó. 
}
