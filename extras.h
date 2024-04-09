/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   extras.h
 * Author: Pedro
 *
 * Created on 1 de janeiro de 2022, 16:54
 */

#ifndef EXTRAS_H
#define EXTRAS_H

#ifdef __cplusplus
extern "C" {
#endif

void relatorio_compras(Clientes *clientes, Encomendas *encomendas, Artigos *artigos);
void relatorio_total_ganhos_cliente(Clientes *apt_clientes, Encomendas *encomendas, Artigos *apt_artigos);
void relatorio_cliente_compra_mais(Clientes *apt_clientes, Encomendas *encomendas, Artigos *apt_artigos);
void relatorio_quantidade_comprada_artigo(Clientes *apt_cliente, Encomendas *encomendas, Artigos *apt_artigos);
void artigo_mais_comprado(Artigos *apt_artigos);

#ifdef __cplusplus
}
#endif

#endif /* EXTRAS_H */

