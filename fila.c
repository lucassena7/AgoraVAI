/*
	FAETERJ-Rio
	Fundamentos de Programa��o - FPR
	2022/2  -  Turma: Manh�
	
	Data: 23/11/2022
	
	Filas (atrav�s de listas encadeadas)
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
int enfilar (TLista *F, TLista *U, int numero);
int desenfilar (TLista *F, TLista *U, int *numero);
int primeiro (TLista F, int *p);

int menu ();

//main 
void main ()
{
	//declara��o de vari�veis
	TLista F = NULL, U = NULL;
	int num, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usu�rio
		op = menu ();
		
		//verificando a op��o escolhida
		switch (op)
		{
			//Enfilar
			case 1: printf ("\nEntre com o valor a ser enfilado: ");
			        scanf ("%d", &num);
			        
			        //chamando a fun��o
			        if (enfilar (&F, &U, num) == TRUE)
			        {
			        	printf ("\n\tElemento enfilado com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: elemento nao enfilado!");
					}
					break;

			//Desenfilar
			case 2: //chamando a fun��o
			        if (desenfilar (&F, &U, &num) == TRUE)
			        {
			        	printf ("\n\tO valor %d foi desenfilado!", num);
					}
					else
					{
						printf ("\n\tERRO: fila vazia!");
					}
					break;

			//Primeiro
			case 3: if (primeiro (F, &num) == TRUE)
			        {
			        	printf ("\n\tPrimeiro elemento da fila: %d", num);
					}
					else
					{
						printf ("\n\tERRO: fila vazia!");
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
int enfilar (TLista *F, TLista *U, int numero)
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
		
		//3� passo: fazer com que o campo 'prox' do novo n� aponte para NULL
		aux->prox = NULL;
		
		if (*U)
		{
			//4� passo: fazer o "antigo �ltimo n�" apontar para o novo n�
			(*U)->prox = aux;
		}
		else
		{
			//Fazer o 'F' apontar para o novo n� (que � o primeiro da fila)
			*F = aux;
		}
	
		//5� passo: fazer o 'U' apontar para o novo n�
		*U = aux;
		
		return TRUE;
	}	
}

int desenfilar (TLista *F, TLista *U, int *numero)
{
	//declara��o de vari�veis
	TLista aux;
	
	//verificando se a fila est� vazia
	if (!(*F))
	{
		return FALSE;
	}
	else
	{
		//verificando se a lista possui apenas um n�
		if (*F == *U)
		{
			*U = NULL;
		}
		
		//fazer o 'aux' apontar para o primeiro elemento da fila
		aux = *F;
		
		//atualizando o F, uma vez que o primeiro ser� removido	
		*F = aux->prox;   //ou   *F = (*F)->prox
		
		/*
		if (*F == NULL)
		{
			*U = NULL;
		}	
		*/
		
		//armazenando em 'numero' o valor sendo removido
		*numero = aux->valor;
		
		//liberando o n� sendo removido
		free (aux);
		
		return TRUE;
	}
}

int primeiro (TLista F, int *p)
{
	//verificando se a fila est� vazia
	//if (F == NULL)
	if (!F)
	{
		return FALSE;
	}
	else
	{
		//armazenando em 'p' o primeiro valor da fila
		*p = F->valor;
		
		return TRUE;
	}
}

int menu ()
{
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Enfilar\n");
	printf ("(2) Desenfilar\n");
	printf ("(3) Primeiro\n");
	printf ("(4) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}
