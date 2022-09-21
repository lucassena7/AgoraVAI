/*
	FPR - Fundamentos de Programaçãop
	Professor Leonardo Vianna
	Data: 29/08/2022
	
	Implementar uma função que remova todas as ocorrências de determinado caracter em uma string. */

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//Declaração de constantes

//protótipos das funções
void removerCaracter (char string[], char ch);

//main
void main ()
{
	//Declaração de variáveis
	char string[30];
	char caract;
	
	//leitura das strings
	printf ("Entre com a string: ");
	fflush (stdin);
	gets (string);
	
	printf ("Entre com o caracter a ser removido: ");
	scanf ("%c", &caract);
	
	printf ("\nString original antes da remocao do caracter %c: %s", caract, string);
	
	removerCaracter (string, caract);
	
	printf ("\n\nString apos a remocao do caracter %c: %s", caract, string);
}

//Implementação das demais funções
void removerCaracter (char string[], char ch)
{
	//Declaração de variáveis
	int i, j;
	
	for (i=0; string[i];) //'i' começa em 0; enquanto 'i' for válido.
	{
		if (string[i] == ch)
		{
			for(j=i; string[j]; j++) //começa o 'j' na posicao de i que é a primeira posicao onde aparace o caracter; enquanto j for válido
			{
				string[j] = string[j+1];
			}
		}
		else
		{
			i++; //Tiramos o contador 'i' do primeiro for, pois só iremos verificar a próxima letra, quando a 'nova' for verificada.
				//Reavaliamos a posicao de 'i'
		}
	}
}
