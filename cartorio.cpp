#include <stdio.h> // biblioteca de comunica��o com usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria 
#include <locale.h> //biblioteca de aloca��o de terxto por regi�o 
#include <string.h> //biblioteca responsavel pelas strings

int registro() //fun��o respons�vel por cadastrar usu�rios no sistema
{
	//in�cio cria��o de vari�veis/strings
	
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final cria��o das vari�veis
	
	printf("Digete o CPF a ser cadastrado: "); //coletando informa��o dos usu�rios
	scanf("%s", cpf); //%s se refere as strings
	
	strcpy(arquivo, cpf); //responsavel por copiar o valor das strings 
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //w cria o arquivo e w significa escrever 
	fprintf(file,cpf); //salvo valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // a significa que quero atualizar a informa��o
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //abrindo arquivo e atualizando as informa��es
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //abrindo arquivo e atualizando as informa��es
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //abrindo arquivo e atualizando as informa��es
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); 
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese" ); //selecionando idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //r responsavel por ler
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
 


}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deleteado: ");
	scanf("%s",cpf);
	
	remove(cpf); //respons�vel por deletar o arquivo 
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) 
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
		
	}
}

int main()
{ 
   int opcao=0; //Definindo vari�veis 
   int x=1;
   
   for(x=1;x=1;)
   {
   
       system("cls"); //resspons�vel por limpar a tela 

       setlocale(LC_ALL, "Portuguese" ); //Definindo idioma 
   
       printf("### Cart�rio Da EBAC ### \n\n"); //Inicio do menu
       printf ("Escolha a op��o desejada no menu: \n\n"); 
       printf("\t1- Registrar nomes\n");
       printf("\t2- Consultar nomes\n");
       printf("\t3- Deletar nomes\n\n");
       printf("op��o: "); //Fim do menu 
 
       scanf("%d", &opcao); //Armazenando escolha do usu�rio
   
       system("cls");
       
       switch(opcao) //inicio sele��o menu
       {
       	  case 1:
       	  registro(); //chamada de fun��es 
    	  break;
    	  
    	  case 2:
    	  consultar();
      	  break;
      	  
      	  case 3:
      	  deletar();
       	  break;
       	  
       	  default:
       	  printf("Est� op��o est� indispon�vel!\n"); //mensagem para usu�rio 
   	      system("pause");
   	      break;
      	  
	   }
   
      
}   
}
