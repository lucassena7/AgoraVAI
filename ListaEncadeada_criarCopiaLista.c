/* Implementar uma fun��o que, dadas duas listas din�micas do tipo TLista, verifique se elas
possuem os mesmos elementos, independente da ordem na qual apare�am. */

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
int criarCopia (TLista L1, TLista *L2);

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
					
			//Sa�da
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
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir na lista 1\n");
	printf ("(2) Exibir elementos da lista 1\n");
	printf ("(3) Criar uma copia da lista 1\n");
	printf ("(4) Exibir elementos da lista 2\n");
	printf ("(5) Sair\n\n");
	
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

int criarCopia (TLista L1, TLista *L2)
{
	//declara��o de vari�veis
	TLista aux1 = L1; //aux1 percorrer� a lista 1
	 TLista aux2 = NULL; //aux 2 iniciar� como NULL uma vez que a lista est� vazia
	 TLista novo; //Ser� o novo n� a ser alocado na *L2
	
	while (aux1) //Enquanto aux1 for diferente de NULL
	{
		//alocando mem�ria para o novo n� a ser inserido
		novo = (TLista) malloc (sizeof(TNo));
		
		//verificando se houve erro na aloca��o de mem�ria
		if (novo == NULL)
		{
			return FALSE;
		}
		else
		{
			//armazenando os dados no novo n� a ser inserido
			novo->valor = aux1->valor;
			novo->prox = NULL;
		
			if (*L2 == NULL) //Verificando se l2 est� vazia
			{
				//Se tiver, insira no in�cio
				*L2 = novo; //L2 apontar� para o 'primeiro' n� a ser inserido na nova lista
				aux2 = novo; //aux2 percorrer� a lista 2
			}
			else
			{
				aux2->prox = novo; //inserindo o novo n� na lista ap�s o elemento anterior
				aux2 = aux2->prox; //atualizando o valor de aux2 que percorrer� a lista
			}
		}
		aux1 = aux1->prox; //andando com o aux1 para percorrer a lista1 toda
	}
	return TRUE;
}
