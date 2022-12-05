/* 			
										Trabalho 2 - FPR

Considerando as implementa��es de listas encadeadas feitas em aula, apresentar o c�digo das fun��es de
inser��o, remo��o, altera��o, busca e exibi��o para uma lista cujos elementos estejam ordenados crescentemente,
al�m de permitir repeti��o de valores.

Alunos: Mano Edu
		Lucas Miguel de Sena Costa																			*/
		
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
int inserirOrdenado(TLista *L, int numero);
int remover (TLista *L, int numero);
int alterar (TLista L, int velho, int novo);
int buscar (TLista L, int numero);
void exibir (TLista L);
int menu ();

//main 
void main ()
{
	//declara��o de vari�veis
	TLista L = NULL;
	int num1, num2, op, quant, resp;
	
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

			//Remo��o
			case 2: printf ("\nEntre com o valor a ser removido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
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

			//Altera��o
			case 3: printf ("\nEntre com o valor a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("\nEntre com o novo valor: ");
			        scanf ("%d", &num2);
			        
			        //chamando a fun��o
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
			        
			        //chamando a fun��o
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
					
			//Sa�da
			case 6: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 6);
}

//Implementa��o das demais fun��es
int inserirOrdenado(TLista *L, int numero)
{
	//Declara��o de vari�veis
	TLista novo; //Vai ser o 'novo' n� a ser alocado
	TLista ant = NULL; //Vai ser o n� que armazenar� as informa��es do n� 'anterior'
	TLista aux = *L; //Aux vai ser o n� corrente
	
	//1� passo: alocar mem�ria para o novo n�
	novo = (TLista) malloc (sizeof(TNo));
	
	//verificando se a mem�ria foi alocada
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
		
		//armazenando o 'numero' na posi��o valor do 'novo' n�
		novo->valor = numero;
		
  		// aux � o no corrent. Enquanto a lista n�o estiver vazia e o valor do n� corrente for menor que o n�mero a ser inserido
  		while ((aux != NULL) && (aux->valor < numero))  // caso lista nao vazia
		{
    		ant = aux;       // andando na lista
    		aux = aux->prox; // andando na lista
  		}

  		if (ant == NULL) // Se a lista estiver vazia. Insiro no in�cio
		{
			//Fazendo o prox do novo n� apontar para onde a lista aponta
    		novo->prox = *L;
			
			//Fazendo a lista apontar para o 'novo' n�
    		*L = novo;
  		}
		else // todos os outros casos. Inserir no meio e no final
		{
			//Fazendo o prox do 'novo' n� apontar para onde o prox do anterior aponta
    		novo->prox = ant->prox;
    		
    		//Fazendo o prox do anterior apontar para o 'novo' n�
    		ant->prox = novo;
  		}
	}
	//Se chegou aqui � pq o n�mero foi inserido. Retornando TRUE
	return TRUE;
}

int remover (TLista *L, int numero)
{
	//declara��o de vari�veis
	TLista aux1, aux2;
	int cont = 0;
	
	if (!(*L))
	{
		return -1;
	}
	else
	{
		//verificando se o primeiro elemento da lista � o n�mero que deseja-se remover
		while ((*L) && ((*L)->valor == numero))
		{
			//fazendo o aux1 apontar para o primeiro elemento da lista
			aux1 = *L;
		
			//fazer o L apontar para o "segundo" elemento da l�ista
			*L = aux1->prox;     //*L = (*L)->prox;
		
			//liberando a mem�ria do n� apontado por 'aux1'
			free (aux1);
		
			//atualizando o n�mero de remo��es realizadas
			cont++;
		}
	
		//verificando se ainda h� elementos na lista
		if (*L)
		{
			//colocando os auxiliares 'aux2' e 'aux1' no primeiro e segundo n�s, respectivamente
			aux2 = *L;
			aux1 = (*L)->prox;	
			
			//percorrendo a lista com 'aux1'
			while (aux1)
			{
				//verificando se o 'aux1' est� apontando para 'numero'
				if (aux1->valor == numero)
				{
					//removendo o valor apontado por 'aux1'
					aux2->prox = aux1->prox;
				
					//removendo o n� que guarda o 'numero'
					free (aux1);
					cont++;
				
					//fazendo 'aux1' apontar para o pr�ximo elemento da lista
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
	//retornando a quantidade de remo��es realizadas
	return cont;
}

int alterar (TLista L, int velho, int novo)
{
	//declara��o de vari�veis
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
			
			//atualizando o n�mero de atualiza��es realizadas
			cont++;
		}
		
		//fazendo o aux apontar para o pr�ximo n� da lista
		aux = aux->prox;		
	}
	
	//retornando a quantidade de altera��es realizadas
	return cont;
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
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}
