/*	Fa�a uma fun��o que, dado um arquivo A contendo n�meros reais, 
	um por linha, crie um novo arquivo B contendo os mesmos elementos 
	de A, por�m ordenados decrescentemente e sem repeti��o.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <limits.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int criarArquivoOrdenado (char nomeArqOrig[], char nomeArqNovo[]);

//main
void main ()
{
	//declara��o de vari�veis
	char original[20], novo[20];
	int resp;
	
	//lendo o nome do arquivo original
	printf ("Entre com o nome do arquivo original: ");
	fflush (stdin);
	gets (original);

	//lendo o nome do novo arquivo
	printf ("Entre com o nome do novo arquivo a ser criado: ");
	fflush (stdin);
	gets (novo);

	//chamando a fun��o
	resp = criarArquivoOrdenado (original, novo);
	
	//testando o retorno da fun��o
	if (resp == FALSE)
	{
		printf ("\n\nErro na abertura dos arquivos!");
	}
	else
	{
		printf ("\n\nNovo arquivo gerado com sucesso!");
	}
}

int criarArquivoOrdenado (char nomeArqOrig[], char nomeArqNovo[])
{
	//declara��o de vari�veis
	FILE *orig, *novo;
	int anterior, valor, maior, fim;
	
	//abrindo os arquivos
	orig = fopen (nomeArqOrig, "r");
	novo = fopen (nomeArqNovo, "w");
	
	//testando se houve erro na abertura
	//if ((orig == NULL) || (novo == NULL))
	if ((!orig) || (!novo))
	{
		fclose (orig);
		fclose (novo);
		
		return FALSE;
	}
	else
	{
		//atribuindo a vari�vel 'fim' como false para ter o controle do arquivo do fim do arquivo
		fim = FALSE;
		
		//iniciando a vari�vel 'anterior' com o maior n�mero de inteiros a fim de fazer as compara��es
		anterior = INT_MAX;
		
		while (fim == FALSE)
		{
			//atribuindo a vari�vel 'maior' com o menor n�mero de inteiros a fim de fazer as compara��es
			maior = INT_MIN;
			
			while (fscanf (orig, "%d", &valor) != EOF)
			{
				//verificando se o valor lido � menor do que o �ltimo n�mero inserido no novo arquivo (ou seja, o valor de 'anterior')
				if (valor <= anterior)
				{
					if (valor > maior)
					{
						maior = valor;
					}	
				}		
			}
			//verificando se foi encontrado um novo elemento a ser inserido no novo arquivo
			if (maior != INT_MIN)
			{
				//escrevendo o valor no novo arquivo
				fprintf (novo, "%d\n", maior);
				
				//atualizando o 'anterior'
				anterior = maior;
				
				//reposicionando o cursor de leitura no in�cio do arquivo
				rewind (orig);
			}
			else
			{
				//n�o h� mais elemento a inserir no novo arquivo
				fim = TRUE;
			}
		}
		//fechando os arquivos
		fclose (orig);
		fclose (novo);
		
		return TRUE;
	}
}
