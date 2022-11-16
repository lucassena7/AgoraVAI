/* Desenvolver uma função que, dado um arquivo texto contendo números, determine se estes encontram-se
ordenados crescentemente.*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int verificarOrdenacao (char nomeArq[]);

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
	//declaração de variáveis
	FILE *arquivo;			//1. declarar uma variável do tipo FILE*
	int menor, maior;
	
	//2.abrir o arquivo (associa a variável FILE à string que representa o arquivo / define o tipo de acesso)
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
			//Verificando se os números estão DESordenados de maneira crescente
			if (menor > maior)
			{
				//fechar o arquivo
				fclose (arquivo);
				
				//o arquivo não está ordenado
				return 0;
			}
			else //Se o menor<maior
			{
				//atualiza o valor do menor para comparar com o 'novo' maior
				menor = maior;
				//a atribuição do maior é feita no while.
			}
		}
		
		//4. fechar o arquivo
		fclose (arquivo);
		
		//O arquivo está ordenado
		return TRUE;
	}
}
