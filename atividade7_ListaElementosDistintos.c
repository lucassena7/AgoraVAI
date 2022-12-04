/* Implementar uma fun��o que, dada uma lista encadeada L, do tipo TLista, determine se todos
os seus elementos s�o distintos.

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
int verificarElementosDistintos (TLista L);

//main
void main ()
{
	//Declara��o de vari�veis
	TLista L = NULL;
	int op, num1, resp;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usu�rio
		op = menu ();
		
		//verificando a op��o escolhida
		switch (op)
		{
			//Inser��o
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
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
					
			//Sa�da
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 4);
}

//Implementa��o das demais fun��es
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
		printf ("\nElementos da lista: ");
		
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

int menu ()
{
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Exibir\n");
	printf ("(3) Verificar se os elementos sao distintos\n");
	printf ("(4) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}

int verificarElementosDistintos (TLista L)
{
	//Declara��o de vari�veis
	TLista aux = L; //Aux aponta para o primeiro n� da lista
	TLista prox = L->prox; //Prox aponta para onde o L->prox aponta, ou seja, o prox elememento
	
	if (aux == NULL) //verificando se a lista est� vazia
	{
		return -1; //Retornando -1 para lista vazia
	}
	else
	{
		//percorrendo a lista at� o final
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
