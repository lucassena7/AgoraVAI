/* Suponha que n�o existissem as fun��es strlen, strcpy, strcat e strcmp. 
Pede-se, ent�o, a implementa��o de fun��es que tenham o mesmo objetivo daquelas.*/

//Importa��o de bibliotecas
#include <stdio.h>

//Prot�tipo das fun��es
int tamanho (char string[]);
void copia (char stringOri[], char stringDes[]);
void concatenar (char stringOri[], char stringDes[]);
int comparar (char stringUm[], char stringDois[]);

//Main
void main ()
{
	//Declara��o de vari�veis
	char frase[30], fraseDois[30];
	int resposta;
	
	fflush (stdin);  //standard input - entrada padr�o
	//leitura da primeira string:
	printf ("Entre com uma frase: ");
	gets (frase);  //get string
	
	resposta = tamanho (frase);
	
	printf ("O tamano da string %s e: %d", frase, resposta);
	
	system("cls");
	
	fflush (stdin);  //standard input - entrada padr�o
	//leitura da primeira string:
	printf ("Entre com uma frase: ");
	gets (frase);  //get string
	
	fflush (stdin);  //standard input - entrada padr�o
	//leitura da primeira string:
	printf ("Entre com outra frase: ");
	gets (fraseDois);  //get string
	
	printf ("Frase um: %s", frase);
	printf ("\nFrase Dois: %s", fraseDois);
	
	copia (frase, fraseDois);
	
	printf ("\n\nFrase um: %s", frase);
	printf ("\nFrase Dois: %s", fraseDois);
	
	system("cls");
	
	fflush (stdin);  //standard input - entrada padr�o
	//leitura da primeira string:
	printf ("Entre com uma frase: ");
	gets (frase);  //get string
	
	fflush (stdin);  //standard input - entrada padr�o
	//leitura da primeira string:
	printf ("Entre com outra frase: ");
	gets (fraseDois);  //get string
	
	printf ("Frase um: %s", frase);
	printf ("\nFrase Dois: %s", fraseDois);
	
	concatenar (frase, fraseDois);
	
	printf ("\n\nFrase um: %s", frase);
	printf ("\nFrase Dois: %s", fraseDois);
}

//Implementa��o das demais fun��es
int tamanho (char string[])
{
	//Declara��o de vari�veis
	int i;
	
	for (i=0; string[i]!='\0'; i++);
	
	return i;
}

void copia (char stringDes[], char stringOri[])
{
	//Declara��o de vari�veis
	int i;
	
	for (i=0; stringOri[i]!='\0'; i++)
	{
		stringDes[i] = stringOri[i];
	}
	
	//finalizando a stringDes com '\0'
	stringDes[i] = '\0';
}

void concatenar (char stringOri[], char stringDes[])
{
	//Declara��o de vari�veis
	int i, j;
	
	/* s1 {t|e|s|t|e|\0|}  -> Original
	   s2 {1|2|3|} -> Destino*/
	   
	for (i=0, j=tamanho(stringOri); stringDes[i]!='\0'; i++, j++)
	{
		stringOri[j] = stringDes[i];
	}
	stringOri[j] = '\0';
}

int comparar (char stringUm[], char stringDois[])
{
	//Declara��o de vari�veis
	
	
}
