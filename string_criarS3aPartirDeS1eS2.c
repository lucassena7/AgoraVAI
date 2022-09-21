/*Implementar uma função que, dadas duas strings s1 e s2, crie uma nova string - s3- 
  contendo todos os caracteres de s1 que não estejam em s2.
  
  Nota: em s3, não devem existir caracteres repetidos.*/

//Importação de bibliotecas
#include <stdio.h>
#include <string.h>

//Definição de constantes


//protótipos/cabeçalhos das funções
void criarString (char s1[], char s2[], char s3[]);
int buscar (char s[], char ch);

//main
void main ()
{
	//Declaração de variáveis
	
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

	printf ("\t1° String: %s", frase);
	printf ("\n\n\t2° String: %s", frase2);
	printf ("\n\n\tString criada a partir de s1 e s2: %s", frase3);
}

//Implementação das demais funções
void criarString (char s1[], char s2[], char s3[])
{
	//Declaração de variáveis
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
	//Declaração de variáveis
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
