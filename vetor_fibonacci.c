/*
	FPR - Fundamentos de Programa��o
	Professor Leonardo Vianna
	Data: 22/08/2021
	
	Revis�o - FAC   
	Desenvolver uma fun��o que calcule o n-�simo termo da sequ�ncia de Fibonacci.
	
		1  1  2  3  5  8  13  21  ...
					a  b  c
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes

//prot�tipos/cabe�alhos das fun��es
int fibonacci (int num);

//implementa��o da fun��o main
void main ()
{
	//Declara��o de vari�veis
	int num, resposta;
	
	//Obtendo os dados do usu�rio
	printf ("\t Entre com o 'n-esimo' termo da sequencia de fibonacci ");
	scanf ("%d", &num);
	
	resposta = fibonacci (num);
	
	printf ("\tO %d termo da sequencia de fibonacci e: %d", num, resposta);
}

//implementa��o das demais fun��es
int fibonacci (int num)
{
	//Declara��o de vari�veis
	int a, b, c, i;
	
	//Se 'num' for igual ao primeiro ou segundo termo da sequ�ncia, ser� igual a 1
	if ((num == 1) || (num == 2))
	{
		return 1;
	}
	else
	{
		//Se 'num' for maior ou igual ao terceiro termo, iniciaremos o c�lculo para encontrarmos o n-�simo termo de fibonacci
		a = 1; //Inicializando 'a' em 1 porque o primeiro termo da sequencia de fibonacci sempre ser� = 1
		b = 1;//Inicializando 'b' em 1 porque o segundo termo da sequencia de fibonacci sempre ser� = 1
		
		for (i=3; i<=num; i++)
		{
			c = a + b;
			/* 1, 1, 2, 3, 5, 8, 13, 21, 34
			   a  b  c
			      a  b  c
				     a  b  c             */
				     
			a = b; //atualizando o valor de 'a' para rodada seguinte
			b = c; //atualizando o valor de 'b' para rodada seguinte
		}
		return c;
	}
}
