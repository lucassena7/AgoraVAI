/* Desenvolver uma função que, dado um vetor com quant números inteiros, crie uma lista encadeada L, do tipo TLista,
contendo os números do vetor ordenados crescentemente e sem repetição.

Nota: os elementos do vetor devem ser transferidos diretamente para a lista; ou seja, nenhuma estrutura auxiliar 
deve ser utilizada, assim como os elementos originais do vetor devem ser preservados. */

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TAM 7
#define TRUE 1
#define FALSE 0

//Declaração de tipos
//Criamos um nome provisório 'No' para o struct 'TNo', para que possamos manipular o struct.
typedef struct No{
	int valor; //Vale lembrar que é 'int' porque se trata de uma lista de inteiros. Pode ser float, string, struct...
	struct No* prox; //? um ponteiro para um struct, neste caso para um igual ao criado.
}TNo;

typedef TNo* TLista; //TLista é um ponteiro para TNo

//protótipos/cabeçalhos das funções
void exibirVetor (int vetor[], int tamanho);
int preencherLista (int vetor[], int tamanho, TLista * L);
void exibirLista (TLista L); //Não precisamos colocar o ponteiro pois só iremos percorrer a lista

//main
void main ()
{
	//declaração de variáveis
	int v[TAM] = {5, 4, 8, 3, 2, 1, 1};
	TLista L = NULL;
	
	exibirVetor (v, TAM);
	
	if (preencherLista (v, TAM, &L) == FALSE)
	{
		printf("Houve erro na alocacao de memoria !");
	}
	else
	{
		exibirLista(L);
	}
}

//Implementação das demais funções
void exibirVetor (int vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	printf ("\n\nVetor: ");
	
	//variando todas as posições do vetor
	for (i=0;i<tamanho;i++)
	{
		//exibindo os valores do vetor
		printf ("%d ", vetor[i]);
	}
	
	printf ("\n");
}

int preencherLista (int vetor[], int tamanho, TLista * L)
{
	//Declaração de variáveis
	int i;
	TLista aux;
	
	//variando todas as posições do vetor
	//Enquanto i<tamanho
	//while (i)
	for (i=0;i<tamanho;)
	{
		//verificando se o elemento existe na lista
		if (buscar (*L, vetor[i]) == TRUE)
		{
			i++;
		}
		else //Se o elemento nao existir na lista
		{
			//1º passo: alocar memória para o novo nó	
			aux = (TLista) malloc (sizeof(TNo));
		
			//verificando se houve erro na alocação de memória
			if (aux == NULL)
			{
				return FALSE;
			}
			else
			{
				//2º passo: armazenar 'numero' na memória recém-alocada
				aux->valor = vetor[i];
			
				//3º passo: mandar o campo 'prox' do novo nó apontar para o 
				//"até então" primeiro elemento	da lista
				aux->prox = *L;
			
				//4º passo: fazer com que L aponte para o novo nó da lista		
				*L = aux;
				
				i++;
			}
		}
	}
	return TRUE;
}

int buscar (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux = L;
	
	//percorrendo a lista até o seu final
	while (aux != NULL)
	{
		//testando se é o valor sendo buscado
		if (aux->valor == numero)
		{
			return TRUE;
		}
			
		//atualizando o 'aux' para apontar para o próximo nó
		aux = aux->prox;
	}
	
	//se chegou a este ponto, o número buscado não existe
	return FALSE;	
}

void exibirLista (TLista L)
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
