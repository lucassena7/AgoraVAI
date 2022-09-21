/*Implementar uma fun��o que, dada uma string s, determine a quantidade de caracteres distintos em s */

//Importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//Defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos/cabe�alhos das fun��es
int caracteresDistintos (char s[]);

//main
void main ()
{
	//Declara��o de vari�veis
	char frase[30];
	int resultado;
	
	printf("Entre com uma palavra: ");
	fflush(stdin);
	gets(frase);
	
	resultado = caracteresDistintos(frase);
	
	printf("A string %s possui %d caracteres distintos.", frase, resultado);
}

//Implementa��o das demais fun��es
int caracteresDistintos (char s[])
{
	//Declara��o de vari�veis
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
