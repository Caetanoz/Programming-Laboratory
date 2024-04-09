/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   extras.c
 * Author: Pedro
 *
 * Created on 1 de janeiro de 2022, 16:54
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "struct.h"
#include "extras.h"
#include "compras.h"
#include "gestao_artigos.h"
#include "gestao_clientes.h"

/**
 * Apresenta uma lista das compras realizadas
 * @param clientes apontador para a struct Clientes
 * @param encomendas apontador para a struct Encomendas
 * @param artigos apontador para a struct Artigos
 */
void relatorio_compras(Clientes *clientes, Encomendas *encomendas, Artigos *artigos) {
    FILE * ficheiro;
    ficheiro = fopen("Relatorios_Compras.txt", "w");

    if (ficheiro != NULL) {
        if (clientes->conta_clientes != 0) {
            printf("\n#########################");
            printf("\n Consultar Compras ");

            for (int i = 0; i < clientes->conta_clientes; i++) {
                for (int j = 0; j < encomendas->conta_encomendas; j++) {
                    if (clientes->clientes[i]->codigo_cliente == encomendas->encomendas[j]->cod_cliente) {
                        printf("\n#########################");
                        printf("\nCódigo %d Cliente %s com nif %d", clientes->clientes[i]->codigo_cliente, clientes->clientes[i]->nome_cliente, clientes->clientes[i]->nif);

                        for (int p = 0; p < artigos->conta_artigos; p++) {
                            if (encomendas->encomendas[j]->id_artigo == artigos->artigos[p]->id_artigo) {
                                printf("\n-----------------------");
                                if (fprintf(ficheiro, "-----------------------\n") < 0) {
                                    printf("\n Aconteceu algum erro 1");
                                }
                                printf("\n Id do artigo -> %d", artigos->artigos[p]->id_artigo);
                                if (fprintf(ficheiro, "Id do artigo -> %d \n", artigos->artigos[p]->id_artigo) < 0) {
                                    printf("\n Aconteceu algum erro 2");
                                }
                                printf("\n Nome do artigo -> %s", artigos->artigos[p]->nome_artigo);
                                if (fprintf(ficheiro, "Nome do artigo -> %s \n", artigos->artigos[p]->nome_artigo) < 0) {
                                    printf("\n Aconteceu algum erro 3");
                                }
                                printf("\n Preco do artigo (um par tamanho 41)-> %.2f", artigos->artigos[p]->preco_artigo); // encomendas->encomendas[p]->preco_total
                                if (fprintf(ficheiro, "Preco do artigo (um par tamanho 41)-> %.2f \n", artigos->artigos[p]->preco_artigo) < 0) {
                                    printf("\n Aconteceu algum erro 4");
                                }
                                printf("\n Quantidade pedida -> %d", encomendas->encomendas[j]->quantidade);
                                if (artigos->artigos[p]->tipo == sapato) {//sapato=0, sandalia=1, bota=2
                                    printf("\n Tipo do artigo -> Sapato ");
                                    if (fprintf(ficheiro, "Tipo do artigo -> Sapato \n") < 0) {
                                        printf("\n Aconteceu algum erro 5");
                                    }
                                } else if (artigos->artigos[p]->tipo == sandalia) {
                                    printf("\n Tipo do artigo -> Sandália");
                                    if (fprintf(ficheiro, "Tipo do artigo -> Sandália \n") < 0) {
                                        printf("\n Aconteceu algum erro 6");
                                    }
                                } else {
                                    printf("\n Tipo do artigo -> Bota");
                                    if (fprintf(ficheiro, "Tipo do artigo -> Bota \n") < 0) {
                                        printf("\n Aconteceu algum erro 7");
                                    }
                                }
                            }
                        }
                        printf("\n||||||");
                        printf("\n Total a pagar : %.2f €", encomendas->encomendas[j]->preco_total);
                        printf("\n||||||\n");
                        if (fprintf(ficheiro, "Total a pagar : %.2f € \n", encomendas->encomendas[j]->preco_total) < 0) {
                            printf("\n Aconteceu algum erro 8\n");
                        }
                    }
                }
            }
        } else {
            printf("Não existem clientes!");
        }
    }
    fclose(ficheiro);
}

/**
 * Apresenta os gastos de cada cliente
 * @param apt_clientes apontador para a struct Clientes
 * @param encomendas apontador para a struct Encomendas
 * @param apt_artigos apontador para a struct Artigos
 */
void relatorio_total_ganhos_cliente(Clientes *apt_clientes, Encomendas *encomendas, Artigos *apt_artigos) {
    FILE * f_ganhos_cliente;
    f_ganhos_cliente = fopen("Relatorio_total_ganhos_cliente.txt", "w");

    float total = 0;
    if (f_ganhos_cliente != NULL) {
        if (apt_clientes->conta_clientes != 0) {
            printf("\n################################");
            printf("\n Consultar Compras ");
            for (int i = 0; i < apt_clientes->conta_clientes; i++) {
                total = 0;
                for (int j = 0; j < encomendas->conta_encomendas; j++) {
                    if (apt_clientes->clientes[i]->codigo_cliente == encomendas->encomendas[j]->cod_cliente) {

                        total += encomendas->encomendas[j]->preco_total;
                    }
                }
                printf("\n################################");
                if (fprintf(f_ganhos_cliente, "################################ \n") < 0) {
                    printf("\n Aconteceu algum erro 1");
                }
                printf("\n Cliente %s com nif %d", apt_clientes->clientes[i]->nome_cliente, apt_clientes->clientes[i]->nif);
                if (fprintf(f_ganhos_cliente, "Cliente %s com nif %d \n", apt_clientes->clientes[i]->nome_cliente, apt_clientes->clientes[i]->nif) < 0) {
                    printf("\n Aconteceu algum erro 2");
                }
                printf("\n||||||");
                if (fprintf(f_ganhos_cliente, "||||||| \n") < 0) {
                    printf("\n Aconteceu algum erro 3");
                }
                printf("\n Total de gastos : %.2f €", total);
                if (fprintf(f_ganhos_cliente, "Total de gastos : %.2f € \n", total) < 0) {
                    printf("\n Aconteceu algum erro 4");
                }
                printf("\n||||||");
            }
        } else {
            printf("Não existem clientes!");
        }
    }
    fclose(f_ganhos_cliente);
}

/**
 * Apresenta o cliente com mais compras (mais pares de calçado comprado)
 * @param apt_clientes apontador para a struct Clientes
 * @param encomendas apontador para a struct Encomendas
 * @param apt_artigos apontador para a struct Artigos
 */
void relatorio_cliente_compra_mais(Clientes *apt_clientes, Encomendas *encomendas, Artigos *apt_artigos) {
    FILE * f_compra_mais;
    f_compra_mais = fopen("Relatorio_cliente_compra_mais.txt", "w");
    int i = 0, max = 0;

    if (f_compra_mais != NULL) {
        if (apt_clientes->conta_clientes != 0) {
            for (i = 1; i < apt_clientes->conta_clientes; i++) {
                if (apt_clientes->clientes[max]->comprado < apt_clientes->clientes[i]->comprado) {
                    max = i;
                }
            }

            printf("\n################################");
            if (fprintf(f_compra_mais, "################################ \n") < 0) {
                printf("\n Aconteceu algum erro 1");
            }
            printf("\n O cliente que fez mais compras foi :");
            if (fprintf(f_compra_mais, "O cliente que fez mais compras foi :\n") < 0) {
                printf("\n Aconteceu algum erro 2");
            }
            printf("\n Nome : %s", apt_clientes->clientes[max]->nome_cliente);
            if (fprintf(f_compra_mais, "Nome : %s \n", apt_clientes->clientes[max]->nome_cliente) < 0) {
                printf("\n Aconteceu algum erro 3");
            }
            printf("\n Código Cliente : %d", apt_clientes->clientes[max]->codigo_cliente);
            if (fprintf(f_compra_mais, "Código Cliente : %d \n", apt_clientes->clientes[max]->codigo_cliente) < 0) {
                printf("\n Aconteceu algum erro 4");
            }
            printf("\n NIF : %d", apt_clientes->clientes[max]->nif);
            if (fprintf(f_compra_mais, "NIF : %d \n", apt_clientes->clientes[max]->nif) < 0) {
                printf("\n Aconteceu algum erro 5");
            }
        } else {
            printf("Não existem clientes!");
        }
    }
    fclose(f_compra_mais);
}

/**
 * Apresenta uma listagem com a quantidade comprada de cada artigo
 * @param apt_cliente apontador para a struct Clientes
 * @param encomendas apontador para a struct Encomendas
 * @param apt_artigos apontador para a struct Artigos
 */
void relatorio_quantidade_comprada_artigo(Clientes *apt_cliente, Encomendas *encomendas, Artigos *apt_artigos) {
    FILE * f_quantidade_artigo; // Opção 4
    f_quantidade_artigo = fopen("Relatorio_quantidade_comprada_artigo.txt", "w");

    if (f_quantidade_artigo != NULL) {
        if (apt_artigos->conta_artigos != 0) {
            printf("\n################################");
            printf("\n Consultar Compras ");

            for (int i = 0; i < apt_artigos->conta_artigos; i++) {
                printf("\n-----------------------");
                if (fprintf(f_quantidade_artigo, " -----------------------\n") < 0) {
                    printf("\n Aconteceu algum erro 1");
                }
                printf("\n Nome do artigo -> %s", apt_artigos->artigos[i]->nome_artigo);
                if (fprintf(f_quantidade_artigo, " Nome do artigo -> %s \n", apt_artigos->artigos[i]->nome_artigo) < 0) {
                    printf("\n Aconteceu algum erro 2");
                }
                printf("\n Preço do artigo -> %.2f €", apt_artigos->artigos[i]->preco_artigo);
                if (fprintf(f_quantidade_artigo, " Preco do artigo -> %.2f \n", apt_artigos->artigos[i]->preco_artigo) < 0) { // colocar 1 par tam 41
                    printf("\n Aconteceu algum erro 3");
                }
                if (apt_artigos->artigos[i]->tipo == sapato) { //sapato=0, sandalia=1, bota=2
                    printf("\n Tipo do artigo -> Sapato ");
                    if (fprintf(f_quantidade_artigo, " Tipo do artigo -> Sapato \n") < 0) {
                        printf("\n Aconteceu algum erro 4");
                    }
                } else if (apt_artigos->artigos[i]->tipo == sandalia) {
                    printf("\n Tipo do artigo -> Sandália");
                    if (fprintf(f_quantidade_artigo, " Tipo do artigo -> Sandália \n") < 0) {
                        printf("\n Aconteceu algum erro 5");
                    }
                } else {
                    printf("\n Tipo do artigo -> Bota");
                    if (fprintf(f_quantidade_artigo, " Tipo do artigo -> Bota \n") < 0) {
                        printf("\n Aconteceu algum erro 6");
                    }
                }
                printf("\n Quantidade comprada -> %d", apt_artigos->artigos[i]->comprado);
                if (fprintf(f_quantidade_artigo, " Quantidade comprada -> %d \n", apt_artigos->artigos[i]->comprado) < 0) {
                    printf("\n Aconteceu algum erro 7");
                }
            }
        } else {
            printf("Não existem artigos!");
        }
    }
    fclose(f_quantidade_artigo);
}

/**
 * Apresenta o artigo mais vendido/comprado
 * @param apt_artigos apontador para a struct Artigos
 */
void artigo_mais_comprado(Artigos *apt_artigos) {
    FILE * f_mais_vendido; // Opção 5
    f_mais_vendido = fopen("Artigo_mais_vendido.txt", "w");

    int max = 0;
    if (f_mais_vendido != NULL) {
        if (apt_artigos->conta_artigos != 0) {
            for (int i = 1; i < apt_artigos->conta_artigos; ++i) {
                if (apt_artigos->artigos[i]->comprado > apt_artigos->artigos[max]->comprado) max = i;
            }

            printf("\n################################");
            if (fprintf(f_mais_vendido, "################################ \n") < 0) {
                printf("\n Aconteceu algum erro 1");
            }
            printf("\nId: %d", apt_artigos->artigos[max]->id_artigo);
            if (fprintf(f_mais_vendido, "Id: %d \n", apt_artigos->artigos[max]->id_artigo) < 0) {
                printf("\n Aconteceu algum erro 2");
            }
            printf("\nNome: %s", apt_artigos->artigos[max]->nome_artigo);
            if (fprintf(f_mais_vendido, "Nome: %s \n", apt_artigos->artigos[max]->nome_artigo) < 0) {
                printf("\n Aconteceu algum erro 3");
            }
            printf("\nQuantidade: %d", apt_artigos->artigos[max]->comprado);
            if (fprintf(f_mais_vendido, "Quantidade: %d pares \n", apt_artigos->artigos[max]->comprado) < 0) {
                printf("\n Aconteceu algum erro 4");
            }
        } else {
            printf("Não existem artigos!");
        }
    }
    fclose(f_mais_vendido);
}