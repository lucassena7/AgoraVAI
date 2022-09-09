/* Desenvolver uma função que, dada uma matriz M15×20, determine se um número X se encontra na linha L da matriz. */

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definição de constantes
#define L 15
#define C 20

#define TRUE 1
#define FALSE 0

//declaração de protótipos
int buscarElementoLinha (float m[L][C], float num, int linha);

void exibir (float m[L][C]);
void preencherMatriz (float m[L][C]);

//main
void main ()
{
	//declaração de variáveis
	float matriz[L][C];
	float numero;
	int linha;
	
	//preenchendo a matriz original
	preencherMatriz (matriz);
	
	//exibindo a matriz original
	exibir (matriz);
	
	//Coletando os dados do usuário
	printf("Entre com o numero a ser buscado: ");
	scanf ("%f", &numero);
	
	printf("Entre com o a linha desejada: ");
	scanf ("%d", &linha);
	
	//chamando a função buscar
	if (buscarElementoLinha (matriz, numero, linha) == TRUE)
	{
		printf ("O elemendo %.1f esta presenta na linha %d da matriz", numero, linha);
	}
	else
	{
		printf ("O elemendo %.1f NAO esta presenta na linha %d da matriz", numero, linha);
	}
}

//implementação das funções
int buscarElementoLinha (float m[L][C], float num, int linha)
{
	//Declaração de variáveis
	int i, j;
	
	//varrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//varrendo as colunas
		for (j=0;j<C;j++)
		{
			if (i == linha)
			{
				if (m[i][j] == num)
				{
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}

void exibir (float m[L][C])
{
	//declaração de variáveis
	int i, j;
	
	printf ("\nElementos da matriz:\n\n");
	
	//varrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//varrendo as colunas
		for (j=0;j<C;j++)
		{
			printf ("%5.1f ", m[i][j]);
		}
		
		printf ("\n");
	}
	
	printf ("\n\n");
}

void preencherMatriz (float m[L][C])
{
	//declaração de variáveis
	int i, j;
	
	srand (time(NULL));
	
	//varrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//varrendo as colunas
		for (j=0;j<C;j++)
		{
			m[i][j] = rand () % 100;
		}
	}
}
