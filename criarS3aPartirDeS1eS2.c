/*Implementar uma fun��o que, dadas duas strings s1 e s2, crie uma nova string - s3- 
  contendo todos os caracteres de s1 que n�o estejam em s2.
  
  Nota: em s3, n�o devem existir caracteres repetidos.*/

//Importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//Defini��o de constantes


//prot�tipos/cabe�alhos das fun��es
void criarString (char s1[], char s2[], char s3[]);
int buscar (char s[], char ch);

//main
void main ()
{
	//Declara��o de vari�veis
	
	char frase[30];
	char frase2[30];
	char frase3[30];
	
	printf("Entre com uma palavra: ");
	fflush(stdin);
	gets(frase);
	
	printf("Entre com uma palavra: ");
	fflush(stdin);
	gets(frase2);
	
	criarString (frase, frase2, frase3);

	printf ("\t1� String: %s", frase);
	printf ("\n\n\t2� String: %s", frase2);
	printf ("\n\n\tString criada a partir de s1 e s2: %s", frase3);
}

//Implementa��o das demais fun��es
void criarString (char s1[], char s2[], char s3[])
{
	//Declara��o de vari�veis
	int i, j=0;
	strcpy (s3, ""); //ou s3[0]='\0'
					 //Inicializando s3 como vazio
	
	for (i=0; s1[i]; i++)
	{
		if (buscar (s2, s1[i]) < 0) //verificando se o caracter da string1 existe na string2
		{
			if (buscar(s3, s1[i]) < 0) //verificando se o caracter da string1 existe na string3
			//Poderia substituir esses 'if buscar' um dentro do outro por um &&
			{
				s3[j] = s1[i];
				s3[j+1] = '\0';
				j++;
			}
		}
	}
}

int buscar (char s[], char ch)
{
	//Declara��o de vari�veis
	int i;
	
	for (i=0; s[i]; i++)
	{
		if (s[i] == ch)
		{
			return i;
		}
	}
	return -1;
}
