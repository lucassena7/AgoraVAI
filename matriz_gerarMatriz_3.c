/* Desenvolver uma fun��o que gere a seguinte matriz M5x5 
 	1  2  3  4  5
	2  3  4  5  6
	3  4  5  6  7
	4  5  6  7  8
	5  6  7  8  9 */

/* Desenvolver uma fun��o que, dada uma matriz m15x20, determine se um numero x se encontra na linha L da matriz */

//Importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declara��o de constantes
#define L 5
#define C 5

//Prot�tipo das fun��es
int encontrarNumLinha (float matriz [L][C], float num, int linha);
void exibirOriginal (float mOriginal[L][C]);
void preencherMatriz (float matriz[L][C]);

//a segunda dimens�o da martriz � sempre obrigat�rio. � ela quem indica uma quebra de linha na mem�ria.

//Main
void main ()
{
	//Declara��o de vari�veis
	float matriz [L][C];
	
	//Preenchendo a matriz original
	preencherMatriz (matriz);
	
	//exibindo a matriz original
	exibirOriginal (matriz);
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
	int i,j, cont=0;
	
	//varrendo as linhas da matriz
	for (i=0; i<L; i++)
	{
		cont = i+1;
		
		//varrendo as colunas
		for (j=0;j<C;j++)
		{
			matriz [i][j] = cont;
			cont++;
		}
	}
	
}
