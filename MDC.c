/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna
	Data: 22/08/2021
	
	Revisão - FAC   
	Fazer uma função que calcule o MDC (máximo divisor comum) entre dois números.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes

//protótipos/cabeçalhos das funções
int MDC (int numA, int numB);

//implementação da função main
void main ()
{
	//Declaração de variáveis
	int numA, numB, resposta;
	
	//Coletando os dados do usuário
	printf ("Entre com o primeiro numero: ");
	scanf("%d", &numA);
	
	printf ("Entre com o segundo numero: ");
	scanf("%d", &numB);
	
	resposta = MDC(numA, numB);
	
	printf ("O MDC entre %d e %d e: %d", numA, numB, resposta);
}

//implementação das demais funções
int MDC (int numA, int numB)
{
	//Declaração de variáveis
	int resto;
	
	if (numA > numB) //numA é maior que numB ?
	{
		while (numB) //Enquanto numB for diferente de 0
		{
			/* numA=16 e numB=12			numA=12 e numB=4		numA=4 e numB=0	
			   resto=16%12 -> resto=4		resto=12%4 -> resto=0	Sai do while, uma vez que numB=0
			*/
			resto = numA%numB; //'resto' recebe o resto da divisão de numA por numB
			numA = numB;
			numB = resto;
		}
		return numA; //Da return no MDC
	}
	else
	{
		if (numA < numB) //numA é menor que numB ?
		{
			while (numA) //Enquanto numA for diferente de 0
			{
				/* numA=12 e numB=16			numA=4 e numB=12		numA=0 e numB=4	
				   resto=16%12 -> resto=4		resto=12%4 -> resto=0	Sai do while, uma vez que numA=0
				*/
				resto = numB%numA; //'resto' recebe o resto da divisão de numB por numA
				numB = numA;
				numA = resto;
			}
			return numB; //Da return no MDC	
		}
	}
	return numA; //ou return numB, já que esse seria o caso se eles fossem iguais;
}
