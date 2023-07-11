/*INTEGRANTES
João Pedro Alves Notari Godoy
Pedro Louro Fernandes
Letícia Barbosa Neves*/

// SISTEMA DE MERCADO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct que conterá cada produto

struct Produto {
    int codigo;
    char nome[21];
    int quantidade;
    float preco;
};
typedef struct Produto produto;


// Funções para cada comando (cada função abrirá e depois fechará o arquivo que contém os produtos)


// Função Insere Produto (IP_<nome>_<quantidade>_<preço>)
void InsereProduto(produto ***p, int TamanhoEstoque) {
    (*p) = (produto **) realloc(*p, (TamanhoEstoque * sizeof(produto *)));
    (*p)[TamanhoEstoque - 1] = (produto *) malloc(sizeof(produto));
    char Nome[21];
    int Quantidade;
    float Preco;

    // Leitura em ordem das variáveis de cada produto
    scanf("%s %d %f", Nome, &Quantidade, &Preco);

    // Preenchimento dos dados desse produto no vetor dinamicamente alocado de produtos
    (*p)[TamanhoEstoque - 1]->codigo = TamanhoEstoque - 1;
    strcpy((*p)[TamanhoEstoque - 1]->nome, Nome);
    (*p)[TamanhoEstoque - 1]->quantidade = Quantidade;
    (*p)[TamanhoEstoque - 1]->preco = Preco;


}
// Função Aumenta Estoque (AE_<código>_<quantidade>)
void AumentaEstoque(produto ***p) {
    int CodigoAlterar;
    int NovoEstoque;
    scanf("%d", &CodigoAlterar);
    scanf("%d", &NovoEstoque);
    (*p)[CodigoAlterar]->quantidade = NovoEstoque;
}

// Função Modifica Preço (MP_<código>_<preço>)

// Função Venda (VE_<código>_<código>_..._<código>_<-1>)

// Função Consulta Estoque (CE)
void ConsultaEstoque(produto ***p, int TamanhoEstoque) {
    for (int i = 0; i < TamanhoEstoque; i++) {
        printf("%d %s %d %.2f\n", (*p)[i]->codigo, (*p)[i]->nome, (*p)[i]->quantidade, (*p)[i]->preco);
    }
}
// Função Consulta Saldo (CS)
void ConsultaSaldo(void) {
}
// Função Finaliza a execução (FE)


int main () {
    FILE *ArquivoEstoque;
    int TamanhoEstoque = 0;
    float Saldo;

    produto **EstoqueProdutos;


// Verifica se o arquivo do estoque já existe
    if ((ArquivoEstoque = fopen("estoque.bin", "rb")) == 0) {

// Se não existir, inserir tamanho do estoque
        scanf("%d", &TamanhoEstoque);
        TamanhoEstoque = 0;
        scanf("%f", &Saldo);
        ArquivoEstoque = fopen("estoque.bin", "wb");
        fclose(ArquivoEstoque);
        // É criado um array de ponteiros para produto, e tudo é alocado dinamicamente
        EstoqueProdutos = (produto **) malloc(TamanhoEstoque * sizeof(produto *));
        for (int i = 0; i < TamanhoEstoque; i++) {
            EstoqueProdutos[i] = (produto *) malloc(sizeof(produto));
        }
    } else {
// Se existe, lê o saldo armazenado no arquivo e o tamanho, que são os dois primeiros valores (float e inteiro)
            fscanf(ArquivoEstoque, "%d", &TamanhoEstoque);
            fscanf(ArquivoEstoque, "%f", &Saldo);
            // É criado um array de ponteiros para produto, e tudo é alocado dinamicamente
            EstoqueProdutos = (produto **) malloc(TamanhoEstoque * sizeof(produto *));
            for (int i = 0; i < TamanhoEstoque; i++) {
                EstoqueProdutos[i] = (produto *) malloc(sizeof(produto));
            }
            for (int i = 0; i < TamanhoEstoque; i++) {
                fscanf(ArquivoEstoque, "%d", &EstoqueProdutos[i]->codigo);
                fscanf(ArquivoEstoque, "%s", EstoqueProdutos[i]->nome);
                fscanf(ArquivoEstoque, "%d", &EstoqueProdutos[i]->quantidade);
                fscanf(ArquivoEstoque, "%f", &EstoqueProdutos[i]->preco);
            }
            printf("Tamanho estoque: %d, Saldo: %.2f\n", TamanhoEstoque, Saldo);
        }




        


        


    char entrada[3];

    


// abertura do loop com leitura dos comandos, até chegar ao fim do input
    while(1) {
        scanf("%s", entrada);

// série de if para saber qual o comando a ser realizado

        if (strcmp(entrada, "IP") == 0) {
            TamanhoEstoque++;
            InsereProduto(&EstoqueProdutos, TamanhoEstoque);
        }

        if (strcmp(entrada, "AE") == 0) {
            AumentaEstoque(&EstoqueProdutos);
        }
/*
        if (strcmp(entrada, "MP") == 0) {
            ModificaPreco();
        }

        if (strcmp(entrada, "VE") == 0) {
            Venda();
        }
        */

        if (strcmp(entrada, "CE") == 0) {
            ConsultaEstoque(&EstoqueProdutos, TamanhoEstoque);
        }
/*
        if (strcmp(entrada, "CS") == 0) {
            ConsultaSaldo();
        }
*/
        if (strcmp(entrada, "FE") == 0) {
            break;
        }

        

// para cada comando, uma função é chamada, realizando a leitura específica do comando
    }

    ArquivoEstoque = fopen("estoque.bin", "wb");
    fprintf(ArquivoEstoque, "%d %f ", TamanhoEstoque, Saldo);


    for (int i = 0; i < TamanhoEstoque; i++) {
        fprintf(ArquivoEstoque, "%d %s %d %f ", EstoqueProdutos[i]->codigo, EstoqueProdutos[i]->nome, EstoqueProdutos[i]->quantidade, EstoqueProdutos[i]->preco);
    }
    fclose(ArquivoEstoque);

    for (int i = 0; i < TamanhoEstoque; i++) {
        free(EstoqueProdutos[i]);
    }
    free(EstoqueProdutos);
    free(ArquivoEstoque);
    return 0;
}