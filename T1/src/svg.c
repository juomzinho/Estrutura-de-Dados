#include "svg.h"
#include "lista.h"
#include <stdio.h>
#include<stdlib.h>


void abrirSVG(char saida[]){
    FILE *arqsvg;
    arqsvg = fopen(saida,"w");
    if (arqsvg==NULL){
        printf("Erro ao abrir arquivo svg!");
        exit(1);
    }
    fprintf(arqsvg,"<svg>");
    fclose(arqsvg);    
}


void addCirculo(int id, float raio, float x, float y, char corb[], char corp[],char saida[]){
    FILE *arqsvg;
    arqsvg = fopen(saida,"a");
    if (arqsvg == NULL){
        printf("Erro ao abrir arquivo SVG, durante uma tentativa de adicionar um circulo!");
        exit(1);
    }

    fprintf(arqsvg, "\n\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\" />", x, y, raio, corp, corb);

    fclose(arqsvg);    
}

void addRetangulo(int id, float width, float heigth, float x, float y, char corb[], char corp[],char saida[]){
    FILE *arqsvg;
    arqsvg = fopen(saida,"a");
    if (arqsvg == NULL){
        printf("Erro ao abrir arquivo SVG, durante uma tentativa de adicionar um Retangulo!");
        exit(1);
    }

    fprintf(arqsvg, "\n\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" stroke=\"%s\" />", x, y, width, heigth, corp, corb);

    fclose(arqsvg);
}

void addTexto(int id, float x, float y, char corb[],char corp[], char texto[],char saida[]){
    FILE *arqsvg;
    arqsvg = fopen(saida,"a");
    if (arqsvg == NULL){
        printf("Erro ao abrir arquivo SVG, durante uma tentativa de adicionar um Texto!");
        exit(1);
    }

    fprintf(arqsvg, "\n\t<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\">%s</text>", x, y,corp, corb, texto);

    fclose(arqsvg);
}


void fechaSVG(char saida[]){
    FILE *arqsvg;
    arqsvg = fopen(saida,"a");
    if (arqsvg==NULL){
        printf("Erro ao abrir arquivo svg!");
        exit(1);
    }
    fprintf(arqsvg,"</svg>");
    fclose(arqsvg);  
}