/*INTEGRANTES
João Pedro Alves Notari Godoy
Pedro Louro Fernandes
Letícia Barbosa Neves*/

// SISTEMA DE MERCADO

#include <stdio.h>
#include <stdlib.h>

// Definição da struct que conterá cada produto

struct Produto {
    int codigo;
    char nome[21];
    int quantidade;
    double preco;
};
typedef struct Produto produto;


// Funções para cada comando (cada função abrirá e depois fechará o arquivo que contém os produtos)


// Função Insere Produto (IP_<nome>_<quantidade>_<preço>)
void InsereProduto() {
    char nome[21];
    int quantidade;
    float preco;
    scanf("%s %d %f", nome, &quantidade, &preco);

}
// Função Aumenta Estoque (AE_<código>_<quantidade>)

// Função Modifica Preço (MP_<código>_<preço>)

// Função Venda (VE_<código>_<código>_..._<código>_<-1>)

// Função Consulta Estoque (CE)
void ConsultaEstoque(FILE *estoque) {
    char c;
    estoque = fopen("estoque.txt", "r");
    while (fscanf(estoque, %c, &c) != EOF) {
        printf("%c", c);
    }
}
// Função Consulta Saldo (CS)
void ConsultaSaldo(void) {
}
// Função Finaliza a execução (FE)


int main () {
    FILE *estoque;
    FILE *saldo;
    int TamanhoEstoque;


// Verifica se o arquivo do estoque já existe
    if ((estoque = fopen("estoque.txt", "r")) == 0) {

// Inserir tamanho do estoque
        printf("Digite o tamanho do estoque: ");
        scanf("%d", &TamanhoEstoque);
        estoque = fopen("estoque.txt", "w");
        produto *EstoqueProdutos;
        EstoqueProdutos = (produto *) malloc(TamanhoEstoque * sizeof(produto));
        fclose(estoque);
        
        saldo = fopen("saldo.txt", "w");
        fclose(saldo);
        float saldo = 100;
    }


    char entrada[3];

    


// abertura do loop com leitura dos comandos, até chegar ao fim do input
    while(1) {
        scanf("%s", entrada);

// série de if para saber qual o comando a ser realizado

        if (strcmp(entrada, "IP") == 0) {
            InsereProduto();
        }

        if (strcmp(entrada, "AE") == 0) {
            AumentaEstoque();
        }

        if (strcmp(entrada, "MP") == 0) {
            ModificaPreco();
        }

        if (strcmp(entrada, "VE") == 0) {
            Venda();
        }

        if (strcmp(entrada, "CE") == 0) {
            ConsultaEstoque(&estoque);
        }

        if (strcmp(entrada, "CS") == 0) {
            ConsultaSaldo();
        }

        if (strcmp(entrada, "FE") == 0) {
            break;
        }

        

// para cada comando, uma função é chamada, realizando a leitura específica do comando
    }

    return 0;
}