/*
	FPR - Fundamentos de Programa��op
	Professor Leonardo Vianna
	Data: 29/08/2022
	
	Dada uma string s, desenvolver uma fun��o que determine se s � ou n�o um pal�ndromo.
	Observa��o: uma string s ser� um pal�ndromo quando seus caracteres formarem a mesma
	sequ�ncia, independente se s � percorrida da esquerda para direita ou vice-versa. */

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//Declara��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int palindromo (char string[]);

//main
void main ()
{
	//declara��o de vari�veis
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
	//Declara��o de vari�veis
	int i,j;
	
	for (i=0,j=strlen(string)-1;i<j; i++, j--) //'i' come�a na primeira posi�a�, 'j' come�a na segunda posi��o; i<j 
	{
		if (string[i] != string[j]) // � diferente ? Retorna FALSO e continua o for.
		{
			return FALSE;
		}
	}
	return TRUE; //Ap�s percorrer o for, e nao ter achado letras diferentes retornar� como TRUE.
}
