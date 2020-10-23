#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

No *inicializaLista(){
    return NULL;
}

No *insereCirculo(int id, float raio, float x, float y, char corb[], char corp[], No *lista){
    Infos *dados;
    No *aux,*aux2;

    dados = (Infos *)malloc(sizeof(Infos));

    dados->id = id;
    dados->raio = raio;
    dados->x = x;
    dados->y = y;
    strcpy(dados->corp,corp);
    strcpy(dados->corb,corb);
    
    dados->forma = 'c';

    if(lista==NULL){
        lista = malloc(sizeof(No));
        lista->nelementos = 0;
        lista->prox = NULL;
        lista->dados = dados;
    }
    else{
        aux = lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux2 = malloc (sizeof(No));
        aux2->dados = dados;
        aux2->prox = NULL;         
        aux->prox = aux2;
    }
    lista->nelementos++;

        //printf("%c %d %f %f %f %s %s || %c %d %f %f %f %s %s \n", dados->forma,dados->id, dados->raio, dados->x, dados->y, dados->corb, dados->corp, lista->dados->forma, lista->dados->id, lista->dados->raio, lista->dados->x, lista->dados->y, lista->dados->corb, lista->dados->corb);

    return lista;
}

No *insereRetangulo(int id, float w, float h, float x, float y, char corb[], char corp[], No *lista){
    Infos *dados;
    No *aux,*aux2;

    dados = (Infos *)malloc(sizeof(Infos));

    dados->id = id;
    dados->width = w;
    dados->height = h;
    dados->x = x;
    dados->y = y;
    strcpy(dados->corp,corp);
    strcpy(dados->corb,corb);
    
    dados->forma = 'r';

    if(lista==NULL){
        lista = malloc(sizeof(No));
        lista->nelementos = 0;
        lista->prox = NULL;
        lista->dados = dados;
    }
    else{
        aux = lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux2 = malloc (sizeof(No));
        aux2->dados = dados;
        aux2->prox = NULL;         
        aux->prox = aux2;
    }
    lista->nelementos++;
    return lista;
}

No *insereTexto(int id, float x, float y, char corb[], char corp[], char texto[], No *lista){
    Infos *dados;
    No *aux,*aux2;

    dados = (Infos *)malloc(sizeof(Infos));

    dados->id = id;
    dados->x = x;
    dados->y = y;
    strcpy(dados->corb,corb);
    strcpy(dados->corp,corp);
    strcpy(dados->texto,texto);
    dados->forma = 't';

    if(lista==NULL){
        lista = malloc(sizeof(No));
        lista->nelementos = 0;
        lista->prox = NULL;
        lista->dados = dados;
    }
    else{
        aux = lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux2 = malloc (sizeof(No));
        aux2->dados = dados;
        aux2->prox = NULL;         
        aux->prox = aux2;
    }
    

    lista->nelementos++;
    return lista;
}

void destroiLista(No *lista){
    No *aux;

    aux = lista;
    while (aux!= NULL){
        lista = lista->prox;
        free(aux->dados);
        free(aux);
        aux = lista;
    }
    

}
