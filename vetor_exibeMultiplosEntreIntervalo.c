/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna
	Data: 22/08/2021
	
	Revisão - FAC   
	Desenvolver uma função que exiba os múltiplos de N compreendidos no intervalo definido por A e B.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes

//protótipos/cabeçalhos das funções
void multiplos (int numA, int numB, int N);

//implementação da função main
void main ()
{
	//Declaração de variáveis
	int numA, numB, N, resposta;
	
	//Obtendo os dados do usuário
	printf ("\t Entre com o primeiro numero da sequencia: ");
	scanf ("%d", &numA);
	
	printf ("\t Entre com o segundo numero da sequencia: ");
	scanf ("%d", &numB);
	
	printf ("\t Entre com o numero que se deseja saber o multiplo: ");
	scanf ("%d", &N);
	
	printf ("\n\t Numeros multiplos de %d: ", N);
	multiplos (numA, numB, N);
}

//implementação das demais funções
void multiplos (int numA, int numB, int N)
{
	//Declaração de variáveis
	int i;
	
	for (i=numA; i<=numB; i++)
	{
		if (i%N == 0)
		{
			printf ("%d ", i);
		}
	}
}
