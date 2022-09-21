/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna
	Data: 22/08/2021
	
	Revisão - FAC   
	Desenvolver uma função que calcule o n-ésimo termo da sequência de Fibonacci.
	
		1  1  2  3  5  8  13  21  ...
					a  b  c
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes

//protótipos/cabeçalhos das funções
int fibonacci (int num);

//implementação da função main
void main ()
{
	//Declaração de variáveis
	int num, resposta;
	
	//Obtendo os dados do usuário
	printf ("\t Entre com o 'n-esimo' termo da sequencia de fibonacci ");
	scanf ("%d", &num);
	
	resposta = fibonacci (num);
	
	printf ("\tO %d termo da sequencia de fibonacci e: %d", num, resposta);
}

//implementação das demais funções
int fibonacci (int num)
{
	//Declaração de variáveis
	int a, b, c, i;
	
	//Se 'num' for igual ao primeiro ou segundo termo da sequência, será igual a 1
	if ((num == 1) || (num == 2))
	{
		return 1;
	}
	else
	{
		//Se 'num' for maior ou igual ao terceiro termo, iniciaremos o cálculo para encontrarmos o n-ésimo termo de fibonacci
		a = 1; //Inicializando 'a' em 1 porque o primeiro termo da sequencia de fibonacci sempre será = 1
		b = 1;//Inicializando 'b' em 1 porque o segundo termo da sequencia de fibonacci sempre será = 1
		
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
