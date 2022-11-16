/*	Arquivos
	
	Exemplo 4: copiando o conte�do de um arquivo para outro.
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int copiarArquivo (char origem[], char destino[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeOrigem[20], nomeDestino[20];
	
	//lendo o nome do arquivo origem
	printf ("Entre com o nome do arquivo a ser copiado: ");
	fflush (stdin);
	gets (nomeOrigem);
	
	//lendo o nome do arquivo destino
	printf ("Entre com o nome do arquivo a ser gerado: ");
	fflush (stdin);
	gets (nomeDestino);
	
	//chamando a fun��o
	if (copiarArquivo (nomeOrigem, nomeDestino) == FALSE) 
	{
		printf ("\nErro na copia dos arquivos!");
	}
	else
	{
		printf ("\nCopia realizada com sucesso!");
	}
}

int copiarArquivo (char origem[], char destino[])
{
	//declara��o de vari�veis
	FILE *arqO, *arqD;			//1. declarar uma vari�vel do tipo FILE*
	char caracter;
		
	//2.abrir o arquivo (associa a vari�vel FILE � string que representa o arquivo / define o tipo de acesso)
	arqO = fopen (origem, "r");
	arqD = fopen (destino, "w");
	
	//testando se houve falha na abertura
	if ((arqO == NULL) || (arqD == NULL))
	{
		return FALSE;
	}
	else
	{
		//lendo os elementos do arquivo de origem
		while (fscanf (arqO, "%c", &caracter) != EOF)    //EOF - End Of File
		{
			//escrevendo no arquivo de destino os valores lidos do arquivo de origem
			fprintf (arqD, "%c", caracter);
		}
		
		//4. fechar os arquivos
		fclose (arqO);
		fclose (arqD);
		
		return TRUE;
	}
}
