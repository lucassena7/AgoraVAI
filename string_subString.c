/* 	FPR - Fundamentos de Programaçãop
	Professor Leonardo Vianna
	Data: 29/08/2022
	
	Desenvolver uma função que, dada uma string s, crie uma substring que inicie na posição p de s e contenha n caracteres.
	Observações: se p e/ou n forem inválidos, a substring será vazia; ii) se s não possuir n caracteres além de p, a substring
	a ser criada começará em p e terminará no final de s.*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//Declaração de constantes

//protótipos das funções
void subString (char frase[], int p, int n, char fraseDois[]);

//main
void main ()
{
	//Declaração de variáveis
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

//Implementação das demais funções
void subString (char frase[], int p, int n, char fraseDois[])
{
	//Declaração de variáveis
	int i, j;
	
	if ((p<0) || (p>strlen(frase)-1) || (n<=0))
	{
		fraseDois[0] = '\0';
	}
	else
	{
		for (i=p, j=0; (frase[i]) && (j<n); i++, j++) //'i' começa na posicao 'p', 'j' começa em 0; roda enquanto 'i' for válido e 'j' for <n
		{
			fraseDois[j] = frase[i]; 	
		}
		fraseDois[j] = '\0';
	}
}
