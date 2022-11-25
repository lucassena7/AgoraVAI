//Importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Defini��o de constantes
#define TRUE 1
#define FALSE 0

//Declara��o de tipos
//Criamos um nome provis�rio 'No' para o struct 'TNo', para que possamos manipular o struct.
typedef struct No{
	int valor; //Vale lembrar que � 'int' porque se trata de uma lista de inteiros. Pode ser float, string, struct...
	struct No* prox; //? um ponteiro para um struct, neste caso para um igual ao criado.
}TNo;

typedef TNo* TLista; //TLista � um ponteiro para TNo

//prototipo das fun��es
int menu ();
int inserirOrdenado(TLista *L, int numero);
void exibirLista (TLista L);
int buscar (TLista L, int numero);

//main
void main ()
{
	//Declara��o de vari�veis
	TLista L = NULL;
	int op, num1;
	
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
					
			//Sa�da
			case 3: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 3);
}

//implementa��o das demais fun��es
int inserirOrdenado(TLista *L, int numero)
{
   //declara��o de vari�veis
	TLista aux, temp;
   	
   	//verificando se o valor j� existe na lista
	if (buscar (*L, numero) == TRUE)
	{
		return FALSE; //essa aqui � a parte q ele verifica se o n�mero ja existe na lista. se existir, ele retorna falso e nao insere
	}
	else
	{
		//verificando se a mem�ria foi alocada
		if (aux == NULL)
		{
			return FALSE;
		}
		else
		{
			aux = (TLista) malloc (sizeof(TNo));
 			temp = (TLista) malloc (sizeof(TNo));
 			
  	        aux->valor = numero;
	       	
			// a lista est� vazia?
	       	if(*L == NULL)
			{
	        	aux->prox = NULL;
	        	
	            *L = aux;
	            
	            return TRUE;
	        }
					 
			// � o menor?
	        else if(aux->valor < (*L)->valor)
			{
	            aux->prox = *L;
	            
	            *L = aux;
	            
	            return TRUE;
	        }
	        else
			{
	            temp = *L;
	            
	            while((temp->prox) && (aux->valor > temp->prox->valor))
	            {
		          	temp = temp->prox;
		            
		            aux->prox = temp->prox;
		            
		           	temp->prox = aux;
		            
		            return TRUE;
				}
	        }  
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
	printf ("(3) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}

void exibirLista (TLista L)
{
	//Declara��o de vari�veis
	TLista aux = L; //Fazendo 'aux' que � um ponteiro para TNo apontar para o primeiro n� da lista
	
	if (L == NULL) //Testando se a a lista est� vazia
	{
		printf ("Lista Vazia !.");
	}
	
	else
	{
		printf ("Lista: ");
		
		while (aux != NULL) //Enquanto aux for diferente de NULL
		{
			//Printando o valor da lista
			printf ("%d", aux->valor); //printa o que � apontado por aux
									//pode ser ("%d", (*aux).valor));
		
			//Atualizando o valor de aux
			aux = aux->prox; 
		}	
	}
}

int buscar (TLista L, int numero)
{
	//declara��o de vari�veis
	TLista aux = L;
	
	//percorrendo a lista at� o seu final
	while (aux != NULL)
	{
		//testando se � o valor sendo buscado
		if (aux->valor == numero)
		{
			return TRUE;
		}
			
		//atualizando o 'aux' para apontar para o pr�ximo n�
		aux = aux->prox;
	}
	
	//se chegou a este ponto, o n�mero buscado n�o existe
	return FALSE;	
}
