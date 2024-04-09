/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   compras.c
 * Author: Pedro
 *
 * Created on 24 de dezembro de 2021, 00:58
 */

#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "input.h"

/*
 * 
 */

/**
 * Coloca os preços dos artigos nos respetivos arrays e matriz no caso dos custos associados
 * @param apt_artigo apontador para a struct artigos
 */
void precos(Artigos *apt_artigo) {
    FILE *precos;

    precos = fopen("tabeladecustos.txt", "r");

    if (precos != NULL) {

        int i = 0;
        while (fscanf(precos, "%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f\n",
                &(apt_artigo->mao_obra[i]),
                &(apt_artigo->custo_fixo[i]),
                &(apt_artigo->custo_associado[i][0]),
                &(apt_artigo->custo_associado[i][1]),
                &(apt_artigo->custo_associado[i][2]),
                &(apt_artigo->custo_associado[i][3]),
                &(apt_artigo->custo_associado[i][4]),
                &(apt_artigo->custo_associado[i][5]),
                &(apt_artigo->custo_associado[i][6]),
                &(apt_artigo->custo_associado[i][7]),
                &(apt_artigo->custo_associado[i][8]),
                &(apt_artigo->custo_associado[i][9]),
                &(apt_artigo->custo_associado[i][10]),
                &(apt_artigo->custo_associado[i][11]),
                &(apt_artigo->custo_associado[i][12]),
                &(apt_artigo->custo_associado[i][13]),
                &(apt_artigo->custo_associado[i][14]),
                &(apt_artigo->margem[i])) != EOF) {
            i++;
        }
        fclose(precos);
    }
}

/**
 * Altera o preço dos arrays do custo da mão de obra, custos fixos e margem de lucro
 * @param array coleção dos valores da mão de obra, custos fixos e margem de lucro 
 */
void alterar_preco(float array[]) {
    int tipo;
    float preco;
    // Pede o novo preço    
    tipo = obterInt(0, 2, "0 - Sapatos\n1 - Sandálias\n2 - Botas\nInsira o tipo: ");
    preco = obterFloat(0, 999, "Insira o novo preço: ");

    array[tipo] = preco;
    printf("Preço alterado com sucesso.");
}

/**
 * Altera o preço associado 
 * @param array coleção de valores dos custos associados
 */
void alterar_preco_associado(float array[3][15]) {
    int tipo, tam;
    float novo_preco;

    tipo = validarInt("0 - Sapatos\n1 - Sandálias\n2 - Botas", 0, 2);
    tam = validarInt("Insira o tamanho do calçado [34 - 48]: ", 34, 48);
    novo_preco = obterFloat(0, 999, "Insira o novo valor: ");

    array[tipo][tam - 34] = novo_preco;
    printf("Preço alterado com sucesso.");
}