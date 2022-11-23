/* 							Atividade 5
Desenvolver uma função que, dado um arquivo com números inteiros, um por linha, crie uma lista encadeada L 
com aseguinte característica:

Cada nó de L terá os seguintes campos: valor (cada número distinto existente no arquivo), quantidade
(quantas vezes o número armazenado no campo valor encontra-se no arquivo), prox (endereço do próximo
nó da lista).

Para exemplificar, considerem o seguinte arquivo:

5
1
4
4
1
5
2
3
5
2
3
4
1

Como o arquivo possui 5 elementos distintos, a lista L, neste exemplo, terá 5 nós (não necessariamente nesta ordem):

1. Nó com 5 no campo valor e 3 no campo quantidade (uma vez que o valor 5 aparece 3 vezes no arquivo);

2. Nó com 1 no campo valor e 3 no campo quantidade (uma vez que o valor 1 aparece 3 vezes no arquivo);

3. Nó com 4 no campo valor e 3 no campo quantidade (uma vez que o valor 4 aparece 3 vezes no arquivo);

4. Nó com 2 no campo valor e 2 no campo quantidade (uma vez que o valor 2 aparece 2 vezes no arquivo);

5. Nó com 3 no campo valor e 2 no campo quantidade (uma vez que o valor 3 aparece 2 vezes no arquivo);
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
	int quantidade;
	struct No* prox; //? um ponteiro para um struct, neste caso para um igual ao criado.
}TNo;

typedef TNo* TLista; //TLista é um ponteiro para TNo

//Protótipo das funções
int preencherLista (char nomeArq[], TLista * L);

//Main
void main  ()
{
	
}

//Implementação das demais funções
int preencherLista (char nomeArq[], TLista * L)
{
	//declaração de variáveis
	FILE *arq;
	TLista aux;
	int valor;
	
	//abrindo os arquivos
	arq = fopen (nomeArq, "r");
	
	//verificando se houve erro na abertura do arquivo
	if (!arq)
	{
		fclose (arq);
		
		return -1;
	}
	else
	{
		//lendo os elementos do arquivo original
		while (fscanf (arq, "%d", &valor) != EOF)
		{
			if (buscar(*L, valor) == FALSE) //Verificando se a lista está vazia ou o número a ser inserido não se encontra na lista
			{
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
					aux->valor = valor;
		
					//Passo 3: fazendo o novo nó aontar para aquele que até então era o primeiro nó da lista
					aux->prox = *L;
		
					//Passo 4: fazer com que a lista aponte para o novo elemento (uma vez que está sendo inserido no inicio da lista
					*L = aux;
				}
			}
			else
			//Como Ler o próximo caracter ??
			{
				
			}
			
		}
	}
}

int buscar (TLista L, int numero)
{
	//Declaração de variáveis
	TLista aux = L; //Fazendo 'aux' que é um ponteiro para TNo apontar para o primeiro nó da lista
	
	if (aux == NULL) //verificando se a lista está vazia
	{
		return FALSE; //Retornando FALSE uma vez que não há elementos na lista.
	}
	else //a lista não está vazia
	{
		while (aux != NULL) //Enquanto aux for diferente de NULL
		{
			if ( aux->valor == numero) //Verificando se o número buscado é igual ao elemento apontado por aux
			{
				return TRUE; //Retornando TRUE caso o valor esteja na lista.
			}
			//Atualizando o valor de aux
			aux = aux->prox; 
		}
	}
	return FALSE; //Se chegou aqui é pq o valor não foi encontrado na lista.
}

