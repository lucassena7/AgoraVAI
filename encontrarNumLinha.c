/* Desenvolver uma fun��o que, dada uma matriz m15x20, determine se um numero x se encontra na linha L da matriz */

/*Fa�a uma fun��o que, dada uma matriz M8x5 de reais, gere a matriz Mt, sua transposta*/

//Importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declara��o de constantes
#define L 15
#define C 20
#define TRUE 1
#define FALSE 0

//Prot�tipo das fun��es
int encontrarNumLinha (float matriz [L][C], float num, int linha);
void exibirOriginal (float mOriginal[L][C]);
void preencherMatriz (float matriz[L][C]);

//a segunda dimens�o da martriz � sempre obrigat�rio. � ela quem indica uma quebra de linha na mem�ria.

//Main
void main ()
{
	//Declara��o de vari�veis
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
	
	//Chamando a fun��o
	if (encontrarNumLinha (matriz, num, linha) == TRUE)
	{
		printf ("O valor %5.1f foi encontrado na linha %d da matriz", num, linha);
	}
	else
	{
		printf ("O valor %5.1f NAO foi encontrado na linha %d da matriz", num, linha);
	}
}

//Implementa��o das demais fun��es
int encontrarNumLinha (float matriz [L][C], float num, int linha)
{
	//Declara��o de vari�veis
	int i, j;
	
	//Corrigindo os valores para o usu�rio, uma vez que a matriz inicia em 0.
	linha--;
	
	//Varrendo a matriz
	for (i=0; i<L; i++)
	{
		for (j=0; j<C ; j++)
		{
			//Verificando se a linha 'i' � a linha desejada
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
	//Declara��o de vari�veis
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
		//Declara��o de vari�veis
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
