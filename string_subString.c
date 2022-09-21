/* 	FPR - Fundamentos de Programa��op
	Professor Leonardo Vianna
	Data: 29/08/2022
	
	Desenvolver uma fun��o que, dada uma string s, crie uma substring que inicie na posi��o p de s e contenha n caracteres.
	Observa��es: se p e/ou n forem inv�lidos, a substring ser� vazia; ii) se s n�o possuir n caracteres al�m de p, a substring
	a ser criada come�ar� em p e terminar� no final de s.*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//Declara��o de constantes

//prot�tipos das fun��es
void subString (char frase[], int p, int n, char fraseDois[]);

//main
void main ()
{
	//Declara��o de vari�veis
	char string[30];
	char subS[20];
	int p, n;
	
	//leitura das strings
	printf ("Entre com a string: ");
	fflush (stdin);
	gets (string);
	
	printf ("Entre com o valor de p: ");
	scanf ("%d", &p);
	
	printf ("Entre com o valor de n: ");
	scanf ("%d", &n);
	
	printf ("String original: %s", string);
	
	subString (string, p, n, subS);
	
	printf ("\nSubString criada: %s", subS);
}

//Implementa��o das demais fun��es
void subString (char frase[], int p, int n, char fraseDois[])
{
	//Declara��o de vari�veis
	int i, j;
	
	if ((p<0) || (p>strlen(frase)-1) || (n<=0))
	{
		fraseDois[0] = '\0';
	}
	else
	{
		for (i=p, j=0; (frase[i]) && (j<n); i++, j++) //'i' come�a na posicao 'p', 'j' come�a em 0; roda enquanto 'i' for v�lido e 'j' for <n
		{
			fraseDois[j] = frase[i]; 	
		}
		fraseDois[j] = '\0';
	}
}
