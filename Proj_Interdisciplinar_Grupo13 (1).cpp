#include<locale.h> //biblioteca para uso de acentos
#include<stdlib.h> //biblioteca para uso do system
#include<stdio.h> //biblioteca para printf e scanf
#include<string.h> //biblioteca strlen

int main (){ //função principal do código
	setlocale(LC_ALL, "Portuguese"); //setando linguagem para português (uso dos acentos)
	
	//declarando variáveis das structs usadas no cadastro do cliente
	struct cadastro_endereco
	{
	char rua[30];
	char bairro[30];
	char cidade[30];
	int numero;
	char estado[3];
    };
	
	struct cadastro_data_nascimento
	{
	int dia;
	int mes;
	int ano;
	};
	//struct do cadastro do cliente
	struct cadastro_cliente
	{
	char nome[35];
	int telefone;
	char email[35];
	int cpf;
	struct cadastro_endereco endereco;                       //definindo a variável da struct dentro de outra struct
	struct cadastro_data_nascimento data_nascimento;
	}cad_cliente[2];
	//declarando variáveis para loop/repetição, escolher o switch, sair do loop do menu
	int i;
	int opcao;
	int sair=0;
	int sair2=0;
	int sair3=0;
	double valorProdutoFinal=0;
	int produtos;
	int formaPagamento;
	char nomeCartao[40];
	int cvv;
	int mesVencimento;
	int anoVencimento;
	int cpfCartao;
	
	do{ //loop do menu
	//menu inicial
	printf("----------------------------------------------\n");
	printf("|                FARMÁCIA xxxxx              |\n");
	printf("|                                            |\n");
	printf("| Escolha uma opção                          |\n");
	printf("|                                            |\n");
	printf("| [1] Cadastro de cliente                    |\n");
	printf("| [2] Produtos                               |\n");
	printf("| [3] Efetuar Pagamento                      |\n");
	printf("| [0] Sair                                   |\n");
	printf("----------------------------------------------\n\n");
	scanf("%d", &opcao);
	fflush(stdin);
	
	switch (opcao)
	{
	case 1:
	system("cls");
	for (i=0;i<2;i++) //repetição 2x do cadastro do cliente
	{
		printf("\n\n-------------------- CADASTRO DE CLIENTE --------------------\n\n");
		//cadastro com printf, fgets para strings, scanf para números           vetor de 2 na struct cad_cliente (2 clientes sendo cadastrados)
		do {
		    printf("Nome do cliente: ");
		    fflush(stdin);
		    fgets(cad_cliente[i].nome,35,stdin);
		    if(strlen(cad_cliente[i].nome) <= 1)
		        printf("Nome inválido. Digite novamente: \n");
		}while(strlen(cad_cliente[i].nome) <= 1);    
		    printf("Telefone do cliente: ");
		    scanf("%d", &cad_cliente[i].telefone);
		    
		do {
		    printf("Email do cliente: ");
		    fflush(stdin);
		    fgets(cad_cliente[i].email,35,stdin);
		    if(strlen(cad_cliente[i].email) <= 1)
		        printf("Email inválido. Digite novamente: \n");
	    }while(strlen(cad_cliente[i].email) <= 1);
	        
	    printf("CPF do cliente: ");
		fflush(stdin);
		scanf("%d", &cad_cliente[i].cpf);
		printf("Data de Nascimento do cliente\n");
		
		do {
		    printf("Digite o dia: ");
		    fflush(stdin);
		    scanf("%d", &cad_cliente[i].data_nascimento.dia);
		    if(cad_cliente[i].data_nascimento.dia < 1 || cad_cliente[i].data_nascimento.dia > 31)
		        printf("Dia inválido. Digite novamente: \n");
	    }while(cad_cliente[i].data_nascimento.dia < 1 || cad_cliente[i].data_nascimento.dia > 31);
	        
	    do { 
		    printf("Digite o mês: ");
		    fflush(stdin);
		    scanf("%d", &cad_cliente[i].data_nascimento.mes);
		    if(cad_cliente[i].data_nascimento.mes < 1 || cad_cliente[i].data_nascimento.mes > 12)
		        printf("Mês inválido. Digite novamente: \n");
	    }while(cad_cliente[i].data_nascimento.mes < 1 || cad_cliente[i].data_nascimento.mes > 12);
	        
	    do {
		    printf("Digite o ano: ");
		    fflush(stdin);
		    scanf("%d", &cad_cliente[i].data_nascimento.ano);
		    if(cad_cliente[i].data_nascimento.ano < 1950 || cad_cliente[i].data_nascimento.ano > 2009)
		        printf("É necessário ter mais que 12 anos para realizar o cadastro do cliente.\n");
		}while(cad_cliente[i].data_nascimento.ano < 1950 || cad_cliente[i].data_nascimento.ano > 2009);
		
		printf("Endereço do cliente\n");
		printf("Rua: ");
		fflush(stdin);
		fgets(cad_cliente[i].endereco.rua,30,stdin);
		printf("Bairro: ");
		fflush(stdin);
		fgets(cad_cliente[i].endereco.bairro,30,stdin);
		printf("Cidade: ");
		fflush(stdin);
		fgets(cad_cliente[i].endereco.cidade,30,stdin);
		printf("Número: ");
		fflush(stdin);
		scanf("%d", &cad_cliente[i].endereco.numero);
		printf("Estado (SIGLA): ");
		fflush(stdin);
		fgets(cad_cliente[i].endereco.estado,3,stdin);
	    printf("\n");
		printf("-------------------------------------------------------------\n");
		system("pause");
		system("cls");		
	}
	
	for (i=0;i<2;i++) //exibindo os dados dos 2 clientes cadastrados
	{
		printf("\n\n-------------------- DADOS DO CLIENTE %d --------------------\n\n", i+1);
		printf("Nome: %s", cad_cliente[i].nome);
		printf("Telefone: %d\n", cad_cliente[i].telefone);
		printf("Email: %s", cad_cliente[i].email);
		printf("CPF: %d\n", cad_cliente[i].cpf);
		printf("Data de nascimento: %d/%d/%d\n", cad_cliente[i].data_nascimento.dia, cad_cliente[i].data_nascimento.mes, cad_cliente[i].data_nascimento.ano);
		printf("Endereço:\n");
		printf("Rua: %s", cad_cliente[i].endereco.rua);
		printf("Bairro: %s", cad_cliente[i].endereco.bairro);
		printf("Cidade: %s", cad_cliente[i].endereco.cidade);
		printf("Número: %d\n", cad_cliente[i].endereco.numero);
		printf("Estado: %s\n\n", cad_cliente[i].endereco.estado);
		printf("-------------------------------------------------------------\n");
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
	break;
	
	do{
	case 2:
	system("cls");
	printf("--------------------------------------------------\n");
	printf("| Escolha os produtos:                           |\n");
	printf("--------------------------------------------------\n");
	printf("| [1] Remédios sem receita R$39,99               |\n");
	printf("| [2] Cortador de unha R7,99                     |\n");
	printf("| [3] Haste flexível com algodão R$5,99          |\n");
	printf("| [4] Camisinhas R$14,99                         |\n");
	printf("| [5] Creme dental R$5,99                        |\n");
	printf("| [6] Fio dental R$8,99                          |\n");
	printf("| [7] Absorvente R$11,99                         |\n");
	printf("| [8] Escova de dente R$9,99                     |\n");
	printf("| [9] Shampoo R$20,99                            |\n");
	printf("| [10] Condicionador R$19,99                     |\n");
	printf("| [11] Sabonete (10 unidades) R$32,99            |\n");
	printf("| [12] Bucha vegetal R$7,99                      |\n");
	printf("| [13] Esparadrapo R$15,99                       |\n");
	printf("| [0] Voltar para o Menu (Finalizar Escolha)     |\n");
	printf("--------------------------------------------------\n\n");
    scanf("%d", &produtos);
    fflush(stdin);
    switch (produtos)
    {
    	case 1:
    		valorProdutoFinal+=40;
    		printf("\nValor da compra: %.1lfR$\n\n", valorProdutoFinal);
    		system("pause");
    	break;
    	case 2:
    		valorProdutoFinal+=8;
    		printf("\nValor da compra: %.1lfR$\n\n", valorProdutoFinal);
    		system("pause");
    	break;
    	case 3:
    		valorProdutoFinal+=6;
    		printf("\nValor da compra: %.1lfR$\n\n", valorProdutoFinal);
    		system("pause");
    	break;
    	case 4:
    		valorProdutoFinal+=15;
    		printf("\nValor da compra:%.1lfR$\n\n", valorProdutoFinal);
    		system("pause");
    	break;
    	case 5:
    		valorProdutoFinal+=6;
    		printf("\nValor da compra:%.1lfR$\n\n", valorProdutoFinal);
    		system("pause");
    	break;
    	case 6:
    		valorProdutoFinal+=9;
    		printf("\nValor da compra:%.1lfR$\n\n", valorProdutoFinal);
    		system("pause");
    	break;
    	case 7:
    		valorProdutoFinal+=12;
    		printf("\nValor da compra:%.1lfR$\n\n", valorProdutoFinal);
    		system("pause");
    	break;
    	case 8:
    		valorProdutoFinal+=10;
    		printf("\nValor da compra:%.1lfR$\n\n", valorProdutoFinal);
    		system("pause");
    	break;
    	case 9:
    		valorProdutoFinal+=21;
    		printf("\nValor da compra:%.1lfR$\n\n", valorProdutoFinal);
    		system("pause");
    	break;
    	case 10:
    		valorProdutoFinal+=20;
    		printf("\nValor da compra:%.1lfR$\n\n", valorProdutoFinal);
    		system("pause");
    	break;
		case 11:
		    valorProdutoFinal+=33;
		    printf("\nValor da compra:%.1lfR$\n\n", valorProdutoFinal);
    		system("pause");
		break;
		case 12:
			valorProdutoFinal+=8;
			printf("\nValor da compra:%.1lfR$\n\n", valorProdutoFinal);
    		system("pause");
		break;
		case 13:
			valorProdutoFinal+=16;
			printf("\nValor da compra:%.1lfR$\n\n", valorProdutoFinal);
    		system("pause");
		break;
		case 0:
			sair2=1;
		break;
		default:
			printf("ID Produto inválido\n");
			system("pause");
	}
	}while (sair2!=1);
	system("pause");
	system("cls");
	break;
	
	do{
	case 3:
	system("cls");
	printf("--------------------------------------------------\n");
	printf("| Valor total: R$%.2lf                           |\n", valorProdutoFinal);
	printf("--------------------------------------------------\n");
	printf("| Formas de Pagamento:                           |\n");
	printf("| [1] Cartão de Crébito                          |\n");
	printf("| [2] Boleto Bancário                            |\n");
	printf("| [3] Pix                                        |\n");
	printf("| [0] Voltar para o Menu                         |\n");
	printf("--------------------------------------------------\n");
	scanf("%d", &formaPagamento);
	fflush(stdin);
	
	switch(formaPagamento)
	{
		case 1:
			system("cls");
			printf("--------------------------------------------------\n");
			printf("Informe o nome completo do titular:\n");
			fgets(nomeCartao,40,stdin);
			fflush(stdin);
			printf("Informe o CVV do cartão:\n");
			scanf("%d", &cvv);
			fflush(stdin);
			do{
			    printf("Informe o mês de vencimento:\n");
		        scanf("%d", &mesVencimento);
		        fflush(stdin);
			    if (mesVencimento<1||mesVencimento>12)
			        printf("Mês inválido. Digite novamente\n");
		    }while (mesVencimento<1||mesVencimento>12);
		    
		    printf("Informe o ano de vencimento:\n");
		    scanf("%d", &anoVencimento);
		    printf("Informe o CPF do titular:\n");
		    scanf("%d", &cpfCartao);
		    printf("--------------------------------------------------\n");
		    
		    system("pause");
		    system("cls");
		    printf("--------------------------------------------------\n");
		    printf("| Pagamento efetuado com sucesso!                \n");
		    printf("| Valor da compra: R$%.2lf                       \n", valorProdutoFinal);
		    printf("--------------------------------------------------\n");
		    printf("| Dados do Cartão:                               \n");
		    printf("| CVV: %d                                       \n", cvv);
		    printf("| Data de Vencimento: %d/%d                     \n", mesVencimento, anoVencimento);
		    printf("| CPF Titular: %d                          \n", cpfCartao);
		    printf("| Nome Titular: %s               ", nomeCartao);
		    system("pause");
		    system("cls");
		    break;
		    
		    case 2:
		    	system("cls");
		    	printf("--------------------------------------------------\n");
		    	printf("|Boleto impresso!                                |\n");
		    	printf("--------------------------------------------------\n\n");
		    	system("pause");
		    	system("cls");
		    break;
		    
		    case 3:
		    	system("cls");
		    	printf("--------------------------------------------------\n");
		    	printf("|                      PIX                       |\n");
		    	printf("| CPF: 29751390125                               |\n");
		    	printf("| R$ %.2lf                                       \n", valorProdutoFinal);
		    	printf("| Nome: Gustavo Borges                           |\n");
		    	printf("| Chave Pix: 29751390125                         |\n");
		    	printf("--------------------------------------------------\n");
		    	system("pause");
		    	system("cls");
		    break;
		    
		    case 0:
		    	sair3=1;
		    break;
		    
		    default:
		    printf("Opção Inválida, digite novamente:\n");
		   		
	}
	
    }while(sair3!=1);
	system("pause");
	system("cls");
	break;
	
	case 0:
	sair=1;
	break;
	
	default: //relatando a invalidez da opção escolhida
	printf("Opção inválida\n");
	system("pause");
	system("cls");	
    }
    }while (sair!=1); //fechando o loop do menu
	
	return 0;
}
