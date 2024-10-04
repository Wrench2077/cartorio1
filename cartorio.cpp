#include <stdio.h> // biblioteca de comunicação com usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria 
#include <locale.h> //biblioteca de alocação de terxto por região 
#include <string.h> //biblioteca responsavel pelas strings

int registro() //função responsável por cadastrar usuários no sistema
{
	//início criação de variáveis/strings
	
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final criação das variáveis
	
	printf("Digete o CPF a ser cadastrado: "); //coletando informação dos usuários
	scanf("%s", cpf); //%s se refere as strings
	
	strcpy(arquivo, cpf); //responsavel por copiar o valor das strings 
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //w cria o arquivo e w significa escrever 
	fprintf(file,cpf); //salvo valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // a significa que quero atualizar a informação
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //abrindo arquivo e atualizando as informações
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //abrindo arquivo e atualizando as informações
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //abrindo arquivo e atualizando as informações
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	printf("Usuário criado com sucesso!\n\n"); //mensagem final ao cadastrar usuário
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
		printf("Não foi possível abrir o arquivo, não localizado!.\n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
 


}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deleteado: ");
	scanf("%s",cpf);
	
	remove(cpf); //responsável por deletar o arquivo 
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) 
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		
	}
}

int main()
{ 
   int opcao=0; //Definindo variáveis 
   int x=1;
   char senhadigitada[10]="a"; //iniciando implementação de senha 
   int comparacao;
  
   printf("### Cartório Da EBAC ### \n\n");
   printf("Login de administrador!\n\n Digite sua senha:");
   scanf("%s",senhadigitada); 
   
   comparacao = strcmp(senhadigitada, "admin"); //senha 
   
   if(comparacao == 0) //comparação de valor para ver se é o mesmo salvo na "senha digitada"
   {
        system("cls");
        
        for(x=1;x=1;)
       {
       	 system("cls");
   
         system("cls"); //ressponsável por limpar a tela 

         setlocale(LC_ALL, "Portuguese" ); //Definindo idioma 
   
         printf("### Cartório Da EBAC ### \n\n"); //Inicio do menu
         printf ("Escolha a opção desejada no menu: \n\n"); 
         printf("\t1 - Registrar nomes\n\n");
         printf("\t2 - Consultar nomes\n\n");
         printf("\t3 - Deletar nomes\n\n");
         printf("\t4 - Sair do sistema\n\n");
         printf("opção: "); //Fim do menu 
  
         scanf("%d", &opcao); //Armazenando escolha do usuário
    
         system("cls");
        
        switch(opcao) //inicio seleção menu
        {
       	    case 1:
       	    registro(); //chamada de funções 
    	    break;
    	   
    	    case 2:
    	    consultar();
      	    break;
      	   
            case 3:
       	    deletar();
       	    break;
       	  
       	    case 4:
       	    printf("Obrigado por usar o sistema!\n");
       	    return 0;
       	    break;
       	 
       	  
       	    default:
       	    printf("Está opção está indisponível!\n"); //mensagem para usuário 
   	        system("pause");
   	        break;
      	  
	       } 
       }
   }
   else 
     printf("Senha incorreta!\n");
}

