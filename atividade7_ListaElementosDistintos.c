/* Implementar uma função que, dada uma lista encadeada L, do tipo TLista, determine se todos
os seus elementos são distintos.

Lucas Miguel de Sena Costa */

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TAM 7
#define TRUE 1
#define FALSE 0

//Declaração de tipos
//Criamos um nome provisório 'No' para o struct 'TNo', para que possamos manipular o struct.
typedef struct No{
	int valor; //Vale lembrar que é 'int' porque se trata de uma lista de inteiros. Pode ser float, string, struct...
	struct No* prox; //? um ponteiro para um struct, neste caso para um igual ao criado.
}TNo;

typedef TNo* TLista; //TLista é um ponteiro para TNo

//protótipos/cabeçalhos das funções
int inserir (TLista *L, int numero);
void exibir (TLista L); //Não precisamos colocar o ponteiro pois só iremos percorrer a lista 
int verificarElementosDistintos (TLista L);

//main
void main ()
{
	//Declaração de variáveis
	TLista L = NULL;
	int op, num1, resp;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Inserção
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        if (inserir (&L, num1) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Exibir
			case 2: exibir (L);
					break;
					
			//Verificar elementos distintos
			case 3: resp = verificarElementosDistintos (L);
					
					if (resp == -1)
					{
						printf ("\n\tLista Vazia !.");
					}
					else
					{
						if (resp == 0)
						{
							printf ("\n\tOs elementos da lista NAO sao distintos.");
						}
						else
						{
							printf ("\n\tOs elementos da lista sao distintos.");
						}
					}
					break;
					
			//Saída
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 4);
}

//Implementação das demais funções
int inserir (TLista *L, int numero)
{
	//declaração de variáveis;
	TLista aux;
	
	//1º passo: alocar memória para o novo nó	
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se houve erro na alocação de memória
	if (aux == NULL)
	{
		return FALSE;
	}
	else
	{
		//2º passo: armazenar 'numero' na memória recém-alocada
		aux->valor = numero;
		
		//3º passo: mandar o campo 'prox' do novo nó apontar para o 
		//"até então" primeiro elemento	da lista
		aux->prox = *L;
		
		//4º passo: fazer com que L aponte para o novo nó da lista		
		*L = aux;
		
		return TRUE;
	}	
}

void exibir (TLista L)
{
	//declaração de variáveis
	TLista aux = L;
	
	//testando se a lista está vazia
	if (L == NULL)
	{
		printf ("\nLista vazia!");
	}
	else
	{
		printf ("\nElementos da lista: ");
		
		//percorrendo a lista até o seu final
		while (aux != NULL)
		{
			//exibindo o valor apontado pelo 'aux'
			printf ("%d ", aux->valor);
			
			//atualizando o 'aux' para apontar para o próximo nó
			aux = aux->prox;
		}
	}
}

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Exibir\n");
	printf ("(3) Verificar se os elementos sao distintos\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

int verificarElementosDistintos (TLista L)
{
	//Declaração de variáveis
	TLista aux = L; //Aux aponta para o primeiro nó da lista
	TLista prox = L->prox; //Prox aponta para onde o L->prox aponta, ou seja, o prox elememento
	
	if (aux == NULL) //verificando se a lista está vazia
	{
		return -1; //Retornando -1 para lista vazia
	}
	else
	{
		//percorrendo a lista até o final
		while (aux != NULL)
		{
			//Enquanto o prox for diferente de NULL
			while (prox != NULL)
			{
				if (aux->valor != prox->valor)
				{
					aux = prox;
					prox = prox->prox;
				}
				else
				{
					return 0; //Retornando 0 caso o elemento seja repetido
				}
			}
			aux = aux->prox;
		}
		return 1;
	}
}
