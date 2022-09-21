/*
	FPR - Professor Leonardo Vianna
	Turma: Manhã
	Data: 20/04/2022
	
	Lista de Exercícios	VI
	
	Questão 01:
	Uma loja de automóveis mantém os carros à venda sob a forma de um vetor de structs 
	contendo as seguintes informações, para cada veículo: placa, modelo, marca, cor, 
	quilometragem, ano modelo/fabricação (deve ser um struct), valor e tipo (usado ou 0 km, 
	conforme o valor do campo quilometragem). 

	Pede-se a declaração de uma variável que represente o estoque de veículos da loja, 
	incluindo todas as declarações de tipos que possam ser necessárias.

	Além disso, implementar as seguintes funções: 
		i.	Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 (inclusive), 
		    com valor não superior a x reais;
		ii.	Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5%;
		iii.Retirar do estoque um determinado veículo, dada a sua placa.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0
#define NUM_CARROS 5

//declaração de tipos
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

//Protótipo das funções
void buscarCarros (TCarro agencia [], int quant, char m[], int a1, int a2, float x);
void exibirDadosCarros(TCarro carro);
void reajustar0km (TCarro agencia[], int quant);

//main
void main ()
{
	
}

//Implementação das demais funções
void buscarCarros (TCarro agencia [], int quant, char m[], int a1, int a2, float x)
{
	//Declaração de variáveis
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
		printf ("Nenhum carro que atenda essas condições foi encontrado.");
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
	//Declaração de variáveis
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
