#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float preco;
    int idd;
} Pizza;

Pizza pizza[100];
int numPizza = 0; 

typedef struct {
    char name[50];
    int id;
} Cliente;

Cliente cliente[100];
int numCliente = 0;

void cadastrarPizza() {
    printf("-- Cadastro de Pizzas --\n");
    printf("Nome da Pizza: ");
    scanf("%s", pizza[numPizza].nome);  
    printf("Preço da Pizza : R$ ");
    scanf("%f", &pizza[numPizza].preco);
    printf("ID da Pizza : ");
    scanf("%d", &pizza[numPizza].idd);
    
    printf("\033[32m");
    printf("Pizza cadastrada com sucesso!\n");
    printf("\033[0m");
    numPizza++; 
}

void cadastrarCliente() {
    printf("-- Cadastro do Cliente --\n");
    printf("Nome do Cliente: ");
    scanf("%s", cliente[numCliente].name);  
    printf("Crie seu ID: ");
    scanf("%d", &cliente[numCliente].id);
    
    printf("\033[32m");
    printf("Cliente cadastrado com sucesso!\n");
    printf("\033[0m");
    numCliente++; 
}
    
void listarPizzas() {
    printf("----- Pizzas Cadastrados -----\n");
    for(int i = 0; i < numPizza; i++) {
        printf("Nome da pizza : %s\n", pizza[i].nome);
        printf("Preço : %.1f\n", pizza[i].preco);
        printf("ID da Pizza : %d", pizza[i].idd);
        printf("\n-----------------------------\n");
    }
}
    
void listarCliente() {
    printf("----- Clientes Cadastrados -----\n");
    for(int i = 0; i < numCliente; i++) {
        printf("Nome do Cliente : %s\n", cliente[i].name);
        printf("ID : %d\n", cliente[i].id);
        printf("\n-----------------------------\n");
    }
}

void venderPizza() {
    if (numCliente == 0) {
        printf("Nenhum cliente cadastrado. Cadastre um cliente primeiro.\n");
        return;
    }
    if (numPizza == 0) {
        printf("Nenhuma pizza cadastrada. Cadastre uma pizza primeiro.\n");
        return;
    }

    int clienteId;
    printf("Digite o ID do cliente: ");
    scanf("%d", &clienteId);
    
    int clienteEncontrado = 0;
    for (int i = 0; i < numCliente; i++) {
        if (cliente[i].id == clienteId) {
            clienteEncontrado = 1;
            printf("Cliente encontrado =) \n");
            break;
        }
    }
    if (!clienteEncontrado) {
        printf("Cliente não cadastrado =(\n");
        return;
    }
    
    
    int pizzaId;
    printf("Digite o ID da pizza que você deseja: ");
    scanf("%d", &pizzaId);
    
    int pizzaEncontrado = 0;
    for (int i = 0; i < numPizza; i++) {
        if (pizza[i].idd == pizzaId) {
            pizzaEncontrado = 1;
            printf("Pizza cadastrada =) \n");
            break;
        }
    }
    if (!pizzaEncontrado) {
        printf("Pizza não está na lista de cadastros =(\n");
        return;
    }

    float total = 0.0f;
    
    int quantidade;
    printf("Digite a quantidade desejada da pizza \"%s\": ", pizza[pizzaEncontrado].nome);
    if (scanf("%d", &quantidade) != 1 || quantidade <= 0) {
        printf("Quantidade inválida. Tente novamente.\n");
        return;
    }
    total += pizza[pizzaEncontrado].preco * quantidade;
    printf("Total a pagar: R$ %.2f\n", total);
}

int main() {
    int opcao;
    do {
        printf("===== Nostra Pizza =====\n");
        printf("1. Cadastrar Pizza\n");
        printf("2. Cadastrar Cliente\n");
        printf("3. Listar Pizzas\n");
        printf("4. Listar Clientes\n");
        printf("5. Vender Pizza\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao) {
            case 1: 
                cadastrarPizza(); 
                break;
            case 2: 
                cadastrarCliente(); 
                break;
            case 3: 
                listarPizzas(); 
                break;
            case 4: 
                listarCliente(); 
                break;
            case 5: 
                venderPizza(); 
                break;
            case 0: 
                printf("Saindo...\n"); 
                break;
            default: 
            printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
