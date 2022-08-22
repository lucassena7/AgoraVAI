/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna
	Data: 22/08/2021
	
	Revisão - FAC   
	Implementar uma função que converta determinada temperatura em graus Celsius para graus Fahrenheit.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes

//protótipos/cabeçalhos das funções
float converterTemp (int celsius);

//implementação da função main
void main ()
{
	//Declaração de variáveis
	int celsius;
	float resposta;
	
	//Obtendo os dados do usuário
	printf ("\t Entre com a temperatura em grau(s) Celsis: ");
	scanf ("%d", &celsius);
	
	resposta = converterTemp (celsius);
	
	printf ("\t%d grau(s) Celsius e equivalente a %.2f grau(s) fahrenheit", celsius, resposta);
}

//implementação das demais funções
float converterTemp (int celsius)
{
	//Declaração de variáveis
	float fahrenheit;
	
	fahrenheit = celsius*1.8 + 32;
	
	return fahrenheit;
}
