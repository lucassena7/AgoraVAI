/* Fazer uma função que, dados uma lista encadeada L, do tipo TLista, cujos elementos estão ordenados 
crescentemente, e um número n, remova todas as ocorrências de n em L. */

//Importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//prototipo das funções
int menu ();
int inserirOrdenado(TLista *L, int numero);
void exibirLista (TLista L);
int remover (TLista *L, int numero);

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
			        if (inserirOrdenado (&L, num1) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Exibir
			case 2: exibirLista (L);
					break;
			
			//Remover
			case 3: printf ("Entre com o numero a ser removido: ");
					scanf ("%d", &num1);
					
					resp = remover (&L, num1);
					
					if (resp == -1)
					{
						printf ("Lista Vazia !.");
					}
					else
					{
						if (resp == 0)
						{
							printf ("O numero %d nao existe na lista !.");
						}
						else
						{
							printf ("Foram realizadas %d remocoes do numero %d\n", resp, num1);
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

int inserirOrdenado(TLista *L, int numero)
{
	//Declaração de variáveis
	TLista novo; //Vai ser o 'novo' nó a ser alocado
	TLista ant = NULL; //Vai ser o nó que armazenará as informações do nó 'anterior'
	TLista aux = *L; //Aux vai ser o nó corrente
	
	//1º passo: alocar memória para o novo nó
	novo = (TLista) malloc (sizeof(TNo));
	
	//verificando se a memória foi alocada
	if (novo == NULL)
	{
		return FALSE;
	}
	else
	{
  		// Referencial estrutural (levo em consideracao a estrutura propriamente dita)
  		// casos que a insere ordenado precisa tratar
		//         // insiro o 2
  		// 2      // insiro o 10 : inicio da lista
  		// 10 - 2 // insiro  o 5 : meio
  		// 10 - 2 ->NULL // insiro o 1  : ultimo
		
		//armazenando o 'numero' na posição valor do 'novo' nó
		novo->valor = numero;
		
  		// aux é o no corrent. Enquanto a lista não estiver vazia e o valor do nó corrente for menor que o número a ser inserido
  		while ((aux != NULL) && (aux->valor < numero))  // caso lista nao vazia
		{
    		ant = aux;       // andando na lista
    		aux = aux->prox; // andando na lista
  		}

  		if (ant == NULL) // Se a lista estiver vazia. Insiro no início
		{
			//Fazendo o prox do novo nó apontar para onde a lista aponta
    		novo->prox = *L;
			
			//Fazendo a lista apontar para o 'novo' nó
    		*L = novo;
  		}
		else // todos os outros casos. Inserir no meio e no final
		{
			//Fazendo o prox do 'novo' nó apontar para onde o prox do anterior aponta
    		novo->prox = ant->prox;
    		
    		//Fazendo o prox do anterior apontar para o 'novo' nó
    		ant->prox = novo;
  		}
	}
	//Se chegou aqui é pq o número foi inserido. Retornando TRUE
	return TRUE;
}

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir um elemento\n");
	printf ("(2) Exibir elemento(s)\n");
	printf ("(3) Remover ocorrencia(s) de um elemento\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

void exibirLista (TLista L)
{
	//Declaração de variáveis
	TLista aux = L; //Fazendo 'aux' que é um ponteiro para TNo apontar para o primeiro nó da lista
	
	if (L == NULL) //Testando se a a lista está vazia
	{
		printf ("Lista Vazia !.");
	}
	
	else
	{
		printf ("Lista: ");
		
		while (aux != NULL) //Enquanto aux for diferente de NULL
		{
			//Printando o valor da lista
			printf ("%d", aux->valor); //printa o que é apontado por aux
									//pode ser ("%d", (*aux).valor));
		
			//Atualizando o valor de aux
			aux = aux->prox; 
		}
		printf ("\n");	
	}
}

int remover (TLista *L, int numero)
{
	//declaração de variáveis
	TLista aux1, aux2;
	int cont = 0;
	
	if (!(*L))
	{
		return -1;
	}
	else
	{
		//verificando se o primeiro elemento da lista é o número que deseja-se remover
		while ((*L) && ((*L)->valor == numero))
		{
			//fazendo o aux1 apontar para o primeiro elemento da lista
			aux1 = *L;
		
			//fazer o L apontar para o "segundo" elemento da lçista
			*L = aux1->prox;     //*L = (*L)->prox;
		
			//liberando a memória do nó apontado por 'aux1'
			free (aux1);
		
			//atualizando o número de remoções realizadas
			cont++;
		}
	
		//verificando se ainda há elementos na lista
		if (*L)
		{
			//colocando os auxiliares 'aux2' e 'aux1' no primeiro e segundo nós, respectivamente
			aux2 = *L;
			aux1 = (*L)->prox;	
			
			//percorrendo a lista com 'aux1'
			while (aux1)
			{
				//verificando se o 'aux1' está apontando para 'numero'
				if (aux1->valor == numero)
				{
					//removendo o valor apontado por 'aux1'
					aux2->prox = aux1->prox;
				
					//removendo o nó que guarda o 'numero'
					free (aux1);
					cont++;
				
					//fazendo 'aux1' apontar para o próximo elemento da lista
					aux1 = aux2->prox;				
				}
				else
				{
					//andando com os dois auxiliares
					aux2 = aux1;
					aux1 = aux1->prox;
				}
			}
		}
	}
	
	//retornando a quantidade de remoções realizadas
	return cont;
}
