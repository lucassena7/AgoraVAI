/* Desenvolver uma função que, dada uma matriz m15x20, determine se um numero x se encontra na linha L da matriz */

/*Faça uma função que, dada uma matriz M8x5 de reais, gere a matriz Mt, sua transposta*/

//Importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaração de constantes
#define L 15
#define C 20
#define TRUE 1
#define FALSE 0

//Protótipo das funções
int encontrarNumLinha (float matriz [L][C], float num, int linha);
void exibirOriginal (float mOriginal[L][C]);
void preencherMatriz (float matriz[L][C]);

//a segunda dimensão da martriz é sempre obrigatório. É ela quem indica uma quebra de linha na memória.

//Main
void main ()
{
	//Declaração de variáveis
	float matriz [L][C], num;
	int linha;
	
	//Preenchendo a matriz original
	preencherMatriz (matriz);
	
	//exibindo a matriz original
	exibirOriginal (matriz);
	
	printf ("Qual numero deseja buscar ?");
	scanf ("%f", &num);
	
	printf ("Em qual linha deseja buscar o numero ?");
	scanf ("%d", &linha);
	
	//Chamando a função
	if (encontrarNumLinha (matriz, num, linha) == TRUE)
	{
		printf ("O valor %5.1f foi encontrado na linha %d da matriz", num, linha);
	}
	else
	{
		printf ("O valor %5.1f NAO foi encontrado na linha %d da matriz", num, linha);
	}
}

//Implementação das demais funções
int encontrarNumLinha (float matriz [L][C], float num, int linha)
{
	//Declaração de variáveis
	int i, j;
	
	//Corrigindo os valores para o usuário, uma vez que a matriz inicia em 0.
	linha--;
	
	//Varrendo a matriz
	for (i=0; i<L; i++)
	{
		for (j=0; j<C ; j++)
		{
			//Verificando se a linha 'i' é a linha desejada
			if (i == linha)
			{
				//Verificando se o elemento foi encontrado
				if (matriz[i][j] == num)
				{
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}

void exibirOriginal (float mOriginal[L][C])
{
	//Declaração de variáveis
	int i,j;
	
	printf("Elementos da Matriz: \n");
	
	//varrendo as linhas da matriz
	for (i=0; i<L; i++)
	{
		//varrendo as colunas
		for (j=0;j<C;j++)
		{
			printf ("%5.1f", mOriginal[i][j]);
		}
		printf ("\n");
	}
	printf ("\n");
}

void preencherMatriz (float matriz[L][C])
{
		//Declaração de variáveis
	int i,j;
	
	srand (time(NULL));
	
	//varrendo as linhas da matriz
	for (i=0; i<L; i++)
	{
		//varrendo as colunas
		for (j=0;j<C;j++)
		{
			matriz [i][j] = rand()%100;
		}
	}
}
