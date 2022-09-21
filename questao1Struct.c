/*
	FPR - Professor Leonardo Vianna
	Turma: Manh�
	Data: 20/04/2022
	
	Lista de Exerc�cios	VI
	
	Quest�o 01:
	Uma loja de autom�veis mant�m os carros � venda sob a forma de um vetor de structs 
	contendo as seguintes informa��es, para cada ve�culo: placa, modelo, marca, cor, 
	quilometragem, ano modelo/fabrica��o (deve ser um struct), valor e tipo (usado ou 0 km, 
	conforme o valor do campo quilometragem). 

	Pede-se a declara��o de uma vari�vel que represente o estoque de ve�culos da loja, 
	incluindo todas as declara��es de tipos que possam ser necess�rias.

	Al�m disso, implementar as seguintes fun��es: 
		i.	Exibir todos os carros do modelo m, ano de fabrica��o entre a1 e a2 (inclusive), 
		    com valor n�o superior a x reais;
		ii.	Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5%;
		iii.Retirar do estoque um determinado ve�culo, dada a sua placa.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0
#define NUM_CARROS 5

//declara��o de tipos
typedef struct {
	int fabricacao;
	int modelo;
}TAno;

typedef struct {
	char placa [20];
	char modelo [20];
	char marca [20];
	char cor [20];
	float km;
	TAno ano;
	float valor;
	char tipo[6];
} TCarro;

//Prot�tipo das fun��es
void buscarCarros (TCarro agencia [], int quant, char m[], int a1, int a2, float x);
void exibirDadosCarros(TCarro carro);
void reajustar0km (TCarro agencia[], int quant);

//main
void main ()
{
	
}

//Implementa��o das demais fun��es
void buscarCarros (TCarro agencia [], int quant, char m[], int a1, int a2, float x)
{
	//Declara��o de vari�veis
	int i, cont=0;
	
	for (i=0; i<quant; i++)
	{
		if ((strcmp (m, agencia[i].modelo) == 0) && (agencia[i].ano.fabricacao >= a1) && (agencia[i].ano.fabricacao <= a2) && (agencia[i].valor <= x))
		{
			exibirDadosCarros (agencia[i]);
			cont++;
		}
	}
	if (cont == 0)
	{
		printf ("Nenhum carro que atenda essas condi��es foi encontrado.");
	}
}

void exibirDadosCarros(TCarro carro)
{
	printf ("Placa: %s\n", carro.placa);
	printf ("Marca/Modelo: %s %s\n", carro.marca, carro.modelo);
	printf ("Cor: %s\n", carro.cor);
	printf ("Quilometragem: %.1f\n", carro.km);
	printf ("Ano-Fabricacao/Modelo: %d %d\n", carro.ano.fabricacao, carro.ano.modelo);
	printf ("Valor: R$ %2.f\n", carro.valor);
	printf ("Tipo: %s\n", carro.tipo);
}

void reajustar0km (TCarro agencia[], int quant)
{
	//Declara��o de vari�veis
	int i;
	
	for (i=0; i<quant; i++)
	{
		//if (agencia[i].km == 0) ou
		if (strcmp (agencia[i].tipo, "0KM") == 0)
		{
			agencia[i].valor = agencia[i].valor + 0.025*agencia[i].valor;
		}
	}
}
