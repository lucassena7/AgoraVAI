/* Desenvolver uma fun��o que, dado um arquivo texto, verifique o n�mero de caracteres no mesmo.*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int numCaracteres (char nomeArq[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArq[20];
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser lido: ");
	fflush (stdin);
	gets (nomeArq);
	
	//chamando a fun��o
	if (numCaracteres (nomeArq) == FALSE) 
	{
		printf ("\nErro na abertura do arquivo!");
	}
	else
	{
		printf ("\n O Arquivo possui %d caracteres", numCaracteres(nomeArq));
	}
}

int numCaracteres (char nomeArq[])
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
			cont++;
		}
		
		//4. fechar o arquivo
		fclose (arquivo);
		
		return cont;
	}
}
