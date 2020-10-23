#ifndef _SVG_H_
#define _SVG_H_

    /*Inicia arquivo svg*/
    void abrirSVG(char saida[]);

    /*Adiciona circulo ao arquivo svg*/
    void addCirculo(int id, float raio, float x, float y, char corb[], char corp[], char saida[]);
   
    /*Adiciona retangulo ao arquivo svg*/
    void addRetangulo(int id, float width, float heigth, float x, float y,char corb[], char corp[], char saida[]);

    /*Adiciona texto ao arquivo svg*/
    void addTexto(int id, float x, float y, char corp[],char corb[], char texto[], char saida[]);

    /*Finaliza o arquivo svg*/
    void fechaSVG(char saida[]);

#endif