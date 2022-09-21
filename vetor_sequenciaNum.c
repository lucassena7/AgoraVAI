/* 
		FPR - Fundamentos de Programa��o
			Professor Leonardo Vianna
			Data: 24/08/2022

		Implementar uma fun��o que, dado um n�mero inteiro N, exiba uma sequ�ncia de n�meros como as 
		ilustradas nos exemplos a seguir:
		
		Exemplo 1: N = 3
				
			(1 2) (1 3) (2 1) (2 3) (3 1) (3 2)

		Exemplo 2: N = 5
			(1 2) (1 3) (1 4) (1 5) (2 1) (2 3) (2 4) (2 5) (3 1)
			(3 2) (3 4) (3 5) (4 1) (4 2) (4 3) (4 5) (5 1) (5 2) (5 3) (5 4) */
			
//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes

//prot�tipos/cabe�alhos das fun��es
void funcao (int num);

//implementa��o da fun��o main
void main ()
{
	//Declara��o de vari�veis
	int num;
	
	//Coletando os dados do usu�rio
	printf ("Entre com o numero: ");
	scanf("%d", &num);

	funcao (num);
}

/*Exemplo 1: N = 3
				
			(1 2) (1 3) (2 1) (2 3) (3 1) (3 2)

		Exemplo 2: N = 5
			(1 2) (1 3) (1 4) (1 5) (2 1) (2 3) (2 4) (2 5) (3 1)
			(3 2) (3 4) (3 5) (4 1) (4 2) (4 3) (4 5) (5 1) (5 2) (5 3) (5 4) */
			
void funcao (int num)
{
	//Declara��o de vari�veis
	int i, j;
	
	for (i=1; i<num; i++)
	{
		for (j=2; j<=num; j++)
		{
			printf ("%d %d", i, j);
		}
	}
}

