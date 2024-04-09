/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   struct.h
 * Author: Pedro
 *
 * Created on 19 de dezembro de 2021, 15:45
 */

#ifndef STRUCT_H
#define STRUCT_H

#ifdef __cplusplus
extern "C" {
#endif
#define TAM_STRING 100
#define MAX_ARTIGO 30
    
    typedef struct {
        int codigo_cliente;
        char nome_cliente[TAM_STRING];
        int nif;
        char pais[TAM_STRING];

        enum atividade {
            inativo, ativo
        } atividade;
        int comprado;
    } Cliente;

    typedef struct {
        int conta_clientes;
        int max_clientes;
        Cliente **clientes;
    } Clientes;

    typedef struct {
        int id_artigo;
        char nome_artigo[TAM_STRING];
        float preco_artigo;
        enum tipo {
            sapato, sandalia, bota
        } tipo;
        int comprado;// nº total de pares comprado (?) isto é a quantidade de artigos tamanho
    } Artigo;

    typedef struct {
        int conta_artigos;
        int max_artigos;
        float custo_associado[3][15], margem[3], mao_obra[3], custo_fixo[3];
        Artigo **artigos;
    } Artigos;

    typedef struct { 
        int cod_cliente;
        char *nome_cliente;
        int quantidade; // nº pares
        int tam;
        float preco_total;
        int id_artigo;        
    } Encomenda;

    typedef struct {
        int conta_encomendas;
        int max_encomendas;
        Encomenda **encomendas; // fazer memoria para isto
    } Encomendas;

#ifdef __cplusplus
}
#endif

#endif /* STRUCT_H */

