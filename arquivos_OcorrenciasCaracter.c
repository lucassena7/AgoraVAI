/* Desenvolver uma fun��o que, dado um arquivotexto, verifique o n�mero de vezes que um determinado
caracter aparece no arquivo. */

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int numVezesCaracter (char nomeArq[], char caract);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArq[20];
	char caract;
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser lido: ");
	fflush (stdin);
	gets (nomeArq);
	
	//lendo o caracter a ser buscado
	printf ("Entre com o caracter a ser buscado: ");
	scanf ("%c", &caract);
	
	//chamando a fun��o
	if (numVezesCaracter (nomeArq, caract) == FALSE) 
	{
		printf ("\nErro na abertura do arquivo!");
	}
	else
	{
		printf ("\n O caracter %c aparece %d vezes no arquivo %s", caract, numVezesCaracter(nomeArq, caract), nomeArq);
	}
}

int numVezesCaracter (char nomeArq[], char caract)
{
	//declara��o de vari�veis
	FILE *arquivo;			//1. declarar uma vari�vel do tipo FILE*
	char caracter;
	int cont=0;
	
	//2.abrir o arquivo (associa a vari�vel FILE � string que representa o arquivo / define o tipo de acesso)
	arquivo = fopen (nomeArq, "r");  //w - write    r - read    a - append
	
	//testando se houve falha na abertura
	if (arquivo == NULL)
	{
		return FALSE;
	}
	else
	{
		//lendo os elementos do arquivo
		while (fscanf (arquivo, "%c", &caracter) != EOF)    //EOF - End Of File
		{
			if (caracter == caract)
			{
				cont++;
			}
		}
		
		//4. fechar o arquivo
		fclose (arquivo);
		
		return cont;
	}
}
