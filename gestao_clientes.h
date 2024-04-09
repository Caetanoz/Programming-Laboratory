/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   gestao_clientes.h
 * Author: Pedro
 *
 * Created on 19 de dezembro de 2021, 17:03
 */

#ifndef GESTAO_CLIENTES_H
#define GESTAO_CLIENTES_H

#ifdef __cplusplus
extern "C" {
#endif

    void ler_data_clientes(Clientes *array_clientes);
    Clientes *inic_clientes();
    int verificar_codigo(Clientes *apt_verificar, int cod_cliente);
    int criar_cliente(Clientes *apt_cliente);
    void inserir_clientes(Clientes *apt_clientes);
    void imprimir_cliente(Cliente *apt_imprimir);
    void lista_clientes(Clientes *lista);
    void procurar_clientes(Clientes *apt_cliente);
    void editar_cliente(Cliente *apt_editar);
    void editar_clientes(Clientes *apt_editar);
    void mover_cliente(Clientes *apt_editar);

#ifdef __cplusplus
}
#endif

#endif /* GESTAO_CLIENTES_H */

