/* Desenvolver uma função que calcule o n-ésimo termo da sequência de Fibonacci. 
					
					1  1  2  3  5  8  13  21  ...
					a  b  c													*/

//Importação de bibliotecas
#include <stdio.h>

//Protótipo das funções
int fibonacci (int num);

//Main
void main ()
{
	//Declaração de variáveis
	int num, resposta;
	
	//Entre com o n-ésimo termo da sequência de fibonnacci
	printf ("Entre com o n-esimo termo da sequencia de fibonnacci");
	scanf("%d", &num);
	
	resposta = fibonacci (num);
	
	printf ("O n-esimo termo da sequencia de fibonacci e: %d", resposta);
}

//Implementação das demais funções
int fibonacci (int num)
{
	//Declaração de variáveis
	int a, b, c, i;
	
	//Se n for igual ao primeiro e ao segundo termo, fibonacci será igual a 1
	if ((num == 1) || (num == 2))
	{
		return 1;
	}
	
	//Se n for >= 3, fibonacci será a soma dos dois elementos anteriores
	//'a' e 'b' são os primeiros 2 termos da sequencia de fibonacci, por este motivo iniciarão em 1.
	a=1;
	b=1;
	
	//iniciando um for a partir do 3° termo da sequencia em busca do n-ésimo termo de fibonacci
	for (i=3; i<=num; i++)
	{
		c = a + b; //c será a soma dos dois elementos anteriores
		
		a = b; //atualizando o valor de a
		b = c; // atualizando o valor de b
	}
	//retornando o n-ésimo termo da sequência de fibonacci
	return c;
}
