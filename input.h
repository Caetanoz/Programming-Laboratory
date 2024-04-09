/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   input.h
 * Author: Pedro
 *
 * Created on 16 de dezembro de 2021, 21:48
 */

#ifndef INPUT_H
#define INPUT_H

#ifdef __cplusplus
extern "C" {
#endif

#define MSG_OBTER_OPCAO "Insira a opção:"

    int validarInt(char * txt, int Val_min, int Val_max);
    int obterInt(int minValor, int maxValor, char *msg);
    float obterFloat(float minValor, float maxValor, char *msg);    
    void lerString(char *string, unsigned int tamanho, char *msg);
    void printLinha();

#ifdef __cplusplus
}
#endif

#endif /* INPUT_H */

