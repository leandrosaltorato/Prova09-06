#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char banda[50];
    int quant, ano, generoID;
    float preco;
} CD;

CD vendacd[100];
int numVenda = 0; 

void cadastrarCD() {
    if (numVenda >= 100) {
        printf("Limite de CDs atingido.\n");
        return;
    }

    printf("-- Cadastro de CD --\n");
    printf("Nome da Banda: ");
    scanf("%s", vendacd[numVenda].banda);  
    printf("Ano: ");
    scanf("%d", &vendacd[numVenda].ano);  
    printf("ID do genero: ");
    scanf("%d", &vendacd[numVenda].generoID);  
    printf("Quantidade no estoque: ");
    scanf("%d", &vendacd[numVenda].quant);
    printf("Preço do produto: R$ ");
    scanf("%f", &vendacd[numVenda].preco);
    
    printf("\033[32m");
    printf("\nProduto cadastrado com sucesso!\n");
    printf("\033[0m");
    
    numVenda++; 
}

void venderCD() {
    if (numVenda == 0) {
        printf("Nenhum produto cadastrado ainda.\n");
        return;
    }
    int quantComprada;
    printf("- Realizar Compra -\n");
    printf("Quantidade de produtos: ");
    scanf("%d", &quantComprada);

    if (quantComprada <= 0) {
        printf("Quantidade inválida.\n");
    } else if (quantComprada > vendacd[0].quant) {
        printf("Estoque insuficiente. Estoque atual: %d\n", vendacd[0].quant);
    } else {
        vendacd[0].quant -= quantComprada; 
        float total = quantComprada * vendacd[0].preco;
        printf("Compra realizada com sucesso! Total: R$ %.2f\n", total);
        printf("Estoque restante: %d\n", vendacd[0].quant);
    }
    
    printf("\nPressione Enter para continuar...");
    getchar(); 
    getchar(); 
    system("clear");
}

void generoporCD() {
    int id;
    printf("Digite o ID do genero: ");
    scanf("%d", &id);
    
    for (int i = 0; i < numVenda; i++) {
        if (vendacd[i].generoID == id) {
            printf("Nome da Banda: %s\n", vendacd[i].banda);  
            printf("Ano: %d\n", vendacd[i].ano);  
            printf("ID do genero: %d\n", vendacd[i].generoID);  
            printf("Quantidade no estoque: %d\n", vendacd[i].quant);
            printf("Preço do produto: R$ %.1f\n", vendacd[i].preco);
            printf("-----------------------------\n");
        }
    }
    printf("\nPressione Enter para continuar...");
    getchar(); 
    getchar(); 
    system("clear");
}

int main() {
    int opcao;

    do {
        printf("--- Som & Arte ---\n");
        printf("1. Cadastrar CD\n");
        printf("2. Vender CD\n");
        printf("3. CD por Genero\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao) {
            case 1:
                cadastrarCD();
                break;
            case 2:
                venderCD();
                break;
            case 3:
                generoporCD();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while(opcao != 0);

    return 0;
}
