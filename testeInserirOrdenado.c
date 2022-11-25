//Importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Definição de constantes
#define TRUE 1
#define FALSE 0

//Declaração de tipos
//Criamos um nome provisório 'No' para o struct 'TNo', para que possamos manipular o struct.
typedef struct No{
	int valor; //Vale lembrar que é 'int' porque se trata de uma lista de inteiros. Pode ser float, string, struct...
	struct No* prox; //? um ponteiro para um struct, neste caso para um igual ao criado.
}TNo;

typedef TNo* TLista; //TLista é um ponteiro para TNo

//prototipo das funções
int menu ();
int inserirOrdenado(TLista *L, int numero);
void exibirLista (TLista L);
int buscar (TLista L, int numero);

//main
void main ()
{
	//Declaração de variáveis
	TLista L = NULL;
	int op, num1;
	
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
					
			//Saída
			case 3: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 3);
}

//implementação das demais funções
int inserirOrdenado(TLista *L, int numero)
{
   //declaração de variáveis
	TLista aux, temp;
   	
   	//verificando se o valor já existe na lista
	if (buscar (*L, numero) == TRUE)
	{
		return FALSE; //essa aqui é a parte q ele verifica se o número ja existe na lista. se existir, ele retorna falso e nao insere
	}
	else
	{
		//verificando se a memória foi alocada
		if (aux == NULL)
		{
			return FALSE;
		}
		else
		{
			aux = (TLista) malloc (sizeof(TNo));
 			temp = (TLista) malloc (sizeof(TNo));
 			
  	        aux->valor = numero;
	       	
			// a lista está vazia?
	       	if(*L == NULL)
			{
	        	aux->prox = NULL;
	        	
	            *L = aux;
	            
	            return TRUE;
	        }
					 
			// é o menor?
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
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Exibir\n");
	printf ("(3) Sair\n\n");
	
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
	}
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
