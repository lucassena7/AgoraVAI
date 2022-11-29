/* Implementar uma fun��o que, dadas duas listas din�micas do tipo TLista, verifique se estas s�o iguais; 
isto �, cont�m os mesmos elementos, na mesma ordem.

Lucas Miguel de Sena Costa */

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//defini��o de constantes
#define TAM 7
#define TRUE 1
#define FALSE 0

//Declara��o de tipos
//Criamos um nome provis�rio 'No' para o struct 'TNo', para que possamos manipular o struct.
typedef struct No{
	int valor; //Vale lembrar que � 'int' porque se trata de uma lista de inteiros. Pode ser float, string, struct...
	struct No* prox; //? um ponteiro para um struct, neste caso para um igual ao criado.
}TNo;

typedef TNo* TLista; //TLista � um ponteiro para TNo

//prot�tipos/cabe�alhos das fun��es
int inserir (TLista *L, int numero);
void exibir (TLista L); //N�o precisamos colocar o ponteiro pois s� iremos percorrer a lista
int verificarIguais (TLista L1, TLista L2);

void main ()
{
	//Declara��o de vari�veis
	TLista l1 = NULL;
	TLista l2 = NULL;
	int op, num1, resp;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usu�rio
		op = menu ();
		
		//verificando a op��o escolhida
		switch (op)
		{
			//Inser��o na lista 1
			case 1: printf ("\nEntre com o valor a ser inserido na lista 1: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
			        if (inserir (&l1, num1) == TRUE)
			        {
			        	printf ("\n\tInsercao na lista 1 realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;
			
			//Inser��o na lsita 2
			case 2: printf ("\nEntre com o valor a ser inserido na lista 2: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
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
					
			//Sa�da
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
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir na lista 1\n");
	printf ("(2) Inserir na lista 2\n");
	printf ("(3) Exibir elementos da lista 1\n");
	printf ("(4) Exibir elementos da lista 2\n");
	printf ("(5) Verificar se as listas sao iguais\n");
	printf ("(6) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}

int inserir (TLista *L, int numero)
{
	//declara��o de vari�veis;
	TLista aux;
	
	//1� passo: alocar mem�ria para o novo n�	
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se houve erro na aloca��o de mem�ria
	if (aux == NULL)
	{
		return FALSE;
	}
	else
	{
		//2� passo: armazenar 'numero' na mem�ria rec�m-alocada
		aux->valor = numero;
		
		//3� passo: mandar o campo 'prox' do novo n� apontar para o 
		//"at� ent�o" primeiro elemento	da lista
		aux->prox = *L;
		
		//4� passo: fazer com que L aponte para o novo n� da lista		
		*L = aux;
		
		return TRUE;
	}	
}

void exibir (TLista L)
{
	//declara��o de vari�veis
	TLista aux = L;
	
	//testando se a lista est� vazia
	if (L == NULL)
	{
		printf ("\nLista vazia!");
	}
	else
	{		
		//percorrendo a lista at� o seu final
		while (aux != NULL)
		{
			//exibindo o valor apontado pelo 'aux'
			printf ("%d ", aux->valor);
			
			//atualizando o 'aux' para apontar para o pr�ximo n�
			aux = aux->prox;
		}
	}
}

int verificarIguais (TLista L1, TLista L2)
{
	//Declara��o de vari�veis
	TLista aux1 = L1; //Aux1 aponta para o primeiro n� da lista 1
	TLista aux2 = L2; //Aux2 aponta para o primeiro n� da lista 2
	
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
		return TRUE; //retornando TRUE, uma vez que as listas chegaram ao final juntas com os mesmos elementos nas mesmas posi��es
	}
	else
	{
		return FALSE;
	}
}
