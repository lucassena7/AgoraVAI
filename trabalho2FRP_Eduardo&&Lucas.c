/* 			
										Trabalho 2 - FPR

Considerando as implementações de listas encadeadas feitas em aula, apresentar o código das funções de
inserção, remoção, alteração, busca e exibição para uma lista cujos elementos estejam ordenados crescentemente,
além de permitir repetição de valores.

Alunos: Mano Edu
		Lucas Miguel de Sena Costa																			*/
		
//importação de bibliotecas
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

//declaração dos protótipos das funções
int inserirOrdenado(TLista *L, int numero);
int remover (TLista *L, int numero);
int alterar (TLista L, int velho, int novo);
int buscar (TLista L, int numero);
void exibir (TLista L);
int menu ();

//main 
void main ()
{
	//declaração de variáveis
	TLista L = NULL;
	int num1, num2, op, quant, resp;
	
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

			//Remoção
			case 2: printf ("\nEntre com o valor a ser removido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        quant = remover (&L, num1);
			        
					if (quant == -1)
			        {
			        	printf ("\n\t%d Nao e possivel remover um elemento pois a lista esta vazia !.!");
					}
					else
					{
						if (quant == 0)
						{
							printf ("\n\tO numero %d nao existe na lista !.", num1);
						}
						else
						{
							printf ("\n\t%d remocoes realizadas do numero %d!", quant, num1);
						}
					}
					break;

			//Alteração
			case 3: printf ("\nEntre com o valor a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("\nEntre com o novo valor: ");
			        scanf ("%d", &num2);
			        
			        //chamando a função
			        quant = alterar (L, num1, num2);
			        
			        if (quant > 0)
			        {
			        	printf ("\n\t%d alteracoes realizadas!", quant);
					}
					else
					{
						printf ("\n\tERRO: alteracao nao realizada!");
					}
					break;

			//Busca
			case 4: printf ("\nEntre com o valor a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        resp = buscar (L, num1);
			        
					if (resp == TRUE)
			        {
			        	printf ("\n\tO valor %d foi encontrado na lista!", num1);
					}
					else
					{
						printf ("\n\tO valor %d NAO foi encontrado na lista!", num1);
					}
					break;

			//Exibir
			case 5: exibir (L);
					break;
					
			//Saída
			case 6: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 6);
}

//Implementação das demais funções
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

int alterar (TLista L, int velho, int novo)
{
	//declaração de variáveis
	TLista aux = L;
	int cont = 0;
	
	//percorrendo toda a lista
	while (aux != NULL)
	{
		//verificando se o elemento 'velho' foi encontrado
		if (aux->valor == velho)
		{
			//alterando o 'velho' pelo 'novo'
			aux->valor = novo;
			
			//atualizando o número de atualizações realizadas
			cont++;
		}
		
		//fazendo o aux apontar para o próximo nó da lista
		aux = aux->prox;		
	}
	
	//retornando a quantidade de alterações realizadas
	return cont;
}

int buscar (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux = L;
	
	//percorrendo a lista até o seu final
	while (aux != NULL)
	{
		//testando se é o valor sendo buscado
		if (aux->valor == numero)
		{
			return TRUE;
		}
			
		//atualizando o 'aux' para apontar para o próximo nó
		aux = aux->prox;
	}
	
	//se chegou a este ponto, o número buscado não existe
	return FALSE;	
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
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}
