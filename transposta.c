/*	Lista de Exercícios VI (Matrizes):
	
	Faça uma função que, dada uma matriz M8×5 de reais, gere a matriz Mt, sua transposta. */

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definição de constantes
#define L 8
#define C 5

//declaração de protótipos
void transposta (float m[L][C], float maTransposta[C][L]);

void exibir (float m[L][C]);
void exibirTransposta (float m[C][L]);
void preencherMatriz (float m[L][C]);

//main
void main ()
{
	//declaração de variáveis
	float matriz[L][C], maTransposta [C][L];
	
	//preenchendo a matriz original
	preencherMatriz (matriz);
	
	//Chamando a função transposta
	transposta (matriz, maTransposta);
	
	//exibindo a matriz original
	exibir (matriz);
	
	//exibindo a matriz transposta
	exibirTransposta (maTransposta);
}

//implementação das funções
void transposta (float m[L][C], float maTransposta[C][L])
{
	//Declaração de variáveis
	int i, j;
	
	//varrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//varrendo as colunas
		for (j=0;j<C;j++)
		{
			 maTransposta [j][i] = m[i][j];
		}
	}
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

void exibirTransposta (float m[C][L])
{
	//declaração de variáveis
	int i, j;
	
	printf ("\nElementos da matriz:\n\n");
	
	//varrendo as linhas da matriz
	for (i=0;i<C;i++)
	{
		//varrendo as colunas
		for (j=0;j<L;j++)
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
