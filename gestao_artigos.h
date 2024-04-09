/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   gestao_artigos.h
 * Author: Pedro
 *
 * Created on 24 de dezembro de 2021, 00:17
 */

#ifndef GESTAO_ARTIGOS_H
#define GESTAO_ARTIGOS_H

#ifdef __cplusplus
extern "C" {
#endif

    void ler_data_encomendas(Encomendas *array_encomendas);
    void ler_data_artigos(Artigos *array_produtos);
    Encomendas *inic_encomendas();
    Artigos *inic_produtos();
    int verificar_id(Artigos *apt_verificar, int id);
    int criar_artigo(Artigos *apt_artigo);
    void inserir_artigo(Artigos *apt_clientes);
    void cria_encomenda(Artigos *apt_artigos, Clientes *apt_clientes, Encomendas *apt_encomendas);
    void regista_encomenda(char *encomenda);
    void lista_artigos(Artigos *lista);
    void remover_artigo(Artigos *apt_remover);
    void editar_artigo(Artigo *apt_editar);
    void procurar_artigos(Artigos *apt_artigo);
    void imprimir_artigo(Artigo *imprimir);
    void editar_artigos(Artigos *apt_editar);

#ifdef __cplusplus
}
#endif

#endif /* GESTAO_ARTIGOS_H */

