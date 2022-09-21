/*
	FPR - Fundamentos de Programa��op
	Professor Leonardo Vianna
	Data: 29/08/2022
	
	Implementar uma fun��o que remova todas as ocorr�ncias de determinado caracter em uma string. */

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//Declara��o de constantes

//prot�tipos das fun��es
void removerCaracter (char string[], char ch);

//main
void main ()
{
	//Declara��o de vari�veis
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

//Implementa��o das demais fun��es
void removerCaracter (char string[], char ch)
{
	//Declara��o de vari�veis
	int i, j;
	
	for (i=0; string[i];) //'i' come�a em 0; enquanto 'i' for v�lido.
	{
		if (string[i] == ch)
		{
			for(j=i; string[j]; j++) //come�a o 'j' na posicao de i que � a primeira posicao onde aparace o caracter; enquanto j for v�lido
			{
				string[j] = string[j+1];
			}
		}
		else
		{
			i++; //Tiramos o contador 'i' do primeiro for, pois s� iremos verificar a pr�xima letra, quando a 'nova' for verificada.
				//Reavaliamos a posicao de 'i'
		}
	}
}
