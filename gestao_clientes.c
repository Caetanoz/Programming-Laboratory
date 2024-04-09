/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   gestao_clientes.c
 * Author: Pedro
 *
 * Created on 19 de dezembro de 2021, 16:15
 */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "input.h"
#include "gestao_clientes.h"

/*
 * 
 */
#define MAX_CODIGO 999999
#define MAX_NOME 100
#define MAX_NIF 999999999
#define MIN_NIF 100000000

/**
 * Verifica o código do cliente 
 * @param apt_verificar Apondador para a struct Clientes
 * @param cod_cliente Recebe o código a verificar
 * @return a posição do cliente caso não exista ou -1 caso exista
 */
int verificar_codigo(Clientes *apt_verificar, int cod_cliente) {
    /*
     * Verificar se o código de cliente se existe ou não. 
     */
    int i;
    int tam = apt_verificar->conta_clientes;

    for (i = 0; i < tam; i++) { // ciclo que percorre o conta_cliente
        if (apt_verificar->clientes[i] != NULL && apt_verificar->clientes[i]->codigo_cliente == cod_cliente) {
            return i; // O código está associado retorna i (índice de clientes)
        }
    }
    return -1; // NÃO EXISTE (O código não está associado)  
}

/**
 * Aloca memória para um Cliente
 * @return cliente
 */
Cliente * inic_cliente() {
    Cliente *apt_cliente;

    apt_cliente = (Cliente *) malloc(sizeof (Cliente));
    if (apt_cliente == NULL) {
        perror("Erro a alocar memória para cliente!"); // perror faz printf e exit
    }
    apt_cliente->atividade = ativo;
    return apt_cliente;
}

/**
 * Cria um Cliente
 * @param apt_cliente apontador para a struct Clientes
 * @return número de clientes que ficam depois de adicionar
 */
int criar_cliente(Clientes *apt_cliente) {
    /*
     * código de cliente
     * nome de cliente 
     * nif
     * pais    
     */
    int cod_cliente;
    cod_cliente = obterInt(0, MAX_CODIGO, "Insira o código de cliente: ");

    int indice;
    indice = verificar_codigo(apt_cliente, cod_cliente);

    if (indice == -1) { // se o código de cliente não estiver associado continua.
        Cliente *cliente;

        if (apt_cliente->clientes[apt_cliente->conta_clientes] == NULL) { // posição de memoria ja esta locada ou nao // SE NÃO TIVER
            cliente = inic_cliente();
        } else {
            cliente = apt_cliente->clientes[apt_cliente->conta_clientes]; // SE tiver alocada
            cliente->atividade = ativo;
        }

        if (apt_cliente->conta_clientes == apt_cliente->max_clientes) {
            apt_cliente->max_clientes <<= 1; // multiplica o numero por dois
            apt_cliente->clientes = realloc(apt_cliente->clientes, sizeof (Cliente **)
                    * apt_cliente->max_clientes);
        }

        cliente->codigo_cliente = cod_cliente;

        lerString(cliente->nome_cliente, MAX_NOME,
                "Insira o nome do cliente: "); // destino para guardar o nome/ tamanho máximo/ mensagem

        cliente->nif = obterInt(MIN_NIF, MAX_NIF,
                "Inserir o NIF do cliente: "); // destino para guardar o NIF

        lerString(cliente->pais, MAX_NOME,
                "Insira o País do cliente: "); // destino para guardar o País/ tamanho máximo/ mensagem 

        cliente->comprado = 0;

        apt_cliente->clientes[apt_cliente->conta_clientes] = cliente;

        return ++(apt_cliente->conta_clientes); 
    } 
    return -1;
}

/**
 * Lê os dados guardados em "clientes.txt"
 * @param array_clientes apontador para a struct Clientes
 */
void ler_data_clientes(Clientes *array_clientes) {
    FILE *clientes = fopen("clientes.txt", "r");

    if (clientes != NULL) {
        array_clientes->clientes[array_clientes->conta_clientes] = (Cliente*) malloc(sizeof (Cliente));

        while (fscanf(clientes, "%d %s %d %s %d %d\n",
                &(array_clientes->clientes[array_clientes->conta_clientes]->codigo_cliente),
                (array_clientes->clientes[array_clientes->conta_clientes]->nome_cliente),
                &(array_clientes->clientes[array_clientes->conta_clientes]->nif),
                (array_clientes->clientes[array_clientes->conta_clientes]->pais),
                &(array_clientes->clientes[array_clientes->conta_clientes]->atividade),
                &(array_clientes->clientes[array_clientes->conta_clientes]->comprado)) != EOF) {

            array_clientes->conta_clientes++;
            array_clientes->clientes[array_clientes->conta_clientes] = (Cliente*) malloc(sizeof (Cliente));
        }
        fclose(clientes);
    }
}

/**
 * Verifica a existência de Clientes 
 * @param apt_clientes apontador para a struct Clientes
 */
void inserir_clientes(Clientes *apt_clientes) {
    if (criar_cliente(apt_clientes) == -1) { 
        printf("O cliente já existe!");
    }
}

/**
 * Aloca memória para os Clientes
 * @return array_clientes
 */
Clientes *inic_clientes() {
    Clientes *array_clientes;
    array_clientes = (Clientes *) malloc(sizeof (Clientes));
    if (array_clientes == NULL) {
        perror("Erro a alocar memória para cliente!"); // perror faz printf e exit
    }
    array_clientes->max_clientes = 30;

    array_clientes->clientes = (Cliente **) malloc(sizeof (Cliente*) *
            array_clientes->max_clientes);
    if (array_clientes->clientes == NULL) {
        perror("Erro a alocar memória para clientes!"); // perror faz printf e exit
    }
    array_clientes->conta_clientes = 0;

    for (int i = 0; i < array_clientes->max_clientes; i++) { //inicializa tudo a NULL
        array_clientes->clientes[i] = NULL;
    }
    return array_clientes;

}

/**
 * Imprime o cliente no formato Código_Cliente Nome NIF País Estado
 * @param apt_imprimir apontador para a struct Cliente
 */
void imprimir_cliente(Cliente *apt_imprimir) {
    /*
     * Imprimir cliente no formato: código_cliente nome_cliente nif pais 
     */
    char *estado;
    if (apt_imprimir->atividade == inativo)
        estado = "Inativo";
    else
        estado = "Ativo";

    printf("\n%3d %-30s %d %-30s %s", apt_imprimir->codigo_cliente, apt_imprimir->nome_cliente,
            apt_imprimir->nif, apt_imprimir->pais, estado);
}

/**
 * Faz uma listagem dos clientes que existem usando a função imprimir_cliente
 * @param lista apontador para a struct Clientes
 */
void lista_clientes(Clientes *lista) {
    if (lista->conta_clientes > 0) {
        int i;
        for (i = 0; i < lista->conta_clientes; i++) {
            imprimir_cliente(lista->clientes[i]);
        }
    } else {
        printf("Lista Vazia!");
    }
}

/**
 * Procura o cliente e imprime o mesmo se existir
 * @param apt_cliente apontador para a struct Clientes
 */
void procurar_clientes(Clientes *apt_cliente) {
    int cod_cliente;

    cod_cliente = verificar_codigo(apt_cliente, obterInt(0, MAX_CODIGO,
            "Insira o código do cliente: "));

    if (cod_cliente != -1) { // -1 não existe cliente
        imprimir_cliente(apt_cliente->clientes[cod_cliente]);
    } else {
        printf("Este cliente não existe!");
    }
}

/**
 * Edita o cliente pedindo um novo nome, NIF e país
 * @param apt_editar
 */
void editar_cliente(Cliente *apt_editar) {
    /* 
     * Novo código do cliente
     * Novo nome do cliente
     * Novo NIF do cliente
     * Novo País do cliente
     */

    lerString(apt_editar->nome_cliente, MAX_NOME, "Insira o novo nome do Cliente: ");
    apt_editar->nif = obterInt(MIN_NIF, MAX_NIF, "Insira o novo NIF do Cliente: ");
    lerString(apt_editar->pais, MAX_NOME, "Insira o novo País do Cliente: ");
}

/**
 * Edita o cliente caso ele exista
 * @param apt_editar apontador para a struct Clientes
 */
void editar_clientes(Clientes *apt_editar) {
    int cod_cliente;

    cod_cliente = verificar_codigo(apt_editar, obterInt(0, MAX_CODIGO,
            "Insira o código do cliente: "));

    if (cod_cliente != -1) {
        editar_cliente(apt_editar->clientes[cod_cliente]);
    } else {
        printf("Este Cliente não existe!");
    }
}

/**
 * Coloca o cliente a Ativo ou Inativo conforme o seu estado anterior 
 * @param apt_editar apontador para a struct Clientes
 */
void mover_cliente(Clientes *apt_editar) {
    /*
     * colocar inativo ou ativo   
     */
    int cod_cliente;

    cod_cliente = verificar_codigo(apt_editar, obterInt(0, MAX_CODIGO,
            "Insira o código do cliente: "));

    if (cod_cliente != -1) {

        int escolha = obterInt(0, 1, "Atividade: 0 - Inativo 1 - Ativo ");

        if (escolha == 0) {
            if (apt_editar->clientes[cod_cliente]->atividade != inativo) {
                apt_editar->clientes[cod_cliente]->atividade = inativo;
                printf("Cliente inativado com sucesso!");
            } else {
                printf("Este cliente já está Inativo.");
            }
        } else {
            if (apt_editar->clientes[cod_cliente]->atividade != ativo) {
                apt_editar->clientes[cod_cliente]->atividade = ativo;
                printf("Cliente ativado com sucesso!");
            } else {
                printf("Este cliente já está Ativo.");
            }
        }
    } else {
        printf("Este Cliente não existe!");
    }
}