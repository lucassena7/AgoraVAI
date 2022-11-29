/*
	FAETERJ-Rio
	FPR - 2022/1
	Data: 30/04/2022
	
	Lista de Exerc�cios VII (Arquivos)
	
	Quest�o 05:
	Fa�a uma fun��o que, dado um arquivo A contendo n�meros reais, um por linha, 
	crie um novo arquivo B contendo os mesmos elementos de A, por�m ordenados 
	decrescentemente e sem repeti��o.
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int gerarArquivoOrdenado (char nomeArqA[], char nomeArqB[]);

//main
void main ()
{
	//declara��o de arquivos
	char nomeArquivoA[30], nomeArquivoB[30];
	int retorno;
	
	//lendo o nome do arquivo original
	printf ("Entre com o nome do primeiro arquivo: ");
	fflush (stdin);
	gets (nomeArquivoA);
	
	//lendo o nome do arquivo a ser criado
	printf ("Entre com o nome do segundo arquivo: ");
	fflush (stdin);
	gets (nomeArquivoB);

	//chamando a fun��o
	retorno = gerarArquivoOrdenado (nomeArquivoA, nomeArquivoB);
	
	//exibindo o resultado
	if (retorno == TRUE)
	{
		printf ("\nArquivo gerado com sucesso.");
	}
	else
	{
		printf ("\nErro na bertura dos arquivos.");
	}
}

//implementa��o das fun��es
int gerarArquivoOrdenado (char nomeArqA[], char nomeArqB[])
{
	//declara��o de vari�veis
	FILE *arqA, *arqB;
	float maior, numero, ultimo = 99999;
	int sair;
	
	//abrindo os arquivos
	arqA = fopen (nomeArqA, "r");
	arqB = fopen (nomeArqB, "w");
	
	//testando se houve sucesso ou n�o na abertura do arquivo
	if ((arqA == NULL) || (arqB == NULL))
	{
		//garantindo que, caso algum arquivo tenha sido aberto, o mesmo ser� fechado antes da fun��o terminar
		fclose (arqA);
		fclose (arqB);
		
		return FALSE;
	}
	else
	{
		do
		{
			//reposicionando o ponteiro de leitura do arquivo A para o seu in�cio
			rewind (arqA);			
			
			//inicializando a vari�vel 'maior'
			maior = -99999;
			
			//vari�vel de controle do do..while (repeti��o externa)
			sair = TRUE;  
			
			//lendo os numeros do arquivo A
			while (fscanf (arqA, "%f", &numero) != EOF)
			{
				//para cada n�mero lido, verificar: 1. se � menor do que o �ltimo inserido
				//no arquivo B; ii. se � o maior at� ent�o.
				if ((numero < ultimo) && (numero > maior))
				{
					//atualizando o maior
					maior = numero;
					
					//uma vez que um novo valor foi encontrado, registra-se que n�o � ainda o momento de terminar a busca
					sair = FALSE;
				}
			}
			
			//verificando se foi encontrado elemento para ser inserido no arquivo B
			if (sair == FALSE)
			{
				//escrevendo o valor no arquivo B
				fprintf (arqB, "%.1f\n", maior);
				
				//aramzenando o �ltimo valor inserido no arquivo B
				ultimo = maior;
			}
		}
		while (sair == FALSE);
		
		//fechando os arquivos
		fclose (arqA);
		fclose (arqB);
		
		return TRUE;
	}
}
