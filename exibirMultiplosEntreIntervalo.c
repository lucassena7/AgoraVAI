/*
	FPR - Fundamentos de Programa��o
	Professor Leonardo Vianna
	Data: 22/08/2021
	
	Revis�o - FAC   
	Desenvolver uma fun��o que exiba os m�ltiplos de N compreendidos no intervalo definido por A e B.
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes

//prot�tipos/cabe�alhos das fun��es
void multiplos (int numA, int numB, int N);

//implementa��o da fun��o main
void main ()
{
	//Declara��o de vari�veis
	int numA, numB, N, resposta;
	
	//Obtendo os dados do usu�rio
	printf ("\t Entre com o primeiro numero da sequencia: ");
	scanf ("%d", &numA);
	
	printf ("\t Entre com o segundo numero da sequencia: ");
	scanf ("%d", &numB);
	
	printf ("\t Entre com o numero que se deseja saber o multiplo: ");
	scanf ("%d", &N);
	
	printf ("\n\t Numeros multiplos de %d: ", N);
	multiplos (numA, numB, N);
}

//implementa��o das demais fun��es
void multiplos (int numA, int numB, int N)
{
	//Declara��o de vari�veis
	int i;
	
	for (i=numA; i<=numB; i++)
	{
		if (i%N == 0)
		{
			printf ("%d ", i);
		}
	}
}
