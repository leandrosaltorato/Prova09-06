#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int quantidade;
    float preco;
} Produto;

Produto produto;

void cadastrarProduto() {
    printf("-- Cadastro de Produto --\n");
    printf("Nome do produto : ");
    scanf("%s", produto.nome);  
    printf("Quantidade no estoque: ");
    scanf("%d", &produto.quantidade);
    printf("Preço do produto: R$ ");
    scanf("%f", &produto.preco);
    printf("\033[32m");
    printf("\nProduto cadastrado com sucesso!\n");
    printf("\033[0m");
    printf ("\n Enter para continuar");
    getchar (); 
    getchar (); 
    system("clear");
}


void mostrarProduto() {
    if (produto.quantidade < 0) {
        printf("Nenhum produto cadastrado ainda.\n\n");
        return;
    }
    printf("-- Dados do Produto --\n");
    printf("Nome: %s\n", produto.nome);
    printf("Quantidade no estoque: %d\n", produto.quantidade);
    printf("Preço do produto: R$ %.2f\n\n", produto.preco);
}

void realizarCompra() {
    if (produto.quantidade < 0) {
        printf("Nenhum produto cadastrado ainda.\n\n");
    }
    int quantidadeComprada;
    printf("- Realizar Compra -\n");
    printf("Quantidade de produtos: ");
    scanf("%d", &quantidadeComprada);

    if (quantidadeComprada <= 0) {
        printf("Quantidade inválida.\n");
    } else if (quantidadeComprada > produto.quantidade) {
        printf("Estoque insuficiente. Estoque atual: %d\n\n", produto.quantidade);
    } else {
        produto.quantidade = produto.quantidade - quantidadeComprada;
        float total = quantidadeComprada * produto.preco;
        printf("Compra realizada com sucesso! Total: R$ %.2f\n", total);
        printf("Estoque restante: %d\n\n", produto.quantidade);
    printf ("\n Enter para continuar");
    getchar (); 
    getchar (); 
    system("clear");
    }
}

int main() {
    produto.quantidade = 0;
    int opcao;

    do {
        printf("Supermercado SuperMais\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Visualizar Produto\n");
        printf("3. Realizar Compra\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                mostrarProduto();
                break;
            case 3:
                realizarCompra();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n\n");
        }
    } while(opcao != 0);

    return 0;
}

