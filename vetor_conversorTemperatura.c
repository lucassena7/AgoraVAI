/*
	FPR - Fundamentos de Programa��o
	Professor Leonardo Vianna
	Data: 22/08/2021
	
	Revis�o - FAC   
	Implementar uma fun��o que converta determinada temperatura em graus Celsius para graus Fahrenheit.
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes

//prot�tipos/cabe�alhos das fun��es
float converterTemp (int celsius);

//implementa��o da fun��o main
void main ()
{
	//Declara��o de vari�veis
	int celsius;
	float resposta;
	
	//Obtendo os dados do usu�rio
	printf ("\t Entre com a temperatura em grau(s) Celsis: ");
	scanf ("%d", &celsius);
	
	resposta = converterTemp (celsius);
	
	printf ("\t%d grau(s) Celsius e equivalente a %.2f grau(s) fahrenheit", celsius, resposta);
}

//implementa��o das demais fun��es
float converterTemp (int celsius)
{
	//Declara��o de vari�veis
	float fahrenheit;
	
	fahrenheit = celsius*1.8 + 32;
	
	return fahrenheit;
}
