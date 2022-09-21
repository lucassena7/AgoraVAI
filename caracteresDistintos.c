/*Implementar uma função que, dada uma string s, determine a quantidade de caracteres distintos em s */

//Importação de bibliotecas
#include <stdio.h>
#include <string.h>

//Definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos/cabeçalhos das funções
int caracteresDistintos (char s[]);

//main
void main ()
{
	//Declaração de variáveis
	char frase[30];
	int resultado;
	
	printf("Entre com uma palavra: ");
	fflush(stdin);
	gets(frase);
	
	resultado = caracteresDistintos(frase);
	
	printf("A string %s possui %d caracteres distintos.", frase, resultado);
}

//Implementação das demais funções
int caracteresDistintos (char s[])
{
	//Declaração de variáveis
	int i, j, encontrou, cont=0;
	/*
	
		C  a  s  a
		0  1  2  3
		i
		C  a  s  a  a
		i
	
	*/
	for (i=0; s[i]; i++)
	{
		encontrou = FALSE;
		
		for (j=0; j<i; j++)
		{
			if (s[i] == s[j])
			{
				encontrou = TRUE;
			}
		}
		if (encontrou == FALSE)
		{
			cont++;
		}
	}
	return cont;
}
