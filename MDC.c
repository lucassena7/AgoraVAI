/*
	FPR - Fundamentos de Programa��o
	Professor Leonardo Vianna
	Data: 22/08/2021
	
	Revis�o - FAC   
	Fazer uma fun��o que calcule o MDC (m�ximo divisor comum) entre dois n�meros.
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes

//prot�tipos/cabe�alhos das fun��es
int MDC (int numA, int numB);

//implementa��o da fun��o main
void main ()
{
	//Declara��o de vari�veis
	int numA, numB, resposta;
	
	//Coletando os dados do usu�rio
	printf ("Entre com o primeiro numero: ");
	scanf("%d", &numA);
	
	printf ("Entre com o segundo numero: ");
	scanf("%d", &numB);
	
	resposta = MDC(numA, numB);
	
	printf ("O MDC entre %d e %d e: %d", numA, numB, resposta);
}

//implementa��o das demais fun��es
int MDC (int numA, int numB)
{
	//Declara��o de vari�veis
	int resto;
	
	if (numA > numB) //numA � maior que numB ?
	{
		while (numB) //Enquanto numB for diferente de 0
		{
			/* numA=16 e numB=12			numA=12 e numB=4		numA=4 e numB=0	
			   resto=16%12 -> resto=4		resto=12%4 -> resto=0	Sai do while, uma vez que numB=0
			*/
			resto = numA%numB; //'resto' recebe o resto da divis�o de numA por numB
			numA = numB;
			numB = resto;
		}
		return numA; //Da return no MDC
	}
	else
	{
		if (numA < numB) //numA � menor que numB ?
		{
			while (numA) //Enquanto numA for diferente de 0
			{
				/* numA=12 e numB=16			numA=4 e numB=12		numA=0 e numB=4	
				   resto=16%12 -> resto=4		resto=12%4 -> resto=0	Sai do while, uma vez que numA=0
				*/
				resto = numB%numA; //'resto' recebe o resto da divis�o de numB por numA
				numB = numA;
				numA = resto;
			}
			return numB; //Da return no MDC	
		}
	}
	return numA; //ou return numB, j� que esse seria o caso se eles fossem iguais;
}
