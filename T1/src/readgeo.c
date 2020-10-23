#include "lista.h"
#include "svg.h"
#include "readgeo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

No *leituraGeo(No *lista, char geo[],char saida[]){
    FILE *arq;
    char comando[3], forma,forma2;
    int max = 1000, id;
    size_t len = 32;
    float raio, x, y, w, h;
    char corb[20], corp[20], *texto;
    arq = fopen(geo,"r");
    if (arq==NULL){
        printf("\nErro!!aqui");
        exit(0);
    }

    abrirSVG(saida);

    texto = malloc(len);

    fscanf(arq,"%s",comando);
    if (strcmp(comando,"nx")==0){
        fscanf(arq,"%d",&max);
    }
    else{
        fseek(arq, 0, SEEK_SET);
    }
    for (int i = 0; i < max; i++){
    
        fscanf(arq,"%c",&forma);
        if(forma=='\n'){
            fscanf(arq,"%c",&forma);
        }

        if (forma == 'c'){
            fscanf(arq,"%d %f %f %f %s %s",&id,&raio,&x,&y,corb, corp);
            lista = insereCirculo(id,raio,x,y,corb, corp,lista);
            addCirculo(id,raio,x,y,corb, corp,saida);            
        }
        else if(forma == 'r'){
            fscanf(arq,"%d %f %f %f %f %s %s",&id,&w,&h,&x,&y,corb, corp);
            lista = insereRetangulo(id,w,h,x,y,corb, corp,lista);
            addRetangulo(id,w,h,x,y,corb, corp,saida);
        }
        else if(forma == 't'){
            fscanf(arq,"%d %f %f %s %s",&id,&x,&y, corb, corp);
            getline(&texto,&len,arq);
            lista = insereTexto(id,x,y,corb, corp,texto,lista);
            addTexto(id,x,y,corb, corp,texto,saida);
        }
    }

    fechaSVG(saida);

    fclose(arq);

    free(texto);

    return lista;
}