/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   gestao_artigos.c
 * Author: Pedro
 *
 * Created on 24 de dezembro de 2021, 00:17
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "struct.h"
#include "gestao_artigos.h"
#include "gestao_clientes.h"

#define MAX_ID 999999
#define MAX_NOME 30
#define MAX_CODIGO 999999

/*
 * 
 */

/**
 * Aloca memória para os produtos
 * @return array_produtos
 */
Artigos *inic_produtos() {
    Artigos *array_produtos;
    array_produtos = (Artigos *) malloc(sizeof (Artigos)); // numero de bites do artigo
    if (array_produtos == NULL) {
        perror("Erro a alocar memória para artigos!"); // perror faz printf e exit
    }
    array_produtos->max_artigos = 30;

    array_produtos->artigos = (Artigo **) malloc(sizeof (Artigo*) *
            array_produtos->max_artigos);
    if (array_produtos->artigos == NULL) {
        perror("Erro a alocar memória para artigo!"); // perror faz printf e exit
    }
    array_produtos->conta_artigos = 0;

    for (int i = 0; i < array_produtos->max_artigos; i++) { //inicializa tudo a NULL
        array_produtos->artigos[i] = NULL;
    }
    return array_produtos;
}

/**
 * Lê os dados guardados em "encomendasdata.txt"
 * @param array_encomendas apontador para a struct Encomendas
 */
void ler_data_encomendas(Encomendas *array_encomendas) {
    FILE *encomendas = fopen("encomendasdata.txt", "r");

    if (encomendas != NULL) {
        array_encomendas->encomendas[array_encomendas->conta_encomendas] = (Encomenda*) malloc(sizeof (Encomenda));
        char buffer[TAM_STRING];

        while (fscanf(encomendas, "%d %s %d %d %f %d\n",
                &(array_encomendas->encomendas[array_encomendas->conta_encomendas]->cod_cliente),
                buffer,
                &(array_encomendas->encomendas[array_encomendas->conta_encomendas]->quantidade),
                &(array_encomendas->encomendas[array_encomendas->conta_encomendas]->tam),
                &(array_encomendas->encomendas[array_encomendas->conta_encomendas]->preco_total),
                &(array_encomendas->encomendas[array_encomendas->conta_encomendas]->id_artigo)) != EOF) {
            array_encomendas->encomendas[array_encomendas->conta_encomendas]->nome_cliente = strdup(buffer); //aloca memoria para o nome do cliente e copia a string buffer para la

            array_encomendas->conta_encomendas++;
            array_encomendas->encomendas[array_encomendas->conta_encomendas] = (Encomenda*) malloc(sizeof (Encomenda));
        }
        fclose(encomendas);
    }
}

/**
 * Aloca memória para um artigo
 * @return artigo
 */
Artigo *inic_artigo() {
    Artigo *artigo;
    artigo = (Artigo *) malloc(sizeof (Artigo));
    if (artigo == NULL) {
        perror("Erro a alocar memória para artigo!"); // perror faz printf e exit
    }
    return artigo;
}

/**
 * Lê os dados guardados em "artigos.txt"
 * @param array_produtos apontador do tipo Artigos
 */
void ler_data_artigos(Artigos *array_produtos) {
    FILE *artigos;
    artigos = fopen("artigos.txt", "r");

    if (artigos != NULL) {
        array_produtos->artigos[array_produtos->conta_artigos] = (Artigo *) malloc(sizeof (Artigo));

        while (fscanf(artigos, "%d %s %f %d %d\n",
                &(array_produtos->artigos[array_produtos->conta_artigos]->id_artigo),
                (array_produtos->artigos[array_produtos->conta_artigos]->nome_artigo),
                &(array_produtos->artigos[array_produtos->conta_artigos]->preco_artigo),
                &(array_produtos->artigos[array_produtos->conta_artigos]->tipo),
                &(array_produtos->artigos[array_produtos->conta_artigos]->comprado)) != EOF) {

            array_produtos->conta_artigos++;
            array_produtos->artigos[array_produtos->conta_artigos] = (Artigo*) malloc(sizeof (Artigo));
        }
        fclose(artigos);
    }
}

/**
 * Aloca memória para as encomendas
 * @return array_encomendas
 */
Encomendas *inic_encomendas() {
    Encomendas *array_encomendas;
    array_encomendas = (Encomendas *) malloc(sizeof (Encomendas));
    if (array_encomendas == NULL) {
        perror("Erro a alocar memória para encomenda!"); // perror faz printf e exit
    }
    array_encomendas->max_encomendas = 30;

    array_encomendas->encomendas = (Encomenda **) malloc(sizeof (Encomenda*) *
            array_encomendas->max_encomendas);
    if (array_encomendas->encomendas == NULL) {
        perror("Erro a alocar memória para encomendas!"); // perror faz printf e exit
    }
    array_encomendas->conta_encomendas = 0;

    for (int i = 0; i < array_encomendas->max_encomendas; i++) { //inicializa tudo a NULL
        array_encomendas->encomendas[i] = NULL;
    }
    return array_encomendas;
}

/**
 * Aloca memória para uma encomenda
 * @return encomenda
 */
Encomenda *inic_enc() {
    Encomenda *encomenda;
    encomenda = (Encomenda *) malloc(sizeof (Encomenda));
    if (encomenda == NULL) {
        perror("Erro a alocar memória para encomenda!"); // perror faz printf e exit
    }
    return encomenda;
}

/**
 * Verifica o ID do artigo
 * @param apt_verificar apontador para a struct Artigos
 * @param id número de id a verificar
 * @return i caso o ID esteja associado ou -1 caso o ID não esteja associado 
 */
int verificar_id(Artigos *apt_verificar, int id) {
    /*
     * Verificar se existe o ID do artigo    
     */
    int i;
    int tam = apt_verificar->conta_artigos;

    for (i = 0; i < tam; i++) {
        if (apt_verificar->artigos[i]->id_artigo == id) {
            return i; // id está associado 
        }
    }
    return -1; // id não está associado
}

/**
 * Cria um artigo
 * @param apt_artigo apontador para a struct Artigos
 * @return número de artigos que ficam depois de adicionar
 * @return -1 se o artigo existe 
 */
int criar_artigo(Artigos *apt_artigo) {
    /*    
     * id_artigo
     * nome_artigo
     * tipo
     * preço
     */
    int id_artigo;
    id_artigo = obterInt(0, MAX_ID, "Insira o ID do produto: ");

    int indice;
    indice = verificar_id(apt_artigo, id_artigo);

    if (indice == -1) { // se o ID do artigo não tiver associado continua.
        Artigo *artigo;
        artigo = inic_artigo();

        if (apt_artigo->conta_artigos == apt_artigo->max_artigos) {
            apt_artigo->max_artigos <<= 1; // multiplica o numero por dois
            apt_artigo->artigos = realloc(apt_artigo->artigos, sizeof (Artigo **)
                    * apt_artigo->max_artigos); // o numero maximo a colocar duplica
        }

        artigo->id_artigo = id_artigo;

        lerString(artigo->nome_artigo, MAX_NOME, "Insira o nome do artigo: "); // destino para guardar o nome/ tamanho máximo/ mensagem

        artigo->tipo = obterInt(0, 2, "Insira o tipo: 0 - Sapatos || 1 - Sandálias || 2 - Botas: ");

        // Preco por defeito de um par tam 41
        float preco_ca = (apt_artigo->custo_associado[artigo->tipo][7]); //tabela de preços meio
        float preco_mo = (apt_artigo->mao_obra[artigo->tipo] * 2) * preco_ca;
        float preco_cf = (apt_artigo->custo_fixo[artigo->tipo]) * preco_ca; // custo fixo mantem se (?) senão retirar preco_ca
        float preco_ml = (preco_mo + preco_cf) * apt_artigo->margem[artigo->tipo];
        float preco_defeito = preco_mo + preco_cf + preco_ml;

        artigo->preco_artigo = preco_defeito;
        artigo->comprado = 0;

        apt_artigo->artigos[apt_artigo->conta_artigos] = artigo;
        printf("O artigo foi criado.");
        return ++(apt_artigo->conta_artigos); // no final de criar o artigo incrementa um ao conta_artigos        
    }
    return -1;
}

/**
 * Verifica a existencia de artigos
 * @param apt_artigos apontador para a struct Artigos
 */
void inserir_artigo(Artigos *apt_artigos) {
    if (criar_artigo(apt_artigos) == -1) {
        printf("O artigo já existe!");
    }
}

/**
 * Faz uma mudança no array 
 * @param array apontador a apontar para a struct Artigo
 * @param inicio número mínimo
 * @param fim número maximo
 */
void shift_Array(Artigo **array, int inicio, int fim) {
    for (int i = inicio; i < fim - 1; i++) {
        array[i] = array[i + 1];
    }
}

/**
 * Remove o artigo que não tenha compras
 * @param apt_remover apontador para a struct Artigos
 */
void remover_artigo(Artigos *apt_remover) {
    int id = verificar_id(apt_remover, obterInt(0, 99, "Insira o número de id:"));
    int tam = apt_remover->conta_artigos;
    if (id != -1) { // Se ele encontrar o elemento
        if (apt_remover->artigos[id]->comprado == 0) {
            free(apt_remover->artigos[id]);
            apt_remover->artigos[id] = NULL;
            shift_Array(apt_remover->artigos, id, tam);
            --apt_remover->conta_artigos;
            printf("Artigo removido!");
        } else {
            printf("Este artigo não pode ser removido, já possui encomendas!\n");
        }
    } else {
        printf("Id invalido!\n");
    }
}

/**
 * Edita o artigo 
 * @param apt_editar apontador para a struct Artigo
 */
void editar_artigo(Artigo * apt_editar) {
    /* 
     * Novo id do artigo
     * Novo nome do artigo
     * Novo tipo do artigo     
     */

    lerString(apt_editar->nome_artigo, MAX_NOME, "Insira o novo nome do artigo: ");
    apt_editar->tipo = obterInt(0, 2, "Novo tipo: 0 - Sapatos || 1 - Sandálias || 2 - Botas: ");
}

/**
 * Edita o artigo caso ele exista
 * @param apt_editar apontador para a struct Artigos
 */
void editar_artigos(Artigos * apt_editar) {
    int id;

    id = verificar_id(apt_editar, obterInt(0, 99, "Insira o número de id:"));

    if (id != -1) {
        editar_artigo(apt_editar->artigos[id]);
        printf("Artigo atualizado.");
    } else {
        printf("Este artigo não existe!");
    }
}

/**
 * Procura o artigo através do ID
 * @param apt_artigo apontador para a struct Artigos
 */
void procurar_artigos(Artigos * apt_artigo) {
    int id;

    id = verificar_id(apt_artigo, obterInt(0, apt_artigo->max_artigos, "Insira o número de id:"));

    if (id != -1) {
        imprimir_artigo(apt_artigo->artigos[id]);
    } else {
        printf("Este artigo não existe!");
    }
}

/**
 * Imprime o artigo no formato ID Nome Tipo
 * @param imprimir apontador para a struct Artigo
 */
void imprimir_artigo(Artigo * imprimir) {
    char *tipo;

    switch (imprimir->tipo) {
        case sapato:
            tipo = "Sapato";
            break;
        case sandalia:
            tipo = "Sandália";
            break;
        case bota:
            tipo = "Bota";
            break;
    }
    printf("\n%3d %-30s %-30s", imprimir->id_artigo, imprimir->nome_artigo, tipo);
}

/**
 * Faz uma listagem dos artigos que existem
 * @param lista apontador para a struct Artigos
 */
void lista_artigos(Artigos * lista) {
    if (lista->conta_artigos > 0) {
        int i;
        for (i = 0; i < lista->conta_artigos; i++) {
            imprimir_artigo(lista->artigos[i]);
        }
    } else {
        printf("Lista Vazia!");
    }
}

/**
 * Cria uma encomenda pedindo o ID do produto, número de pares e respetivo tamanho. 
 * @param apt_artigos apontador para a struct Artigos
 * @param apt_clientes apontador para a struct Clientes
 * @param apt_encomendas apontador para a struct Encomendas
 */
void cria_encomenda(Artigos *apt_artigos, Clientes *apt_clientes, Encomendas *apt_encomendas) {

    int cod_cliente;
    cod_cliente = verificar_codigo(apt_clientes, obterInt(0, MAX_CODIGO, "Insira o código de cliente: "));

    if (cod_cliente != -1) { // se a fução verificar_codigo retornar o indice do cliente  

        if (apt_clientes->clientes[cod_cliente]->atividade == 1) { // se o cliente estiver ativo

            int id = obterInt(0, MAX_ID, "Insira o ID do produto: "); // ID do artigo
            int indice = verificar_id(apt_artigos, id); // indice do ID do artigo (posição onde está guardado o artigo)

            if (indice != -1) {
                Artigo *artigo;
                artigo = apt_artigos->artigos[indice];

                Cliente *cliente; // usar para colocar os dados do cliente no ficheiro
                cliente = apt_clientes->clientes[cod_cliente];

                int pares = obterInt(0, 999, "Insira o número de pares: ");
                int tam = validarInt("Insira o tamanho: ", 34, 48);

                float preco_mo, preco_ca, preco_cf, preco_ml, preco_total;

                preco_ca = (apt_artigos->custo_associado[artigo->tipo][tam - 34]); //tabela de preços meio
                preco_mo = (apt_artigos->mao_obra[artigo->tipo] * pares * 2) * preco_ca;
                preco_cf = (apt_artigos->custo_fixo[artigo->tipo] * pares) * preco_ca; // custo fixo mantem se (?) senão retirar preco_ca
                preco_ml = (preco_mo + preco_cf) * apt_artigos->margem[artigo->tipo];
                preco_total = preco_mo + preco_cf + preco_ml;

                char registo[10000]; // máximo de carateres 100000           
                int cod_cliente = cliente->codigo_cliente;
                char *nome_cliente = cliente->nome_cliente, *nome_artigo = artigo->nome_artigo;
                int nif = cliente->nif;

                snprintf(registo, 10000, // passa para uma string para o ficheiro
                        "#############################" //copiar exatamente igual
                        "\nCódigo de cliente: %d || Nome: %s || NIF: %d"
                        "\nNome do artigo: %s"
                        "\nQuantidade(pares): %d"
                        "\nTamanho: %d"
                        "\nPreço mão de obra = %.2f€"
                        "\nPreço do custo fixo = %.2f€"
                        "\nMargem de lucro = %.2f€"
                        "\nPreco total = %.2f€\n", cod_cliente, nome_cliente, nif,
                        nome_artigo, pares, tam, preco_mo, preco_cf, preco_ml, preco_total);
                regista_encomenda(registo);
                printf("A encomenda foi registada!!");

                Encomenda *encomenda;
                encomenda = inic_enc();

                encomenda->cod_cliente = cod_cliente;
                encomenda->nome_cliente = strdup(nome_cliente);
                encomenda->quantidade = pares;
                artigo->comprado += pares;
                cliente->comprado += pares;
                encomenda->tam = tam;
                encomenda->preco_total = preco_total;
                encomenda->id_artigo = id;

                apt_encomendas->encomendas[apt_encomendas->conta_encomendas++] = encomenda;
            } else {
                printf("Não existe este artigo!");
            }
        } else {
            printf("Cliente inativo!");
        }
    } else { // se a fução verificar_codigo retornar o -1  
        printf("Cliente não existe!");
    }
}

/**
 * Regista a encomenda feita em cria_encomenda
 * @param encomenda 
 */
void regista_encomenda(char *encomenda) {
    FILE *file;

    file = fopen("encomendas.txt", "a");

    if (file == NULL) {
        perror("Erro ao abrir ficheiro!");
    }

    fprintf(file, "\n%s", encomenda);
    fclose(file);
}