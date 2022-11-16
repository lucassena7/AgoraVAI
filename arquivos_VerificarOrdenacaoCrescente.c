/* Desenvolver uma fun��o que, dado um arquivo texto contendo n�meros, determine se estes encontram-se
ordenados crescentemente.*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int verificarOrdenacao (char nomeArq[]);

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
	switch (verificarOrdenacao (nomeArq))
	{
		case -1: printf ("\nErro na abertura do arquivo!");
				 break;
		
		case 0: printf ("\nOs elementos do arquivo %s NAO estao ordenados crescentemente.", nomeArq);
		         break;
		
		case 1:	 printf ("\nOs elementos do arquivo %s estao ordenados crescentemente.", nomeArq);
	}
}

int verificarOrdenacao (char nomeArq[])
{
	//declara��o de vari�veis
	FILE *arquivo;			//1. declarar uma vari�vel do tipo FILE*
	int menor, maior;
	
	//2.abrir o arquivo (associa a vari�vel FILE � string que representa o arquivo / define o tipo de acesso)
	arquivo = fopen (nomeArq, "r");  //w - write    r - read    a - append
	
	//testando se houve falha na abertura
	if (arquivo == NULL)
	{
		return -1;
	}
	else
	{
		//Lendo o primeiro numero do arquivo
		fscanf (arquivo, "%c", &menor);
		
		//lendo os elementos do arquivo
		while (fscanf (arquivo, "%c", &maior) != EOF)    //EOF - End Of File
		{
			//Verificando se os n�meros est�o DESordenados de maneira crescente
			if (menor > maior)
			{
				//fechar o arquivo
				fclose (arquivo);
				
				//o arquivo n�o est� ordenado
				return 0;
			}
			else //Se o menor<maior
			{
				//atualiza o valor do menor para comparar com o 'novo' maior
				menor = maior;
				//a atribui��o do maior � feita no while.
			}
		}
		
		//4. fechar o arquivo
		fclose (arquivo);
		
		//O arquivo est� ordenado
		return TRUE;
	}
}
