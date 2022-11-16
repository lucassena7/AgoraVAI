/*
	FAETERJ-Rio
	FPR - Manh� - 2022/2
	Data: 06/10/2022
	
	Arquivos
	
	Exemplo 5: lendo os dados de um arquivo, tratando-os como 
	caracteres (por n�o saber a estrutura exata de seu conte�do)
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int lerArquivo (char nomeArq[]);

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
	if (lerArquivo (nomeArq) == FALSE) 
	{
		printf ("\nErro na abertura do arquivo!");
	}
	else
	{
		printf ("\nArquivo aberto com sucesso!");
	}
}

int lerArquivo (char nomeArq[])
{
	//declara��o de vari�veis
	FILE *arquivo;			//1. declarar uma vari�vel do tipo FILE*
	char caracter;
		
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
			//exibindo na tela os valores lidos do arquivo
			printf ("%c", caracter);
		}
		
		//4. fechar o arquivo
		fclose (arquivo);
		
		return TRUE;
	}
}
