/* Fazer uma função que calcule o MDC (máximo divisor comum) entre dois números. */

//Importação de bibliotecas
#include <stdio.h>

//Protótipo das funções
int mdc (int num1, int num2);

//Main
void main ()
{
	//Declaração de variáveis
	int num1, num2, resposta;
	
	//Entre com o primeiro número
	printf ("Entre com o primeiro numero: ");
	scanf ("%d", &num1);
	
	//Entre com o segundo número
	printf ("Entre com o segundo numero: ");
	scanf ("%d", &num2);
	
	resposta = mdc(num1, num2);
	
	printf ("O MDC entre %d e %d e: %d", num1, num2, resposta);
}

//Implementação das demais funções
int mdc (int num1, int num2)
{
	
}
