/* Implementar uma função que, dadas duas listas dinâmicas do tipo TLista, verifique se estas são iguais; 
isto é, contêm os mesmos elementos, na mesma ordem.

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
int verificarIguais (TLista L1, TLista L2);

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
			
			//Inserção na lsita 2
			case 2: printf ("\nEntre com o valor a ser inserido na lista 2: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        if (inserir (&l2, num1) == TRUE)
			        {
			        	printf ("\n\tInsercao na lista 2 realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Exibir elementos da lista 1
			case 3: printf ("\nElementos da lista 1: ");
					exibir (l1);
					break;
			
			//Exibir
			case 4: printf ("\nElementos da lista 2: ");
					exibir (l2);
					break;
					
			//Verificar elementos distintos
			case 5: resp = verificarIguais (l1, l2);
					
					if (resp == TRUE)
					{
						printf ("\n\tAs listas sao iguais !.");
					}
					else
					{
						printf ("\n\tAs listas NAO sao iguais !.");
					}
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

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir na lista 1\n");
	printf ("(2) Inserir na lista 2\n");
	printf ("(3) Exibir elementos da lista 1\n");
	printf ("(4) Exibir elementos da lista 2\n");
	printf ("(5) Verificar se as listas sao iguais\n");
	printf ("(6) Sair\n\n");
	
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

int verificarIguais (TLista L1, TLista L2)
{
	//Declaração de variáveis
	TLista aux1 = L1; //Aux1 aponta para o primeiro nó da lista 1
	TLista aux2 = L2; //Aux2 aponta para o primeiro nó da lista 2
	
	//percorrendo enquanto existirem elementos nas listas
	while (aux1 && aux2)
	{
		if (aux1->valor != aux2->valor) //caso os elementos sejam diferentes
		{
			return FALSE; //retornando falso
		}
		else
		{
			//andando com as listas
			aux1=aux1->prox;
			aux2=aux2->prox;
		}
	}
	//Verificando se as duas listas chegaram ao fim
	if (!aux1 && !aux2)
	{
		return TRUE; //retornando TRUE, uma vez que as listas chegaram ao final juntas com os mesmos elementos nas mesmas posições
	}
	else
	{
		return FALSE;
	}
}
