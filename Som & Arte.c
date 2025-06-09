#include <stdio.h>

typedef struct {
    int bandaID, ano, generoID, quantidade;
    
} CD;

CD estoque[50]; 
CD novo;

int totalCD = 0;

void cadastrarCD() {
    if (totalCD >= 50) {
        printf("Estoque cheio!\n");
        return;
    }else{
        printf("ID da banda: ");
        scanf("%d", &novo.bandaID);
        printf("Ano: ");
        scanf("%d", &novo.ano);
        printf("ID do genero: ");
        scanf("%d", &novo.generoID);
        printf("Quantidade: ");
        scanf("%d", &novo.quantidade);
        estoque[totalCD++] = novo;
        printf("CD cadastrado!\n");
    }
}

void venderCD() {
    int banda;
    printf("Digite o ID da banda para vender: ");
    scanf("%d", &banda);
    for (int i = 0; i < totalCD; ++i) {
        if (estoque[i].bandaID == banda) {
            if (estoque[i].quantidade > 0) {
                estoque[i].quantidade--;
                printf("Venda feita! Ainda tem %d CDs\n", estoque[i].quantidade);
                return;
            } else {
                printf("Sem estoque desse CD!\n");
                return;
            }
        }
    }
    printf("CD nao encontrado!\n");
}

void consultarCD() {
    int banda;
    printf("Digite o ID da banda para consultar: ");
    scanf("%d", &banda);
    for (int i = 0; i < totalCD; ++i) {
        if (estoque[i].bandaID == banda) {
            printf("CD encontrado!\n Ano: %d\n, Genero ID: %d\n, Quantidade: %d\n",
                estoque[i].ano, estoque[i].generoID, estoque[i].quantidade);
            return;
        }
    }
    printf("CD nao encontrado!\n");
}

int main() {
    int opcao;
    do {
        printf("\n-- Som & Arte --\n");
        printf("\n1 - Cadastrar CD\n");
        printf("2 - Vender CD\n");
        printf("3 - Consultar CD\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: 
                cadastrarCD(); 
                break;
            case 2: 
                venderCD(); 
                break;
            case 3: 
                consultarCD(); 
                break;
            case 0: 
                printf("Saindo...\n"); 
                break;
            default: 
            printf("Opcao invalida!\n"); 
            break;
        }
    } while (opcao != 0);
    return 0;
}
