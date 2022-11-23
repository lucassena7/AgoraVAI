/* Desenvolver uma fun��o que, dado um vetor com quant n�meros inteiros, crie uma lista encadeada L, do tipo TLista,
contendo os n�meros do vetor ordenados crescentemente e sem repeti��o.

Nota: os elementos do vetor devem ser transferidos diretamente para a lista; ou seja, nenhuma estrutura auxiliar 
deve ser utilizada, assim como os elementos originais do vetor devem ser preservados. */

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//defini��o de constantes
#define TAM 6
#define TRUE 1
#define FALSE 0

//Declara��o de tipos
//Criamos um nome provis�rio 'No' para o struct 'TNo', para que possamos manipular o struct.
typedef struct No{
	int valor; //Vale lembrar que � 'int' porque se trata de uma lista de inteiros. Pode ser float, string, struct...
	struct No* prox; //? um ponteiro para um struct, neste caso para um igual ao criado.
}TNo;

typedef TNo* TLista; //TLista � um ponteiro para TNo

//prot�tipos/cabe�alhos das fun��es
void exibir (int vetor[], int tamanho);
int preencherLista (int vetor[], int tamanho, TLista * L);

//main
void main ()
{
	//declara��o de vari�veis
	int v[TAM] = {5, 4, 4, 3, 2, 1, 1};
	
	exibir (v, TAM);
	
	
}

//Implementa��o das demais fun��es
void exibir (int vetor[], int tamanho)
{
	//declara��o de vari�veis
	int i;
	
	printf ("\n\nVetor: ");
	
	//variando todas as posi��es do vetor
	for (i=0;i<tamanho;i++)
	{
		//exibindo os valores do vetor
		printf ("%d ", vetor[i]);
	}
	
	printf ("\n");
}

int preencherLista (int vetor[], int tamanho, TLista * L)
{
	//Declara��o de vari�veis
	int i;
	TLista aux;
	
	//variando todas as posi��es do vetor
	for (i=0;i<tamanho;i++)
	{
		//verificando se o elemento n�o existe na lista
		if (buscar (*L, vetor[i]) == FALSE)
		{	
			//1� passo: alocar mem�ria para o novo n�	
			aux = (TLista) malloc (sizeof(TNo));
		
			//verificando se houve erro na aloca��o de mem�ria
			if (aux == NULL)
			{
				return FALSE;
			}
			else
			{
				//2� passo: armazenar 'numero' na mem�ria rec�m-alocada
				aux->valor = vetor[i];
			
				//3� passo: mandar o campo 'prox' do novo n� apontar para o 
				//"at� ent�o" primeiro elemento	da lista
				aux->prox = *L;
			
				//4� passo: fazer com que L aponte para o novo n� da lista		
				*L = aux;
			}
		}
		else
		{
			i++;
		}
		return TRUE;
	}
	
}

int buscar (TLista L, int numero)
{
	//declara��o de vari�veis
	TLista aux = L;
	
	//percorrendo a lista at� o seu final
	while (aux != NULL)
	{
		//testando se � o valor sendo buscado
		if (aux->valor == numero)
		{
			return TRUE;
		}
			
		//atualizando o 'aux' para apontar para o pr�ximo n�
		aux = aux->prox;
	}
	
	//se chegou a este ponto, o n�mero buscado n�o existe
	return FALSE;	
}
