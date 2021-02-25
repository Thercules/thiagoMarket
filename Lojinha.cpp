/*

*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define QTREG 30

typedef struct{
int codigo;
char nome[30];
int quantidade;
float preco;
}REGPRODUTO;

REGPRODUTO produto[QTREG];
float caixaAtual = 800.00;

int cadastrar();

void alterarEstoque(int pCodgio, int pQuantidade);

void modificarPreco(int pCodigo, float pPreco);

float venda();

void listaProduto(int pQtProduto);

void consultarSaldo();
int main(void){
int op = 0;
setlocale(LC_ALL,"Portuguese");
while(op != 7){
printf("\n===================");
printf("\n** Thiago market **"); 
printf("\n===================\n");
printf("\n========================");
printf("\n** Sejam-bem vindos!! **");
printf("\n========================\n");
printf("\n====================");
printf("\n** MENU Principal **");
printf("\n====================\n");
printf("\n1 - Cadastrar Produto\n2 - Atualizar Estoque\n3 - Alterar preço produto");
printf("\n4 - Realizar venda\n5 - Consultar estoque\n6 - Consultar saldo do caixa\n7 - Sair\n");
scanf("%d",&op);
system("cls");
switch(op){
case 1:
int qtProduto;
qtProduto = cadastrar();
break;
case 2:{
int pCodigo, pQuantidade;
printf("Digite o código do produto que deseja atualizar no estoque:");
scanf("%d",&pCodigo);
printf("Deseja alterar quantidade do produto: %s - quantidade: %d \n",produto[pCodigo].nome,produto[pCodigo].quantidade);
printf("Nova quantidade:");
scanf("%d",&pQuantidade);
fflush(stdin);
system("pause");
alterarEstoque(pCodigo, pQuantidade);
}
break;
case 3:{
int pCodigo;
float pPreco;
printf("Digite o código do produto que deseja modificar o preço:");
scanf("%d",&pCodigo);
printf("Deseja modificar o preço do produto: %s - preço: %0.2f \n",produto[pCodigo].nome,produto[pCodigo].preco);
printf("Novo preço:");
scanf("%f",&pPreco);
fflush(stdin);
system("pause");
modificarPreco(pCodigo, pPreco);
}
break;
case 4:
int pCodigo;
float lucro;
lucro = venda();
caixaAtual = caixaAtual + lucro;
break;
case 5:
listaProduto(qtProduto);
break;
case 6:
consultarSaldo();
break;
case 7:
exit;
break;
default:
printf("Opção inválida");
break;
}
}
system("pause");
return 0;
}

int cadastrar(){
char opSub;
int cont=0,qtProdutoCad=0;
float compra;
do{
produto[cont].codigo = cont;
fflush(stdin);
printf("Digite o nome do produto:");
gets(produto[cont].nome);
printf("Digite a quantidade:");
scanf("%d",&produto[cont].quantidade);
fflush(stdin);
printf("Digite o preço:");
scanf("%f",&produto[cont].preco);
fflush(stdin);
caixaAtual = caixaAtual - produto[cont].preco;
qtProdutoCad = qtProdutoCad + cont;
cont++;
printf("Deseja cadastrar um novo produto sim(s) ou não(n)?");
scanf("%c",&opSub);
}while(opSub == 's' or opSub == 'S');
return qtProdutoCad;
}

void alterarEstoque(int pCodigo, int pQuantidade){
produto[pCodigo].quantidade = pQuantidade;
}

void modificarPreco(int pCodigo, float pPreco){
produto[pCodigo].preco = pPreco;
}

float venda(){
int pCodigo;
float lucro;
printf("Informe o código do produto");
scanf("%d",&pCodigo);
if(produto[pCodigo].quantidade < 0){
printf("Produto indisponivel");
}else{
printf("\t %s - \t %1.2f",produto[pCodigo].nome,produto[pCodigo].preco);
lucro = lucro + produto[pCodigo].preco;
}
printf("\t\t\t Total: %1.2f",lucro);
return lucro;
}

void consultarSaldo(){
printf("Saldo atual em caixa: %1.2f",caixaAtual);
}

void listaProduto(int pQtProduto) {
    int i, qtProduto;
    qtProduto = pQtProduto;
    for (i = 0; i < qtProduto; i++) {
        printf("\tCódigo - %d \tNome - %s \tQuantidade - %d \n", produto[i].codigo, produto[i].nome, produto[i].quantidade);
    }
    fflush(stdout);
}
