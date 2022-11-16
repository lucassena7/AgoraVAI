/*	Arquivos
	
	Exemplo 1: desenvolver uma fun��o que escreva em um arquivo os n�meros de 1 a N.
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int gerarArquivo (char nomeArq[], int n);

//main
void main ()
{
	//declara��o de vari�veis
	int n;
	char nomeArq[20];
	
	//lendo o valor de N
	printf ("Entre com um numero inteiro: ");
	scanf ("%d", &n);
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser criado: ");
	fflush (stdin);
	gets (nomeArq);
	
	//chamando a fun��o
	if (gerarArquivo (nomeArq, n) == FALSE)
	{
		printf ("\nErro na geracao do arquivo!");
	}
	else
	{
		printf ("\nArquivo gerado com sucesso!");
	}
}

int gerarArquivo (char nomeArq[], int n)
{
	//declara��o de vari�veis
	int i;
	FILE *arquivo;			//1. declarar uma vari�vel do tipo FILE*
		
	//2.abrir o arquivo (associa a vari�vel FILE � string que representa o arquivo / define o tipo de acesso)
	arquivo = fopen (nomeArq, "w");  //w - write    r - read    a - append
	
	//testando se houve falha na abertura
	if (arquivo == NULL)
	{
		return FALSE;
	}
	else
	{
		//escrevendo os elementos de 1 at� N no arquivo
		for (i=1;i<=n;i++)
		{
			fprintf (arquivo, "%d\n", i);		//3. manipular o arquivo
		}
		
		//4. fechar o arquivo
		fclose (arquivo);
		
		return TRUE;
	}
}
