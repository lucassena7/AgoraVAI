/*	string: A L G O R I T M O S \0
			0 1 2 3 4 5 6 7 8 9 10
			
	subsString: R I T M O \0
				0 1 2 3 4 5 
	P=4 e N=5.
	
	P inv�lido: <=0 e >10
	N inv�lido: <0
*/

//Importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//Defini��o de constantes

//prot�tipos/cabe�alhos das fun��es
void subString (char s[], int p, int n, char sub[]);

//Main
void main ()
{
	//declara��o de vari�veis
	char frase[30];
	char frase2[20];
	int p, n;
	
	fflush(stdin);
	printf("Entre com uma palavra:");
	gets (frase);
	
	printf("Entre com o valor de p:");
	scanf ("%d", &p);
	
	printf("Entre com o valor de n:");
	scanf ("%d", &n);
	
	subString (frase, p, n, frase2);
//	printf ("%s", frase2);
	printf ("\nA string original e: %s.", frase);
	printf ("\nA subString e: %s.", frase2);
}

//Implementa��o das demais fun��es
void subString (char s[], int p, int n, char sub[])
{
	//Declara��o de vari�veis
	int i, j;
	
	if ((p <0) || (p >=strlen(s)) || (n<=0))
	{
		//sub[0] = '\0';
		
		strcpy (sub, "");
	}
	else
	{
		for (i=p, j=0; (j<n) && (s[i]); i++, j++)
		{
			sub[j] = s[i];
		}
		sub[j] = '\0';
	}
}
