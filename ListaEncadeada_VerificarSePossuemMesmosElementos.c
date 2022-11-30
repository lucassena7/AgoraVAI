/*
QUESTÃO 05:
Implementar uma função que, dadas duas listas dinâmicas do tipo TLista, verifique se elas possuem os 
mesmos elementos, independente da ordem na qual apareçam.


	Exemplos:
	
		L1:		1 2 3 4	
		L2:		4 1 2 3		SIM
				
				
		L1:		1 2 3	
		L2:		4 1 2 3		NÃO
		
		
		L1:		1 2 3 4	
		L2:		4 1 2 3 1 2 3	SIM

*/

TLista buscar (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux = L;
	
	//percorrendo a lista até o seu final
	while (aux != NULL)
	{
		//testando se é o valor sendo buscado
		if (aux->valor == numero)
		{
			//retornando o endereço do nó que contém o valor buscado
			return aux;
		}
			
		//atualizando o 'aux' para apontar para o próximo nó
		aux = aux->prox;
	}
	
	//se chegou a este ponto, o número buscado não existe
	return NULL;	
}

int estaContida (TLista L1, TLista L2)
{
	//declaração de variáveis
	TLista aux;
	
	//inicializando 'aux' com o endereço do primeiro nó de 'L1'
	aux = L1;
	
	//percorrendo 'L1' com 'aux'
	while (aux)
	{
		//buscando cada elemento de 'L1' em 'L2'
		if (buscar (L2, aux->valor) == NULL)
		{
			return FALSE;
		}
		
		//atualizando 'aux'
		aux = aux->prox;
	}
	
	//se chegou aqui, todos os elementos de 'L1' foram encontrados em 'L2'
	return TRUE;
}

int verificarMesmosElementos (TLista lista1, TLista lista2)
{
	/*
	if ((estaContida (lista1, lista2) == TRUE) && (estaContida (lista2, lista1) == TRUE)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
	*/
	
	return estaContida (lista1, lista2) && estaContida (lista2, lista1);
}
