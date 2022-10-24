/* Considere um vetor que armazene alguns dados coletados de um grupo de pessoas em uma pesquisa,
a saber: nome, g�nero, idade e altura.

Desenvolver uma fun��o que receba os par�metros g�nero, faixa de idade (idade inicial e idade final) e
faixa de altura (altura inferior e altura superior) e retorne a quantidade de pessoas que atendem aos 
filtros por ele representados.

Nota: caso o g�nero especificado seja igual a M, ser�o considerados os homens que estiverem nas faixas de
idade e altura especificadas; o mesmo ocorrer� com as mulheres, quando o g�nero for F. Por�m, se o g�nero
contiver qualquer valor diferente de M ou F, todas as pessoas que atenderem aos filtros de idade e altura
ser�o contabilizadas.*/

//Importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//Defini��o de constantes
#define TAM 5

//Defini��o de tipos
typedef struct {
	char nome [20];
	char genero;
	int idade;
	float altura;
}TPesquisa;

//Prot�tipo das fun��es
void preencherStruct (TPesquisa Pes[], int quant);
int funcao (TPesquisa Pes[], int quant, char gen, int IdadeIni, int IdadeFinal, float alturaInf, float alturaSup); 

//Main
void main ()
{
	//Delcara��o de vari�veis
	TPesquisa Pessoa[TAM];
	char gene;
	int IdadeIn, IdadeFi, resposta;
	float alturaIn, alturaSu;
	
	//Preenchendo o Struct
	preencherStruct (Pessoa, TAM);
	
	fflush (stdin);
	system("pause");
	
	printf ("\n\nEntre com o genero a ser buscado: ");
	scanf ("%c", &gene);
	
	printf ("\nEntre com o primeiro valor do intervalo de Idade: ");
	scanf ("%d", &IdadeIn);
	
	printf ("\nEntre com o segundo valor do intervalo de Idade: ");
	scanf ("%d", &IdadeFi);
	
	printf ("\nEntre com o primeiro valor do intervalo de altura: ");
	scanf ("%f", &alturaIn);
	
	printf ("\nEntre com o primeiro valor do intervalo de altura: ");
	scanf ("%f", &alturaSu);
	
	//Chamando  a fun��o
	resposta = funcao (Pessoa, TAM, gene, IdadeIn, IdadeFi, alturaIn, alturaSu);
	
	printf ("\nO numero de pessoas do genero %c com a idade entre %d e %d e altura entre %.2f e %.2f e: %d", gene, IdadeIn, IdadeFi, alturaIn, alturaSu, resposta);
}

//Implementa��o das demais fun��es
void preencherStruct (TPesquisa Pes[], int quant)
{
	//Declara��o de vari�veis
	int i;
	
	//Percorrendo o vetor
	for (i=0; i<quant; i++)
	{
		fflush (stdin);
		printf ("\nEntre com o nome da pessoa: ");
		gets (Pes[i].nome);
		
		printf ("\nEntre com o genero da pessoa (M/F): ");
		scanf ("%c", &Pes[i].genero);
		
		printf ("\nEntre com idade da pessoa: ");
		scanf ("%d", &Pes[i].idade);
		
		printf ("\nEntre com altura da pessoa: ");
		scanf ("%f", &Pes[i].altura);	
	}
}

/*Nota: caso o g�nero especificado seja igual a M, ser�o considerados os homens que estiverem nas faixas de
idade e altura especificadas; o mesmo ocorrer� com as mulheres, quando o g�nero for F. Por�m, se o g�nero
contiver qualquer valor diferente de M ou F, todas as pessoas que atenderem aos filtros de idade e altura
ser�o contabilizadas.*/
int funcao (TPesquisa Pes[], int quant, char gen, int IdadeIni, int IdadeFinal, float alturaInf, float alturaSup)
{
	//Declara��o de vari�veis
	int i, cont=0;
	char busca[5];
	
	switch (gen) 
	{
		case 'M': //strcpy(busca, gen); //copiando o caracter 'gen' para a string busca
		
		for (i=0; i<quant; i++)
		{
			if (Pes[i].genero == gen)
			{
				if ((Pes[i].idade >= IdadeIni) && (Pes[i].idade <=IdadeFinal) && (Pes[i].altura >= alturaInf) && (Pes[i].altura <= alturaSup))//Verificando o numero de pessoas que est�o entre o intervalo de idade e altura
				{
					cont++;
				}
			}
		 } 
			break;
		
		case 'F': //strcpy(busca, gen); //copiando o caracter 'gen' para a string busca
		
		for (i=0; i<quant; i++)
		{
			if (Pes[i].genero == gen)
			{
				if ((Pes[i].idade >= IdadeIni) && (Pes[i].idade <=IdadeFinal) && (Pes[i].altura >= alturaInf) && (Pes[i].altura <= alturaSup))//Verificando o numero de pessoas que est�o entre o intervalo de idade e altura
				{
					cont++;
				}
			}
		 } 
			break;
			
		default:
			for (i=0; i<quant; i++)
		{
			if ((Pes[i].idade >= IdadeIni) && (Pes[i].idade <=IdadeFinal) && (Pes[i].altura >= alturaInf) && (Pes[i].altura <= alturaSup))//Verificando o numero de pessoas que est�o entre o intervalo de idade e altura
				{
					cont++;
				}
		} 
			break;
	}
	return cont;
}
