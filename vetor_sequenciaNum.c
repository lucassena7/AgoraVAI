/* 
		FPR - Fundamentos de Programação
			Professor Leonardo Vianna
			Data: 24/08/2022

		Implementar uma função que, dado um número inteiro N, exiba uma sequência de números como as 
		ilustradas nos exemplos a seguir:
		
		Exemplo 1: N = 3
				
			(1 2) (1 3) (2 1) (2 3) (3 1) (3 2)

		Exemplo 2: N = 5
			(1 2) (1 3) (1 4) (1 5) (2 1) (2 3) (2 4) (2 5) (3 1)
			(3 2) (3 4) (3 5) (4 1) (4 2) (4 3) (4 5) (5 1) (5 2) (5 3) (5 4) */
			
//importação de bibliotecas
#include <stdio.h>

//definição de constantes

//protótipos/cabeçalhos das funções
void funcao (int num);

//implementação da função main
void main ()
{
	//Declaração de variáveis
	int num;
	
	//Coletando os dados do usuário
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
	//Declaração de variáveis
	int i, j;
	
	for (i=1; i<num; i++)
	{
		for (j=2; j<=num; j++)
		{
			printf ("%d %d", i, j);
		}
	}
}

