/* Desenvolver uma função que, dado um arquivotexto, verifique o número de vezes que um determinado
caracter aparece no arquivo. */

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int numVezesCaracter (char nomeArq[], char caract);

//main
void main ()
{
	//declaração de variáveis
	char nomeArq[20];
	char caract;
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser lido: ");
	fflush (stdin);
	gets (nomeArq);
	
	//lendo o caracter a ser buscado
	printf ("Entre com o caracter a ser buscado: ");
	scanf ("%c", &caract);
	
	//chamando a função
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
	//declaração de variáveis
	FILE *arquivo;			//1. declarar uma variável do tipo FILE*
	char caracter;
	int cont=0;
	
	//2.abrir o arquivo (associa a variável FILE à string que representa o arquivo / define o tipo de acesso)
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
