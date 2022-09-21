/* Implementar uma função que remova todas as ocorrencias de um determinado caracter em uma String */

//Importação de bibliotecas
#include <stdio.h>
#include <string.h>

//Definição de constantes


//protótipos/cabeçalhos das funções
void removerCaracter (char s[], char ch);

//main
void main ()
{
	//declaração de variáveis
	char frase[30];
	char caracter;
	
	fflush(stdin);
	printf("Entre com uma palavra:");
	gets (frase);
	
	printf("Entre com uma palavra:");
	caracter = getche();
	
	//exibindo a string antes da remoção
	printf ("\nString: %s\n", frase);
	
	removerCaracter (frase, caracter);
	
		//exibindo a string depois da remoção
	printf ("\nString: %s\n", frase);
}

//Implementação das demais funções
void removerCaracter (char s[], char ch)
{
	//Declaraão de variáveis
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
