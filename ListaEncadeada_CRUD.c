/* Listas Encadeadas (listas por ponteiros)

			C	R	U	D
*/

//Importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Definição de constantes
#define TRUE 1
#define FALSE 0

//Declaração de tipos
//Criamos um nome provisório 'No' para o struct 'TNo', para que possamos manipular o struct.
typedef struct No{
	int valor; //Vale lembrar que é 'int' porque se trata de uma lista de inteiros. Pode ser float, string, struct...
	struct No* prox; //? um ponteiro para um struct, neste caso para um igual ao criado.
}TNo;

typedef TNo* TLista; //TLista é um ponteiro para TNo

// OBS: TLista* L1, L2; -- L1 e L2 são ponteiros para TLista
// OBS: TLista *L1, L2; -- L1 é um ponteiro para TLista e L2 é do tipo TLista.

//Protótipo das funções
int inserir (TLista * L, int numero); //Toda vez que eu mudar o valor de um parâmetro, devo passá-lo por referência e nao por valor.
								      //Para facilitar, criamos a variável 'TLista'. Poderia ser também (TNo** L, int numero);
int removerTodasOcorrencias (TLista* L, int numero);
int alterarTodasOcorrencias (TLista L, int numAntigo, int numNovo); //Não precisamos colocar o ponteiro '*' pois o endereço não é alterado, e sim o conteúdo.
int buscar (TLista L, int numero); //Não precisamos colocar o ponteiro '*' pois só iremos percorrer a lista. Não iremos alterá-la.
void exibir (TLista L); //Não precisamos colocar o ponteiro pois só iremos percorrer a lista

//Main
void main  ()
{
	//Declaração de variáveis
	TNo * lista = NULL; //lista é um ponteiro para o struct. Ela armazena o endereço do primeiro nó. 
}

int inserir (TLista * L, int numero)
{
	//Declaração de variáveis
	TLista aux;
	
	//Passo 1: alocar memória
	aux = (TLista) malloc (sizeof(TNo)); //malloc: argumento -> quantos bytes vc quer ? (retorna *void)
																				//void = indeterminado
										
										//Tivemos q fazer um casting (TLista). Convertemos *void para TLista
	
	//Verificando se a memória foi alocada
	if (aux == NULL)
	{
		return FALSE;
	}
	else
	{
		//Passo 2: armazenando 'numero' na posição alocada
		aux->valor = numero;
		
		//Passo 3: fazendo o novo nó aontar para aquele que até então era o primeiro nó da lista
		aux->prox = *L;
		
		//Passo 4: fazer com que a lista aponte para o novo elemento (uma vez que está sendo inserido no inicio da lista
		*L = aux;
		
		return TRUE;
	} 
}

int removerTodasOcorrencias (TLista* L, int numero)
{
	//Declaração de variáveis
	
	
}

int alterarTodasOcorrencias (TLista L, int numAntigo, int numNovo)
{
	//Declaração de variáveis
	TLista aux = L; //Fazendo 'aux' que é um ponteiro para TNo apontar para o primeiro nó da lista
	int cont = 0;
	//int alterou = FALSE;
	
	while (aux != NULL) //Enquanto aux for diferente de NULL
	{
		if ( aux->valor == numAntigo) //Verificando se o número buscado é igual ao elemento apontado por aux
		{
			aux->valor = numNovo; //alterando o valor apontado por aux
			cont++; //Um contador foi criado a fim de saber quantas alterações foram feitas
			//alterou = TRUE;
		}
			
		//Atualizando o valor de aux
		aux = aux->prox; 
	}
	return cont;
	//return alterou;
}

int buscar (TLista L, int numero)
{
	//Declaração de variáveis
	TLista aux = L; //Fazendo 'aux' que é um ponteiro para TNo apontar para o primeiro nó da lista
	
	while (aux != NULL) //Enquanto aux for diferente de NULL
		{
			if ( aux->valor == numero) //Verificando se o número buscado é igual ao elemento apontado por aux
			{
				return TRUE; //Retornando TRUE caso o valor esteja na lista.
			}
			
			//Atualizando o valor de aux
			aux = aux->prox; 
		}
		
	return FALSE; //Se chegou aqui é pq o valor não foi encontrado na lista.
}

void exibir (TLista L)
{
	//Declaração de variáveis
	TLista aux = L; //Fazendo 'aux' que é um ponteiro para TNo apontar para o primeiro nó da lista
	
	if (L == NULL) //Testando se a a lista está vazia
	{
		printf ("Lista Vazia !.");
	}
	
	else
	{
		printf ("Lista: ");
		
		while (aux != NULL) //Enquanto aux for diferente de NULL
		{
			//Printando o valor da lista
			printf ("%d", aux->valor); //printa o que é apontado por aux
									//pode ser ("%d", (*aux).valor));
		
			//Atualizando o valor de aux
			aux = aux->prox; 
		}	
	}
}
