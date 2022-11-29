/*	Faça uma função que, dado um arquivo A contendo números reais, 
	um por linha, crie um novo arquivo B contendo os mesmos elementos 
	de A, porém ordenados decrescentemente e sem repetição.
*/

//importação de bibliotecas
#include <stdio.h>
#include <limits.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int criarArquivoOrdenado (char nomeArqOrig[], char nomeArqNovo[]);

//main
void main ()
{
	//declaração de variáveis
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

	//chamando a função
	resp = criarArquivoOrdenado (original, novo);
	
	//testando o retorno da função
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
	//declaração de variáveis
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
		//atribuindo a variável 'fim' como false para ter o controle do arquivo do fim do arquivo
		fim = FALSE;
		
		//iniciando a variável 'anterior' com o maior número de inteiros a fim de fazer as comparações
		anterior = INT_MAX;
		
		while (fim == FALSE)
		{
			//atribuindo a variável 'maior' com o menor número de inteiros a fim de fazer as comparações
			maior = INT_MIN;
			
			while (fscanf (orig, "%d", &valor) != EOF)
			{
				//verificando se o valor lido é menor do que o último número inserido no novo arquivo (ou seja, o valor de 'anterior')
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
				
				//reposicionando o cursor de leitura no início do arquivo
				rewind (orig);
			}
			else
			{
				//não há mais elemento a inserir no novo arquivo
				fim = TRUE;
			}
		}
		//fechando os arquivos
		fclose (orig);
		fclose (novo);
		
		return TRUE;
	}
}
