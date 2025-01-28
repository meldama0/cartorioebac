#include <stdio.h>  //biblioteca de com. com o usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria (esse espa�o representa tal coisa)
#include <locale.h>  //biblioteca de aloca��o de texto por regi�o
#include <string.h>  //biblioteca de strings

int registro()
{
	
	char arquivo [50],nome [50], sobrenome [50], cpf [50],cargo [50];
	
	printf ("\ndigite os dados a serem cadastrados:\n");
	
	printf ("cpf(apenas n�meros):");
	scanf ("%s",cpf);  //scanf � p armazenar tudo que o usu�rio digitar na string ou na vari�vel
	    strcpy (arquivo, cpf);  //copia os valores das strings
	
	FILE *file;
	file = fopen (arquivo, "w");
	
	printf ("nome:");
	scanf ("%s", nome);  //%s armazena dentro de uma string //o scan %s nao le a linha inteira, ele le ate o primeiro esapco, e o considera como o fim
		file = fopen (arquivo, "a");
	    fprintf (file,nome);
	    fprintf (file, ";");
	    fclose (file);
	
	printf ("sobrenome:");
	scanf ("%s", sobrenome);
	    file = fopen (arquivo, "a");
	    fprintf (file,sobrenome);
	    fprintf (file, ";");
	    fclose (file);

	printf ("cargo:");
	scanf ("%s", cargo);
	    file = fopen (arquivo, "a");
	    fprintf (file,cargo);
	    fprintf (file, ";");
	    fclose (file);	
	 
}

int consulta()
{
	setlocale (LC_ALL, "Portuguese");
	
	char cpf [50];
	char conteudo [500];
	
	printf ("digite o cpf a ser consultado:");
	scanf ("%s", cpf); //salva na variavel 
	
	FILE *file;  //consultar o arquvio
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf("arquivo n�o localizado.\n");
	}
	
	while (fgets(conteudo, 500, file) != NULL)
	{
		printf ("essas s�o as informa��es do usu�rio:");
		printf ("%s", conteudo);
		printf ("\n\n");
	}
	
	fclose (file);
	system ("pause");
}

int deletar()
{
	setlocale (LC_ALL, "Portuguese");
	
	char cpf [50];
	
	printf ("digite o cpf do usu�rio a ser deletado:");
	
	scanf ("%s", cpf);
		
	if (remove (cpf) == 0)
	{
		printf ("usu�rio deletado com sucesso!\n");
	}
	else 
	{
		printf ("erro ao deletar usu�rio.\n");
	}
	
	system ("pause");
}




int main ()  //par�nteses vieram por ela ser uma fun��o
{
	int opcao=0;  //int � o do tipo inteiro (?) // um = � associa��o, atribui��o // definindo vari�veis
	int x=1;
	
	for(x=1;x==1;)  //1 � p sempre voltar p come�o
    {
	
	  system("cls");  //limpa a tela
	  
	  setlocale (LC_ALL, "Portuguese");  //define a linguagem
	
	  printf ("\n cart�rio da EBAC \n\n ");
	  printf ("menu \n");  //o \n faz espa�amento de linha
	  printf ("\t 1-registrar nomes");  //o \t faz um espa�amento de par�grafo
	  printf ("\t 2-consultar nomes");
	  printf ("\t 3-deletar nomes");
	  printf ("\n\n Op��o:");
	
	  scanf ("%d", &opcao);  //scanf escaneia o que o user coloca -- %d armazena a  vari�vel do tipo inteira
	
	  system ("cls");
	
	  switch(opcao)
	   {
	  	case 1: 
	  	registro();
	    break;
	    
	    case 2: 
		consulta();
	    break;
	    
	    case 3:
	    deletar();
	    break;
	    
	    default:
	    printf ("essa op��o n�o est� dispon�vel\n");
	    system ("pause");
	    break;
	   }
    } 
}

	

	

