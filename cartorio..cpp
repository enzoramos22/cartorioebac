#include <stdio.h> //biblioteca de comunica√ß√£o com o usu√°rio
#include <stdlib.h> //biblioteca de aloca√ß√£o de espa√ßo em mem√≥ria
#include <locale.h> //biblioteca de aloca√ß√µes de texto por regi√£o
#include <string.h> //biblioteca respons√°vel por cuidar das string
		
int registro() // funÁao responsavel por cadastrar os usuarios do sistema
{
	// inicio criaÁao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final criaÁao de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informÁao do usuario
	scanf("%s", cpf); //%s referese a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo,  "w"); // cria o arquivo e o "w" significa escrrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); 
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); 
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("nao foi possivel abrir o arquivo, nao localizado!");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas sao as informaÁoes do usuario: \n");
		printf("CPF:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("digite o CPF do usuario a se deletado: ");	
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE * file;
	file = fopen(cpf, "r");
	
	if (file != NULL);
	{
		printf(" Usuario deletado com sucesso!\n");
		system("pause");
	}
	
	if (file == NULL);
	{
		printf("o usuario nao se encontra no sistema!\n");
		system("pause");
	}
}


	
int main()
	{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartorio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opÁ„o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("OpÁ„o: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usu√°rio
		
		system("cls"); //responsavel por deletar a tela
	
		switch(opcao) //inicio da sele√ß√£o
		{
			case 1:
			registro(); //chamada de funÁoes
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
		
			default:
			printf("Essa opÁ„o nao est· disponivel! \n");
			system("pause");
			break;
		} //fim da sele√ß√£o
			
	}	
}
