/*
	FAETERJ-Rio
	FPR - Manh� - 2022/2
	Data: 13/10/2022
	
	Arquivos
	
	Exemplo 6: desenvolver uma fun��o que, dado um arquivo texto
	contendo n�meros inteiros - um por linha, remova do arquivo 
	todas as ocorr�ncias de determinado valor 'num'.
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int removerElementoArquivo (char nomeArq[], int numero);
int copiarArquivo (char origem[], char destino[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArq[20];
	int num, resp;
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser lido: ");
	fflush (stdin);
	gets (nomeArq);
	
	//lendo o n�mero a ser removido do arquivo
	printf ("\nEntre com o valor a ser removido: ");
	scanf ("%d", &num);
	
	//chamando a fun��o
	resp = removerElementoArquivo (nomeArq, num);
	
	//testando o retorno da fun��o
	switch (resp)
	{
		case -1: printf ("\n\nErro na abertura do arquivo!");
		         break;
		         
		case 0:  printf ("\n\nO valor %d nao existe no arquivo!", num);
		         break;
		
		default: printf ("\n\nO valor %d foi removido %d vezes do arquivo!", num, resp);
	}
}

//implementa��o das fun��es
int removerElementoArquivo (char nomeArq[], int numero)
/*
	retornar�:
		-1	erro na abertura do arquivo
		0	o elemento n�o existe no arquivo
		outro valor:	representar� quantas remo��es foram feitas	
*/
{
	//declara��o de vari�veis
	FILE *arq, *tmp;
	int valor, cont = 0;
	
	//abrindo os arquivos
	arq = fopen (nomeArq, "r");
	tmp = fopen ("temp.txt", "w");
	
	//verificando se houve erro na abertura dos arquivos
	//if ((arq == NULL) || (tmp == NULL))	
	if ((!arq) || (!tmp))	
	{
		fclose (arq);
		fclose (tmp);
		
		return -1;
	}
	else
	{
		//lendo os elementos do arquivo original
		while (fscanf (arq, "%d", &valor) != EOF)
		{
			//verificando se o valor lido n�o � aquele que deseja-se remover
			if (valor != numero)
			{
				fprintf (tmp, "%d\n", valor);
			}
			else
			{
				cont++;
			}
		}
		
		//fechando os arquivos
		fclose (arq);
		fclose (tmp);

		//copiando o arquivo tempor�rio para o original		
		copiarArquivo ("temp.txt", nomeArq);
		
		//retornando a quantidade de remo��es realizadas
		return cont;
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
		fclose (arqO);
		fclose (arqD);
		
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
