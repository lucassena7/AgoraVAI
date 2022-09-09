/* Desenvolver uma fun��o que, dada uma matriz M15�20, determine se um n�mero X se encontra na linha L da matriz. */

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//defini��o de constantes
#define L 15
#define C 20

#define TRUE 1
#define FALSE 0

//declara��o de prot�tipos
int buscarElementoLinha (float m[L][C], float num, int linha);

void exibir (float m[L][C]);
void preencherMatriz (float m[L][C]);

//main
void main ()
{
	//declara��o de vari�veis
	float matriz[L][C];
	float numero;
	int linha;
	
	//preenchendo a matriz original
	preencherMatriz (matriz);
	
	//exibindo a matriz original
	exibir (matriz);
	
	//Coletando os dados do usu�rio
	printf("Entre com o numero a ser buscado: ");
	scanf ("%f", &numero);
	
	printf("Entre com o a linha desejada: ");
	scanf ("%d", &linha);
	
	//chamando a fun��o buscar
	if (buscarElementoLinha (matriz, numero, linha) == TRUE)
	{
		printf ("O elemendo %.1f esta presenta na linha %d da matriz", numero, linha);
	}
	else
	{
		printf ("O elemendo %.1f NAO esta presenta na linha %d da matriz", numero, linha);
	}
}

//implementa��o das fun��es
int buscarElementoLinha (float m[L][C], float num, int linha)
{
	//Declara��o de vari�veis
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
	//declara��o de vari�veis
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
	//declara��o de vari�veis
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
