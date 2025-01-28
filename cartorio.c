#include <stdio.h>  //biblioteca de com. com o usuário
#include <stdlib.h>  //biblioteca de alocação de espaço em memória (esse espaço representa tal coisa)
#include <locale.h>  //biblioteca de alocação de texto por região
#include <string.h>  //biblioteca de strings

int registro()
{
	
	char arquivo [50],nome [50], sobrenome [50], cpf [50],cargo [50];
	
	printf ("\ndigite os dados a serem cadastrados:\n");
	
	printf ("cpf(apenas números):");
	scanf ("%s",cpf);  //scanf é p armazenar tudo que o usuário digitar na string ou na variável
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
		printf("arquivo não localizado.\n");
	}
	
	while (fgets(conteudo, 500, file) != NULL)
	{
		printf ("essas são as informações do usuário:");
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
	
	printf ("digite o cpf do usuário a ser deletado:");
	
	scanf ("%s", cpf);
		
	if (remove (cpf) == 0)
	{
		printf ("usuário deletado com sucesso!\n");
	}
	else 
	{
		printf ("erro ao deletar usuário.\n");
	}
	
	system ("pause");
}




int main ()  //parênteses vieram por ela ser uma função
{
	int opcao=0;  //int é o do tipo inteiro (?) // um = é associação, atribuição // definindo variáveis
	int x=1;
	
	for(x=1;x==1;)  //1 é p sempre voltar p começo
    {
	
	  system("cls");  //limpa a tela
	  
	  setlocale (LC_ALL, "Portuguese");  //define a linguagem
	
	  printf ("\n cartório da EBAC \n\n ");
	  printf ("menu \n");  //o \n faz espaçamento de linha
	  printf ("\t 1-registrar nomes");  //o \t faz um espaçamento de parágrafo
	  printf ("\t 2-consultar nomes");
	  printf ("\t 3-deletar nomes");
	  printf ("\n\n Opção:");
	
	  scanf ("%d", &opcao);  //scanf escaneia o que o user coloca -- %d armazena a  variável do tipo inteira
	
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
	    printf ("essa opção não está disponível\n");
	    system ("pause");
	    break;
	   }
    } 
}

	

	

