/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: Pedro
 *
 * Created on 16 de dezembro de 2021, 21:20
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "struct.h"
#include "gestao_clientes.h"
#include "gestao_artigos.h"
#include "compras.h"
#include "extras.h"

/*
 * 
 */
int main() {
    int i, opcao_MP = 0, opcao_MA = 0, opcao_MC = 0, opcao_GC = 0, opcao_GA = 0,
            opcao_GTC = 0, opcao_RC = 0, opcao_ler = 0;

    Clientes *array_clientes = inic_clientes();

    Artigos *array_produtos = inic_produtos();

    Encomendas *array_encomendas = inic_encomendas();

    // Coloca o preço de cada produto
    precos(array_produtos);

    printf("Pretende ler/gravar dados?\n");
    printf("1- Sim 2- Nao\n");
    opcao_ler = validarInt(MSG_OBTER_OPCAO, 1, 2);

    FILE *clientes;
    FILE *artigos;
    FILE *encomendas;

    if (opcao_ler == 1) {

        // Lê o ficheiro (ler dados) 
        ler_data_clientes(array_clientes);

        // Lê o ficheiro (ler dados)        
        ler_data_artigos(array_produtos);

        // Lê o ficheiro (ler dados)
        ler_data_encomendas(array_encomendas);
    }

    do {
        printLinha();
        printf("Menu Principal");
        printLinha();
        printf("1 - Administrador");
        printf("\n2 - Cliente");
        printf("\n0 - Sair");
        printLinha();
        opcao_MP = validarInt(MSG_OBTER_OPCAO, 0, 2);

        switch (opcao_MP) {
            case 1:
                do {
                    printLinha();
                    printf("Menu Administrador");
                    printLinha();
                    printf("1 - Gestão de Clientes");
                    printf("\n2 - Gestão de Artigos");
                    printf("\n3 - Gestão das Tabelas de Custo");
                    printf("\n4 - Relatórios");
                    printf("\n0 - Sair");
                    printLinha();
                    opcao_MA = validarInt(MSG_OBTER_OPCAO, 0, 4);

                    switch (opcao_MA) {
                        case 1:
                            do {
                                printLinha();
                                printf("Gestão de Clientes");
                                printLinha();
                                printf("1 - Criar cliente");
                                printf("\n2 - Editar cliente");
                                printf("\n3 - Ativar/Inativar cliente");
                                printf("\n4 - Procurar Cliente");
                                printf("\n5 - Listar Clientes");
                                printf("\n0 - Sair");
                                printLinha();
                                opcao_GC = validarInt(MSG_OBTER_OPCAO, 0, 5);

                                switch (opcao_GC) {
                                    case 1:
                                        printLinha();
                                        printf("Criar cliente");
                                        printLinha();
                                        inserir_clientes(array_clientes);
                                        break;
                                    case 2:
                                        printLinha();
                                        printf("Editar cliente");
                                        printLinha();
                                        editar_clientes(array_clientes);
                                        break;
                                    case 3:
                                        printLinha();
                                        printf("Ativar/Inativar cliente");
                                        printLinha();
                                        mover_cliente(array_clientes);
                                        break;
                                    case 4:
                                        printLinha();
                                        printf("Procurar Cliente");
                                        printLinha();
                                        procurar_clientes(array_clientes);
                                        break;
                                    case 5:
                                        printLinha();
                                        printf("Lista de Clientes");
                                        printLinha();
                                        lista_clientes(array_clientes);
                                        break;
                                }
                            } while (opcao_GC != 0);
                            break;
                        case 2:
                            do {
                                printLinha();
                                printf("Gestão de Artigos");
                                printLinha();
                                printf("1 - Criar artigo de calçado");
                                printf("\n2 - Editar artigo de calçado");
                                printf("\n3 - Remover artigo de calçado");
                                printf("\n4 - Procurar artigo de calçado");
                                printf("\n5 - Listar artigo de calçado");
                                printf("\n0 - Sair");
                                printLinha();
                                opcao_GA = validarInt(MSG_OBTER_OPCAO, 0, 5);
                                switch (opcao_GA) {
                                    case 1:
                                        printLinha();
                                        printf("Criar Artigo");
                                        printLinha();
                                        inserir_artigo(array_produtos);
                                        break;
                                    case 2:
                                        printLinha();
                                        printf("Editar Artigo");
                                        printLinha();
                                        editar_artigos(array_produtos);
                                        break;
                                    case 3:
                                        printLinha();
                                        printf("Remover Artigo");
                                        printLinha();
                                        remover_artigo(array_produtos);
                                        break;
                                    case 4:
                                        printLinha();
                                        printf("Procurar Artigo");
                                        printLinha();
                                        procurar_artigos(array_produtos);
                                        break;
                                    case 5:
                                        printLinha();
                                        printf("Lista de Artigos");
                                        printLinha();
                                        lista_artigos(array_produtos);
                                        break;
                                }
                            } while (opcao_GA != 0);
                            break;
                        case 3:
                            do {
                                printLinha();
                                printf("Gestão das Tabelas de Custos");
                                printLinha();
                                printf("1 - Alteração do custo da mão de obra");
                                printf("\n2 - Alteração custo fixo");
                                printf("\n3 - Alteração da margem de lucro");
                                printf("\n4 - Alteração de custo associado a cada tamanho");
                                printf("\n0 - Sair");
                                printLinha();
                                opcao_GTC = validarInt(MSG_OBTER_OPCAO, 0, 4);
                                switch (opcao_GTC) {
                                    case 1:
                                        printLinha();
                                        printf("Alteração do custo de mão de obra");
                                        printLinha();
                                        alterar_preco(array_produtos->mao_obra);
                                        break;
                                    case 2:
                                        printLinha();
                                        printf("Alteração do custo fixo");
                                        printLinha();
                                        alterar_preco(array_produtos->custo_fixo);
                                        break;
                                    case 3:
                                        printLinha();
                                        printf("Alteração da margem de lucro");
                                        printLinha();
                                        alterar_preco(array_produtos->margem);
                                        break;
                                    case 4:
                                        printLinha();
                                        printf("Alteração do custo associado a cada tamanho");
                                        printLinha();
                                        alterar_preco_associado(array_produtos->custo_associado);
                                        break;
                                    case 0:
                                        break;
                                }
                            } while (opcao_GTC != 0);
                            break;
                        case 4:
                            do {
                                printLinha();
                                printf("Relatórios");
                                printLinha();
                                printf("1 - Relatório de compras");
                                printf("\n2 - Gastos de cada cliente");
                                printf("\n3 - Cliente com mais compras");
                                printf("\n4 - Quantidade comprada de artigos");
                                printf("\n5 - Artigo mais vendido");
                                printf("\n0 - Sair");
                                printLinha();
                                opcao_RC = validarInt(MSG_OBTER_OPCAO, 0, 5);
                                switch (opcao_RC) {
                                    case 1:
                                        printLinha();
                                        printf("Relatório de compras");
                                        printLinha();
                                        relatorio_compras(array_clientes, array_encomendas, array_produtos);
                                        break;
                                    case 2:
                                        printLinha();
                                        printf("Gastos de cada cliente");
                                        printLinha();
                                        relatorio_total_ganhos_cliente(array_clientes, array_encomendas, array_produtos);
                                        break;
                                    case 3:
                                        printLinha();
                                        printf("Cliente com mais compras");
                                        printLinha();
                                        relatorio_cliente_compra_mais(array_clientes, array_encomendas, array_produtos);
                                        break;
                                    case 4:
                                        printLinha();
                                        printf("Quantidade comprada de artigos");
                                        printLinha();
                                        relatorio_quantidade_comprada_artigo(array_clientes, array_encomendas, array_produtos);
                                        break;
                                    case 5:
                                        printLinha();
                                        printf("Artigo mais vendido");
                                        printLinha();
                                        artigo_mais_comprado(array_produtos);
                                        break;
                                }
                            } while (opcao_RC != 0);
                            break;
                        case 0:
                            break;
                    }
                } while (opcao_MA != 0);
                break;
            case 2:
                do {
                    printLinha();
                    printf("Menu Cliente");
                    printLinha();
                    printf("1 - Login");
                    printf("\n0 - Sair");
                    printLinha();
                    opcao_MC = validarInt(MSG_OBTER_OPCAO, 0, 1);

                    switch (opcao_MC) {
                        case 1:
                            printLinha();
                            printf("Menu Cliente");
                            printLinha();
                            printf("Encomenda");
                            printLinha();
                            cria_encomenda(array_produtos, array_clientes, array_encomendas);
                            break;
                        case 0:
                            break;
                    }
                } while (opcao_MC != 0);
                break;
            case 0:
                break;
        }
    } while (opcao_MP != 0);


    if (opcao_ler == 1) {
        FILE *tabela_precos;
        tabela_precos = fopen("tabeladecustos.txt", "w");
        
        int i = 0;
        for (i = 0; i < 3; i++) {
            (fprintf(tabela_precos, "%g;%g;%g;%g;%g;%g;%g;%g;%g;%g;%g;%g;%g;%g;%g;%g;%g;%g\n",
                    (array_produtos->mao_obra[i]),
                    (array_produtos->custo_fixo[i]),
                    (array_produtos->custo_associado[i][0]),
                    (array_produtos->custo_associado[i][1]),
                    (array_produtos->custo_associado[i][2]),
                    (array_produtos->custo_associado[i][3]),
                    (array_produtos->custo_associado[i][4]),
                    (array_produtos->custo_associado[i][5]),
                    (array_produtos->custo_associado[i][6]),
                    (array_produtos->custo_associado[i][7]),
                    (array_produtos->custo_associado[i][8]),
                    (array_produtos->custo_associado[i][9]),
                    (array_produtos->custo_associado[i][10]),
                    (array_produtos->custo_associado[i][11]),
                    (array_produtos->custo_associado[i][12]),
                    (array_produtos->custo_associado[i][13]),
                    (array_produtos->custo_associado[i][14]),
                    (array_produtos->margem[i])));
        }        
        fclose(tabela_precos);

        // Escreve no ficheiro (grava dados)
        clientes = fopen("clientes.txt", "w");

        for (i = 0; i < array_clientes->conta_clientes; i++) {
            fprintf(clientes, "%d %s %d %s %d %d\n",
                    (array_clientes->clientes[i]->codigo_cliente),
                    (array_clientes->clientes[i]->nome_cliente),
                    (array_clientes->clientes[i]->nif),
                    (array_clientes->clientes[i]->pais),
                    (array_clientes->clientes[i]->atividade),
                    (array_clientes->clientes[i]->comprado));

            free(array_clientes->clientes[i]); // cada cliente do array cliente
        }
        fclose(clientes);

        // Escreve no ficheiro (grava dados)
        artigos = fopen("artigos.txt", "w");

        for (i = 0; i < array_produtos->conta_artigos; i++) {
            fprintf(artigos, "%d %s %.2f %d %d\n",
                    (array_produtos->artigos[i]->id_artigo),
                    (array_produtos->artigos[i]->nome_artigo),
                    (array_produtos->artigos[i]->preco_artigo),
                    (array_produtos->artigos[i]->tipo),
                    (array_produtos->artigos[i]->comprado));

            free(array_produtos->artigos[i]);
        }
        fclose(artigos);

        encomendas = fopen("encomendasdata.txt", "w");

        for (i = 0; i < array_encomendas->conta_encomendas; i++) {
            fprintf(encomendas, "%d %s %d %d %.2f %d\n",
                    (array_encomendas->encomendas[i]->cod_cliente),
                    (array_encomendas->encomendas[i]->nome_cliente),
                    (array_encomendas->encomendas[i]->quantidade),
                    (array_encomendas->encomendas[i]->tam),
                    (array_encomendas->encomendas[i]->preco_total),
                    (array_encomendas->encomendas[i]->id_artigo));

            free(array_encomendas->encomendas[i]->nome_cliente);
            free(array_encomendas->encomendas[i]);
        }
        fclose(encomendas);
    }

    // Liberta o bloco de memória apontado por:  
    free(array_clientes->clientes); // array cliente
    free(array_clientes); // struct clientes

    // Liberta o bloco de memória apontado por:
    free(array_produtos->artigos); // array artigo
    free(array_produtos); // struct artigos

    free(array_encomendas->encomendas);
    free(array_encomendas);
    return (0);
}