/* Desenvolver uma função que, dado um arquivo texto, verifique o número de caracteres no mesmo.*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int numCaracteres (char nomeArq[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeArq[20];
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser lido: ");
	fflush (stdin);
	gets (nomeArq);
	
	//chamando a função
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
			cont++;
		}
		
		//4. fechar o arquivo
		fclose (arquivo);
		
		return cont;
	}
}
