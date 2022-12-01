/*
 LARA SOUZA MONTENEGRO
 RA: 2220230
 CIENCIA DA COMPUTACAO
 2º SEMESTRE
 NOITE
 */
/*
 NAO CONSEGUI COLOCAR ALOCACAO E NEM PONTEIROS*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct Produto{
    char nome[100];
    int cod;
    float cCompra;
    float cVenda;
    int qntd;
    int vendidos;
    float vPodEstoque;
}Produto;

struct Produto p;
//declaração dos metodos
void cadastrar(void);
void modificar(void);
void venda(void);
void relatorio(void);

//VAI BUSCAR O PRODUTO PELO CODIGO
int codProd(int buscarCod){
    //CRIA E ABRE O ARQUIVO EM BINARIO
    FILE* arqvProduto = fopen("./produto.dat", "rb");
    int achou = FALSE;
    int teste;
    //PESQUISA
    while(fread(&p, sizeof(Produto), 1, arqvProduto)){
        if(buscarCod == p.cod){
            return 1;
        }
    }
    fclose(arqvProduto);
    return 0;
}//ok


int main() {
    int opc;
    do{
        //=========VARIAVEIS=========
        struct Produto p[2];
        int i;
        int opc;
        //=========MENU=========
        printf("O sistema esta apresentando alguns bugs e atrasos\ncaso aconteca tente novamente\n");
        printf("***** REGISTRO DE CAIXA *****\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Modificar Produto\n");
        printf("3 - Informar Venda\n");
        printf("4 - Mostrar Estoque Atual\n");
        printf("5 - Sair do Sistema\n");
        scanf("%d", &opc);
       setbuf(stdin, NULL);


        switch (opc) {
//               ================================= OPÇÃO 1==========================================
            case 1://cadastrar produto
                system("cls");
                cadastrar();

                break;

            case 2://modificar produto
                system("cls");
                modificar();

                break;

            case 3://informar venda
                system("cls");
                venda();
                break;

            case 4://mostrar estoque atual
                system("cls");
                relatorio();
                break;

            case 5://sair do sistema
                system("cls");
                break;
        }



    }while(opc != 5);


    return 0;
}//ok

void cadastrar(){
    struct Produto p;
    int opc;
    int cod, teste = 0;
    p.cod = cod;
    //1º RECEBE AS INFO DO PRODUTO
    printf("\n-----------------------\n");
    printf("Nome: \n");                                   //no 1º produto aparece na tela:
    fgets(p.nome, sizeof(p.nome), stdin);//nome:     nao recebe cada valor de cada vez
    setbuf(stdin, NULL);
    //codigo:    NAO É POSSIVEL MOSTRAR O NOME/CODIGO
    printf("Codigo: \n");
    scanf("%d", &p.cod);
    setbuf(stdin, NULL);

    printf("Preco Unitario de Compra: \n");
    scanf("%f", &p.cCompra);
    setbuf(stdin, NULL);

    printf("Preco Unitario de Venda: \n");
    scanf("%f", &p.cVenda);
    setbuf(stdin, NULL);

    //CONDICIONAIS:
    //Que o valor do custo unitário de compra seja menor que o valor do custo unitário de venda;
    if(p.cVenda <= p.cCompra) {//TEM UM ERRO AQUI!!!!!!!!
        printf("O preco unitario de venda do produto nao pode \nser menor do que o preco unitario de compra");
        printf("Informe novamente!\n");
        printf("Preco Unitario de Venda: \n");
        scanf("%f", &p.cVenda);
        setbuf(stdin, NULL);
    }
    printf("Quantidade de Produtos: \n");
    scanf("%d", &p.qntd);
    setbuf(stdin, NULL);
    //Que a quantidade comprada seja maior que zero;
    if(p.qntd <= 0){
        printf("A quantidade de produtos disponiveis para venda tem que ser maior do que zero!");
        printf("Quantidade de Produtos: \n");
        scanf("%d", &p.qntd);
        setbuf(stdin, NULL);
    }
    //AO FINAL, INFORMA O VALOR DO PRODUTO EM ESTOQUE:
    printf("Quantidade de Produtos Vendidos: \n");
    scanf("%d", &p.vendidos);
    setbuf(stdin, NULL);

    //Que a quantidade vendida seja menor ou igual a quantidade comprada;
    if(p.vendidos > p.qntd) {
        printf("OPS! A quantidade de itens vendidos nao pode \nser maior que a quantidade de itens em estoque\n");
        printf("Informe novamente!\n");
        printf("Quantidade de Produtos Vendidos: \n");
        scanf("%d", &p.vendidos);
        setbuf(stdin, NULL);
    }

    //valor do produto em estoque
    p.vPodEstoque = p.cVenda * p.qntd;
    printf("Valor do produto em estoque: R$%.2f\n", p.vPodEstoque);

    FILE* arqvProduto;
    arqvProduto = fopen("./produto.dat", "ab");

    //VERIFICA SE O ARQUIVO JA ESTA ABERTO OU EXISTE
    if(arqvProduto == NULL){
        printf("ERRO!");
        exit(1);
    }

    //ESCREVER NO ARQUIVO
    fwrite(&p, sizeof(Produto), 1, arqvProduto);

    fclose(arqvProduto);
    printf("Enter para sair");
    getchar();
}//ok

void modificar(){
    FILE* arqvProduto = fopen("./produto.dat", "rb");
    int achou = FALSE;
    int buscar;
    printf("-------------------------------\n");
    printf("Digite o codigo do produto: \n");
    scanf("%d", &buscar);
    setbuf(stdin, NULL);

    while(fread(&p, sizeof(Produto), 1, arqvProduto)){
        if(buscar == p.cod){
            achou = TRUE;
            break;
        }
    }
    setbuf(stdin, NULL);

    if(!achou){
        printf("NAO ENCONTRADO!\n");
        getchar();
        system("cls");
        return;
    }
    printf("------------------------------------------\n");
    printf("nome: \n");
    fgets(p.nome, sizeof(p.nome), stdin);
    setbuf(stdin, NULL);
    printf("codigo: \n");
    scanf("%d",&p.cod);
    setbuf(stdin, NULL);
    printf("Preco de compra: \n");
    scanf("%f",&p.cCompra);
    setbuf(stdin, NULL);
    printf("Preco de venda: \n");
    scanf("%f",&p.cVenda);
    setbuf(stdin, NULL);
    printf("Quantidade de produtos: \n");
    scanf("%f",&p.qntd);
    setbuf(stdin, NULL);
    printf("Produtos vendidos: \n");
    scanf("%f",&p.vendidos);
    setbuf(stdin, NULL);

    //condicionais
    if(p.cVenda <= p.cCompra) {
        printf("O preco unitario de venda do produto nao pode \nser menor do que o preco unitario de compra");
        printf("Informe novamente!\n");
        printf("Preco Unitario de Venda: \n");
        scanf("%f", &p.cVenda);
        setbuf(stdin, NULL);
    }
    printf("Quantidade de Produtos: \n");
    scanf("%d", &p.qntd);
    setbuf(stdin, NULL);
    //Que a quantidade comprada seja maior que zero;
    if(p.qntd <= 0){
        printf("A quantidade de produtos disponiveis para venda tem que ser maior do que zero!");
        printf("Quantidade de Produtos: \n");
        scanf("%d", &p.qntd);
        setbuf(stdin, NULL);
    }
    //AO FINAL, INFORMA O VALOR DO PRODUTO EM ESTOQUE:
    printf("Quantidade de Produtos Vendidos: \n");
    scanf("%d", &p.vendidos);
    setbuf(stdin, NULL);

    //Que a quantidade vendida seja menor ou igual a quantidade comprada;
    if(p.vendidos > p.qntd) {
        printf("OPS! A quantidade de itens vendidos nao pode \nser maior que a quantidade de itens em estoque\n");
        printf("Informe novamente!\n");
        printf("Quantidade de Produtos Vendidos: \n");
        scanf("%d", &p.vendidos);
        setbuf(stdin, NULL);
    }
    //valor do produto em estoque
    p.vPodEstoque = p.cVenda * p.qntd;
    printf("Valor do produto em estoque: R$%.2f\n", p.vPodEstoque);

    //cria um arquivo auxiliar
    FILE* arqAuxiliar = fopen("./arqvAux.dat", "ab");
    rewind(arqvProduto);//voltar ao começo do arquivo, rebobinar.

    if(arqvProduto == NULL || arqAuxiliar == NULL){
        printf("ERRO!");
    }else{
        //PESQUISA
        fwrite(&p, sizeof(Produto), 1, arqAuxiliar);
        while(fread(&p, sizeof(Produto), 1, arqvProduto)){
            if(buscar != p.cod){
                fwrite(&p, sizeof(Produto), 1, arqAuxiliar);

            }
        }

    }

    fclose(arqvProduto);
    fclose(arqAuxiliar);

    remove("./produto.dat");
    rename("./arqAux.dat","./produto.dat");

    printf("pressione enter");
    getchar();
    system("cls");
} //ok

void venda(){
    FILE* arqvProduto = fopen("produto.dat", "rb");
    int achou = FALSE;
    int qntd, estoque;
    float vendas;
    int buscar;

    printf("Codigo do produto: \n");
    scanf("%d",&buscar);
    setbuf(stdin, NULL);
    //Executa a operação de pesquisa
    while(fread(&p,sizeof(Produto),1,arqvProduto)){
        //Verifica se a matricula existe
        if(buscar == p.cod){
            achou = TRUE;
            break;
        }
    }
    setbuf(stdin, NULL);

    //NAO ENCONTROU

    if(!achou){
        printf("nao encontrado\n");
        getchar();
        system("cls");
        return;
    }

    printf("--------------------\n");
    printf("%s\n", p.nome);
    printf("Quantos foram vendidos: \n");
    scanf("%d", &qntd);
    setbuf(stdin, NULL);
    estoque = p.qntd - qntd;
    printf("Total da venda: R$%.2f\n");
    printf("Ainda resta no estoque: %d", estoque);


    FILE* arqAux = fopen("./arqAux.dat","ab");
    rewind(arqvProduto);

    if(arqvProduto == NULL || arqAux == NULL){
        printf("erro\n");
    }
    else{
        //Executa a operação de pesquisa
        fwrite(&p,sizeof(Produto),1,arqAux);
        while(fread(&p,sizeof(Produto),1,arqvProduto)){
            if(buscar!=p.cod){
                fwrite(&p,sizeof(Produto),1,arqAux);
            }
        }
    }

    //Fecha o arquivo
    fclose(arqvProduto);
    fclose(arqAux);

    //Remove o arquivo
    remove("./produto.dat");
    rename("./arqAux.dat","./produto.dat");

    printf("pressione enter");
    getchar();
    system("cls");

}

void relatorio(){
    //struct Produto p;
    float totEstoque = 0;//valor total do estoque
    int totProdutos = 0;//qnts total de produtos
    FILE* arqvProduto = fopen("./produto.dat", "rb");

    if(arqvProduto == NULL){
        printf("INFELIZMENTE NAO HA PRODUTOS\n");
    }
    printf("        ------- ESTOQUE ATUAL -------\n");
    printf("Codigo\tProduto\t  Es. Atual\tValor Estoque\n");

    while(fread(&p, sizeof(Produto), 1, arqvProduto)){
        totEstoque = p.vPodEstoque + totEstoque;
        totProdutos = p.qntd + totProdutos;
        printf("%d\t%s", p.cod, p.nome);
        printf("\t\t\t%d\t\t%.2f", p.qntd, p.vPodEstoque);
        printf("\n-----------------------------------------------------------------\n");

    }
    printf("Valor total do estoque: R$%.2f\n", totEstoque);
    printf("Quantidade de produtos em estoque: %d\n", totProdutos);
    system("pause");
    fclose(arqvProduto);
    printf("\nEnter p sair");
    getchar();
    system("cls");
}//ok



