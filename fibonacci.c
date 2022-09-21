/* Desenvolver uma fun��o que calcule o n-�simo termo da sequ�ncia de Fibonacci. 
					
					1  1  2  3  5  8  13  21  ...
					a  b  c													*/

//Importa��o de bibliotecas
#include <stdio.h>

//Prot�tipo das fun��es
int fibonacci (int num);

//Main
void main ()
{
	//Declara��o de vari�veis
	int num, resposta;
	
	//Entre com o n-�simo termo da sequ�ncia de fibonnacci
	printf ("Entre com o n-esimo termo da sequencia de fibonnacci");
	scanf("%d", &num);
	
	resposta = fibonacci (num);
	
	printf ("O n-esimo termo da sequencia de fibonacci e: %d", resposta);
}

//Implementa��o das demais fun��es
int fibonacci (int num)
{
	//Declara��o de vari�veis
	int a, b, c, i;
	
	//Se n for igual ao primeiro e ao segundo termo, fibonacci ser� igual a 1
	if ((num == 1) || (num == 2))
	{
		return 1;
	}
	
	//Se n for >= 3, fibonacci ser� a soma dos dois elementos anteriores
	//'a' e 'b' s�o os primeiros 2 termos da sequencia de fibonacci, por este motivo iniciar�o em 1.
	a=1;
	b=1;
	
	//iniciando um for a partir do 3� termo da sequencia em busca do n-�simo termo de fibonacci
	for (i=3; i<=num; i++)
	{
		c = a + b; //c ser� a soma dos dois elementos anteriores
		
		a = b; //atualizando o valor de a
		b = c; // atualizando o valor de b
	}
	//retornando o n-�simo termo da sequ�ncia de fibonacci
	return c;
}
