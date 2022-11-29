/*
	FAETERJ-Rio
	Fundamentos de Programa��o - FPR
	2022/2  -  Turma: Manh�
	
	Data: 17/11/2022
	
	Pilhas (atrav�s de listas encadeadas)
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//defini��o de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//declara��o dos prot�tipos das fun��es
int empilhar (TLista *P, int numero);
int desempilhar (TLista *P, int *numero);
int topo (TLista P, int *t);

int menu ();

//main 
void main ()
{
	//declara��o de vari�veis
	TLista P = NULL;
	int num, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usu�rio
		op = menu ();
		
		//verificando a op��o escolhida
		switch (op)
		{
			//Empilhar
			case 1: printf ("\nEntre com o valor a ser empilhado: ");
			        scanf ("%d", &num);
			        
			        //chamando a fun��o
			        if (empilhar (&P, num) == TRUE)
			        {
			        	printf ("\n\tElemento empilhado com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: elemento nao empilhado!");
					}
					break;

			//Desempilhar
			case 2: //chamando a fun��o
			        if (desempilhar (&P, &num) == TRUE)
			        {
			        	printf ("\n\tO valor %d foi desempilhado!", num);
					}
					else
					{
						printf ("\n\tERRO: pilha vazia!");
					}
					break;

			//Topo
			case 3: if (topo (P, &num) == TRUE)
			        {
			        	printf ("\n\tTopo da pilha: %d", num);
					}
					else
					{
						printf ("\n\tERRO: pilha vazia!");
					}
			
			//Sa�da
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 4);
}

//implementa��o das fun��es
int empilhar (TLista *P, int numero)
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
		//"at� ent�o" topo da pilha
		aux->prox = *P;
		
		//4� passo: fazer com que P aponte para o novo n�
		*P = aux;
		
		return TRUE;
	}	
}

int desempilhar (TLista *P, int *numero)
{
	//declara��o de vari�veis
	TLista aux;
	
	//verificando se a pilha est� vazia
	if (!(*P))
	{
		return FALSE;
	}
	else
	{
		//fazer o 'aux' apontar para o topo da pilha
		aux = *P;
		
		//atualizando o P, uma vez que o topo ser� removido	
		*P = aux->prox;   //ou   *P = (*P)->prox
		
		//armazenando em 'numero' o valor sendo removido
		*numero = aux->valor;
		
		//liberando o n� sendo removido
		free (aux);
		
		return TRUE;
	}
}

int topo (TLista P, int *t)
{
	//verificando se a pilha est� vazia
	//if (P == NULL)
	if (!P)
	{
		return FALSE;
	}
	else
	{
		//armazenando em 't' o valor que encontra-se no topo da pilha
		*t = P->valor;
		
		return TRUE;
	}
}

int menu ()
{
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Empilhar\n");
	printf ("(2) Desempilhar\n");
	printf ("(3) Topo\n");
	printf ("(4) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}
