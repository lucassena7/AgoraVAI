/* Implementar uma função que, dadas duas listas dinâmicas do tipo TLista, verifique se elas
possuem os mesmos elementos, independente da ordem na qual apareçam. */

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
int criarCopia (TLista L1, TLista *L2);

void main ()
{
	//Declaração de variáveis
	TLista l1 = NULL;
	TLista l2 = NULL;
	int op, num1, resp;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Inserção na lista 1
			case 1: printf ("\nEntre com o valor a ser inserido na lista 1: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        if (inserir (&l1, num1) == TRUE)
			        {
			        	printf ("\n\tInsercao na lista 1 realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;
			
			//Exibir elementos da lista 1
			case 2: printf ("\nElementos da lista 1: ");
					exibir (l1);
					break;
			
			case 3: if (criarCopia (l1, &l2) == TRUE)
			        {
			        	printf ("\n\tCopia realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: Copia nao realizada!");
					}
			
			//Exibir
			case 4: printf ("\nElementos da lista 2: ");
					exibir (l2);
					break;
					
			//Saída
			case 5: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 5);
}

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir na lista 1\n");
	printf ("(2) Exibir elementos da lista 1\n");
	printf ("(3) Criar uma copia da lista 1\n");
	printf ("(4) Exibir elementos da lista 2\n");
	printf ("(5) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

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

int criarCopia (TLista L1, TLista *L2)
{
	//declaração de variáveis
	TLista aux1 = L1; //aux1 percorrerá a lista 1
	 TLista aux2 = NULL; //aux 2 iniciará como NULL uma vez que a lista está vazia
	 TLista novo; //Será o novo nó a ser alocado na *L2
	
	while (aux1) //Enquanto aux1 for diferente de NULL
	{
		//alocando memória para o novo nó a ser inserido
		novo = (TLista) malloc (sizeof(TNo));
		
		//verificando se houve erro na alocação de memória
		if (novo == NULL)
		{
			return FALSE;
		}
		else
		{
			//armazenando os dados no novo nó a ser inserido
			novo->valor = aux1->valor;
			novo->prox = NULL;
		
			if (*L2 == NULL) //Verificando se l2 está vazia
			{
				//Se tiver, insira no início
				*L2 = novo; //L2 apontará para o 'primeiro' nó a ser inserido na nova lista
				aux2 = novo; //aux2 percorrerá a lista 2
			}
			else
			{
				aux2->prox = novo; //inserindo o novo nó na lista após o elemento anterior
				aux2 = aux2->prox; //atualizando o valor de aux2 que percorrerá a lista
			}
		}
		aux1 = aux1->prox; //andando com o aux1 para percorrer a lista1 toda
	}
	return TRUE;
}
