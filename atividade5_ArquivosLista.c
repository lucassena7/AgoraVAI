/* 							Atividade 5
Desenvolver uma fun��o que, dado um arquivo com n�meros inteiros, um por linha, crie uma lista encadeada L 
com a seguinte caracter�stica:
Cada n� de L ter� os seguintes campos: valor (cada n�mero distinto existente no arquivo), quantidade
(quantas vezes o n�mero armazenado no campo valor encontra-se no arquivo), prox (endere�o do pr�ximo
n� da lista).
Para exemplificar, considerem o seguinte arquivo:
5
1
4
4
1
5
2
3
5
2
3
4
1
Como o arquivo possui 5 elementos distintos, a lista L, neste exemplo, ter� 5 n�s (n�o necessariamente nesta ordem):
1. N� com 5 no campo valor e 3 no campo quantidade (uma vez que o valor 5 aparece 3 vezes no arquivo);
2. N� com 1 no campo valor e 3 no campo quantidade (uma vez que o valor 1 aparece 3 vezes no arquivo);
3. N� com 4 no campo valor e 3 no campo quantidade (uma vez que o valor 4 aparece 3 vezes no arquivo);
4. N� com 2 no campo valor e 2 no campo quantidade (uma vez que o valor 2 aparece 2 vezes no arquivo);
5. N� com 3 no campo valor e 2 no campo quantidade (uma vez que o valor 3 aparece 2 vezes no arquivo);
*/ 

//Importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Defini��o de constantes
#define TRUE 1
#define FALSE 0

//Declara��o de tipos
//Criamos um nome provis�rio 'No' para o struct 'TNo', para que possamos manipular o struct.
typedef struct No{
	int valor; //Vale lembrar que � 'int' porque se trata de uma lista de inteiros. Pode ser float, string, struct...
	int quantidade;
	struct No* prox; //? um ponteiro para um struct, neste caso para um igual ao criado.
}TNo;

typedef TNo* TLista; //TLista � um ponteiro para TNo

//Prot�tipo das fun��es
int lerArquivo (char nomeArq[]);
int preencherLista (char nomeArq[], TLista * L);
void exibir (TLista L);

//Main
void main  ()
{
	//Declara��o de vari�veis
	char nomeArq[20];
	TLista L = NULL;
	
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
		printf ("\n\n");
	}
	
	//chamando a fun��o
	switch (preencherLista (nomeArq, &L))
	{
		case -1: printf ("\nErro na abertura do arquivo!");
				 break;
		
		case 0: printf ("\nErro na alocacao de memoria!.");
		         break;
		
		case 1:	exibir (L);
	}
}

//Implementa��o das demais fun��es
int lerArquivo (char nomeArq[])
{
	//declara��o de vari�veis
	FILE *arquivo;			//1. declarar uma vari�vel do tipo FILE*
	int numero;
		
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
		while (fscanf (arquivo, "%d", &numero) != EOF)    //EOF - End Of File
		{
			//exibindo na tela os valores lidos do arquivo
			printf ("%d\n", numero);
		}
		
		//4. fechar o arquivo
		fclose (arquivo);
		
		return TRUE;
	}
}

int preencherLista (char nomeArq[], TLista * L)
{
	//declara��o de vari�veis
	FILE *arq;
	TLista aux;
	int valor;
	
	//abrindo os arquivos
	arq = fopen (nomeArq, "r");
	
	//verificando se houve erro na abertura do arquivo
	if (!arq)
	{
		fclose (arq);
		
		return -1; //retornando -1 caso tenha dado erro.
	}
	else
	{
		//lendo os elementos do arquivo original
		while (fscanf (arq, "%d", &valor) != EOF)
		{
			if (buscar(*L, valor) == FALSE) //Verificando se a lista est� vazia ou o n�mero a ser inserido n�o se encontra na lista
			{
				//Passo 1: alocar mem�ria
				aux = (TLista) malloc (sizeof(TNo)); //malloc: argumento -> quantos bytes vc quer ? (retorna *void)
																							//void = indeterminado
												//Tivemos q fazer um casting (TLista). Convertemos *void para TLista
												
				//Verificando se a mem�ria foi alocada
				if (aux == NULL)
				{
					return 0;
				}
				else
				{
					//Passo 2: armazenando 'numero' na posi��o alocada
					aux->valor = valor;
		
					//Passo 3: fazendo o novo n� aontar para aquele que at� ent�o era o primeiro n� da lista
					aux->prox = *L;
		
					//Passo 4: fazer com que a lista aponte para o novo elemento (uma vez que est� sendo inserido no inicio da lista
					*L = aux;
				}
			}
			else
			//Como Ler o pr�ximo caracter ??
			{
				fscanf (arq, "%d", &valor); //Tentativa de ler o proximo caracter
			}
		}
		return 1;
	}
}

int buscar (TLista L, int numero)
{
	//Declara��o de vari�veis
	TLista aux = L; //Fazendo 'aux' que � um ponteiro para TNo apontar para o primeiro n� da lista
	
	if (aux == NULL) //verificando se a lista est� vazia
	{
		return FALSE; //Retornando FALSE uma vez que n�o h� elementos na lista.
	}
	else //a lista n�o est� vazia
	{
		while (aux != NULL) //Enquanto aux for diferente de NULL
		{
			if ( aux->valor == numero) //Verificando se o n�mero buscado � igual ao elemento apontado por aux
			{
				return TRUE; //Retornando TRUE caso o valor esteja na lista.
			}
			//Atualizando o valor de aux
			aux = aux->prox; 
		}
	}
	return FALSE; //Se chegou aqui � pq o valor n�o foi encontrado na lista.
}

void exibir (TLista L)
{
	//Declara��o de vari�veis
	TLista aux = L; //Fazendo 'aux' que � um ponteiro para TNo apontar para o primeiro n� da lista
	
	if (L == NULL) //Testando se a a lista est� vazia
	{
		printf ("Lista Vazia !.");
	}
	
	else
	{
		printf ("Lista: ");
		
		while (aux != NULL) //Enquanto aux for diferente de NULL
		{
			//Printando o valor da lista
			printf ("%d", aux->valor); //printa o que � apontado por aux
									//pode ser ("%d", (*aux).valor));
		
			//Atualizando o valor de aux
			aux = aux->prox; 
		}	
	}
}
