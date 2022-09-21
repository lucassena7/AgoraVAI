/*Fa�a uma fun��o que, dada uma matriz M8x5 de reais, gere a matriz Mt, sua transposta*/

//Importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declara��o de constantes
#define L 8
#define C 5

//Prot�tipo das fun��es
void transposta (float mOriginal[L][C], float mTransposta[C][L]);
void exibirOriginal (float mOriginal[L][C]);
void exibirTransposta (float mTransposta[C][L]);
void preencherMatriz (float matriz[L][C]);

//a segunda dimens�o da martriz � sempre obrigat�rio. � ela quem indica uma quebra de linha na mem�ria.

//Main
void main ()
{
	//Declara��o de vari�veis
	float matriz [L][C], Matransposta [C][L];
	
	//Preenchendo a matriz original
	preencherMatriz (matriz);
	
	//exibindo a matriz original
	exibirOriginal (matriz);
	
	//Chamando a fun��o transposta
	transposta (matriz, Matransposta);
	
	//Exibindo a matriz transposta
	exibirTransposta (Matransposta);
}

//Implementa��o das demais fun��es
void transposta (float mOriginal[L][C], float mTransposta[C][L])
{
	//Declara��o de vari�veis
	int i, j;
	
	for(i=0; i<L;i++)
	{
		for (j=0; j<C;j++)
		{
			mTransposta [j][i] = mOriginal [i][j];
		}
	}
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
	
void exibirTransposta (float mTransposta[C][L])
{
	//Declara��o de vari�veis
	int i,j;
	
	printf("Elementos da Matriz: \n");
	
	//varrendo as linhas da matriz
	for (i=0; i<C; i++)
	{
		//varrendo as colunas
		for (j=0;j<L;j++)
		{
			printf ("%5.1f", mTransposta[i][j]);
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
