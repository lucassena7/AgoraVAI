/* Fazer uma fun��o que calcule o MDC (m�ximo divisor comum) entre dois n�meros. */

//Importa��o de bibliotecas
#include <stdio.h>

//Prot�tipo das fun��es
int mdc (int num1, int num2);

//Main
void main ()
{
	//Declara��o de vari�veis
	int num1, num2, resposta;
	
	//Entre com o primeiro n�mero
	printf ("Entre com o primeiro numero: ");
	scanf ("%d", &num1);
	
	//Entre com o segundo n�mero
	printf ("Entre com o segundo numero: ");
	scanf ("%d", &num2);
	
	resposta = mdc(num1, num2);
	
	printf ("O MDC entre %d e %d e: %d", num1, num2, resposta);
}

//Implementa��o das demais fun��es
int mdc (int num1, int num2)
{
	
}
