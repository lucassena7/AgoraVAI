/* Implementar uma fun��o que remova todas as ocorrencias de um determinado caracter em uma String */

//Importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//Defini��o de constantes


//prot�tipos/cabe�alhos das fun��es
void removerCaracter (char s[], char ch);

//main
void main ()
{
	//declara��o de vari�veis
	char frase[30];
	char caracter;
	
	fflush(stdin);
	printf("Entre com uma palavra:");
	gets (frase);
	
	printf("Entre com uma palavra:");
	caracter = getche();
	
	//exibindo a string antes da remo��o
	printf ("\nString: %s\n", frase);
	
	removerCaracter (frase, caracter);
	
		//exibindo a string depois da remo��o
	printf ("\nString: %s\n", frase);
}

//Implementa��o das demais fun��es
void removerCaracter (char s[], char ch)
{
	//Declara�o de vari�veis
	int i, j;
	
	for (i=0; s[i];)
	{
		if (s[i] == ch)
		{
			for (j=i; s[j]; j++)
			{
				s[j] = s[j+1];
			}
		}
		else
		{
			i++; //fizemos o i++ ao final por conta do caso de caracteres iguais dispostos lado a lado. Ex: ABCCCDE.
				 //Reavaliamos a posicao 'i'.
		}
	}
}
