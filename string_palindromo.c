/*
	FPR - Fundamentos de Programaçãop
	Professor Leonardo Vianna
	Data: 29/08/2022
	
	Dada uma string s, desenvolver uma função que determine se s é ou não um palíndromo.
	Observação: uma string s será um palíndromo quando seus caracteres formarem a mesma
	sequência, independente se s é percorrida da esquerda para direita ou vice-versa. */

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//Declaração de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int palindromo (char string[]);

//main
void main ()
{
	//declaração de variáveis
	char s[30];
	int retorno;
	
	//leitura das strings
	printf ("Entre com a string: ");
	fflush (stdin);
	gets (s);
	
	retorno = palindromo(s);
	
	if (retorno == TRUE)
	{
		printf ("\nA string %s e um palindromo!", s);
	}
	else
	{
		printf ("\nA string %s nao e um palindromo!", s);
	}
}

int palindromo (char string[])
{
	//Declaração de variáveis
	int i,j;
	
	for (i=0,j=strlen(string)-1;i<j; i++, j--) //'i' começa na primeira posiçaõ, 'j' começa na segunda posição; i<j 
	{
		if (string[i] != string[j]) // É diferente ? Retorna FALSO e continua o for.
		{
			return FALSE;
		}
	}
	return TRUE; //Após percorrer o for, e nao ter achado letras diferentes retornará como TRUE.
}
