#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "lista.h"
#include "readqry.h" 

/*Encontra o maior valor*/

float max(float x, float y){
    if(x>y){
        return x;
    }else
    {
        return y;
    }
    
}


/*Encontra o menor valor*/

float min(float x, float y){
    if(x<y){
        return x;
    }else
    {
        return y;
    }
    
}

/*calcula a distancia entre os ponstos*/

float dist(float x1, float y1, float x2, float y2){
    float deltax, deltay, res;

    deltay = y2 - y1;
    deltax = x2 - x1;

    res = sqrt((deltax * deltax) + (deltay * deltay));

    return res;
}

/*verifica sobrepocisao de círculo com retagunlo e salva infomações
na lista*/

No *sobreposicaoCircRet(float cx, float cy, float rx, float ry,float raio, float w, float h,No *lista, bool *verifica){
    
    float  delta, largura, altura, x,y;
    Infos *dados = (Infos *) malloc(sizeof(Infos));
    No *aux, *aux2 = malloc(sizeof(No));

    x = min(rx, cx-raio);
    y = min(ry, cy-raio);
    largura = max(rx+w, cx+raio) - min(rx, cx-raio);
    altura = max(ry+h, cy+raio) - min(ry, cy-raio);


    if(dist(cx,max( rx, min(cx,rx +w)), cy, max(cy, min(cy, ry+h))) < raio){
        *verifica = true;
        dados->forma = 's';
    }  else
    {
        dados->forma = 'n';
    }

    dados->x = x;
    dados->y = y;
    dados->width = largura;
    dados->height = altura;

    aux = lista;
    while (aux->prox!=NULL){
        aux = aux->prox;
    }
    aux2->prox = NULL;
    aux2->dados = dados;
    aux->prox = aux2;

    return lista;

}


/*verifica sobrepocisao de retangulos e salva infomações
na lista*/

No *sobreposicaoRet(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2,No *lista,bool *verificacao){

    float x,y, largura, altura;
    No *aux, *aux2;
    Infos *dados = (Infos *) malloc(sizeof(Infos));

    x = min(x1,x2);
    y = min(y1,y2);
    altura = max(h1+y1, h2+y2) - y;
    largura = max(w1+x1, h2+x2) -x ;
    
    
    if (x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2  + h2 && y1 + h1 > y2){
        *verificacao = true;
        dados->forma = 's';
    }
    else{
        *verificacao = false;
        dados->forma = 'n';
    }
    
    dados->x = x;
    dados->y = y;
    dados->width = largura;
    dados->height = altura;

    aux = lista;
    while (aux->prox!=NULL){
        aux = aux->prox;
    }
    
    aux2 = malloc(sizeof(No));
    aux2->dados = dados;
    aux2->prox = NULL;
    aux->prox = aux2;


    return lista;
}


/*verifica sobrepocisao de circulos e salva infomações
na lista*/

No *sobreposicaoCirc(float x1, float y1, float r1,float x2, float y2, float r2, No *lista, bool *verifica){
    float x, y,largura,altura, maxX, maxY;
    No *aux, *aux2 = malloc(sizeof(No));
    Infos *dados = (Infos *) malloc (sizeof(Infos));


    x = min(x1,x2) - max(r1,r2);
    y = min(y1,y2) - max(r1,r2);
    largura = max(x1,x2) - min(x1,x2) + r1 + r2;
    altura = max(y1,y2) - min(y1,y2) + r1 + r2;

    if (dist(x1,y1,x2,y2) <= r1 + r2){
        *verifica = true;
        dados->forma = 's';
    }
    else{
        *verifica = false;
        dados->forma = 'n';
    }
    
    dados->x = x;
    dados->y = y;
    dados->width = largura;
    dados->height = altura;

    aux = lista;
    while (aux->prox != NULL){
        aux = aux->prox;
    }
    
    aux2->dados = dados;
    aux2->prox = NULL;
    aux->prox = aux2;

    return lista;
    
}

/*verifica se as coordenadas sao ponto interno de um ciruclo
e salva dados lista*/

No *PontoIntC(No* lista,float x1, float y1, float x2 , float y2, float raio, bool *verifica){
    float DeltaX, DeltaY, res;

    DeltaX = x2 - x1;
    DeltaY = y2 - y1;

    res = sqrt((DeltaX * DeltaX) + (DeltaY * DeltaY));

    No *aux = lista;
    No *aux2;
    Infos *dados = (Infos *) malloc(sizeof(Infos));

    while (aux->prox!=NULL){
        aux = aux->prox;
    }

    dados->y = y1;
    dados->y2 =y2;
    dados->x = x1;
    dados->x2 = x2;
    dados->forma = 'i';

    if(raio > res){
        *verifica = true;
        strcpy(dados->corl,"blue");
    }
    else{
        strcpy(dados->corl,"magenta");
    }
    
    aux2 = malloc(sizeof(No));
    aux2->prox = NULL;
    aux2->dados = dados;
    aux->prox = aux2;

    return lista;
    
}


/*verifica se as coordenadas sao ponto interno de um retangulo
e salva dados lista*/


No *PontoIntRet(No* lista,float x1, float y1, float x2 , float y2, float w, float h , bool *verifica){

    No *aux = lista, *aux2;
    Infos *dados = (Infos *) malloc(sizeof(Infos));


    dados->y = y1;
    dados->y2 =y2;
    dados->x = x1;
    dados->x2 = x2;
    dados->forma = 'i';
    
    if (x1>x2 && x1<(x2+w) && y1>y2 && y1<(y2+h)){
        *verifica = true;
        strcpy(dados->corl,"blue");

    }else{
        strcpy(dados->corl,"magenta");
    }

    while (aux->prox!=NULL){
        aux = aux->prox;
    }
    
    aux2 = malloc(sizeof(No));
    aux2->prox = NULL;
    aux2->dados = dados;
    aux->prox = aux2;

    return lista;
    
}

No *leituraQRY(No *lista, char qrysaida[], char qry[]){

    /*declaracao das variaveis utilizadas */

    FILE *arqqry;
    FILE *txt;
    FILE *svg;
    float x,y;
    char txtarq[100];
    int j,k,i=1;
    No *aux, *aux2, *aux3;
    char comando[5], corb[20], corp[20];
    bool verificacao = false;

    sprintf(txtarq,"%s.txt",qrysaida);


    arqqry = fopen(qry,"r");
    txt = fopen(txtarq,"w");

    /* percorre o arquivo qry identificando os comandos e alterando os dados */

    while (!feof(arqqry)){      
        fscanf(arqqry,"%s",comando);
        aux = lista;
        verificacao = false;   

        if(strcmp("o?",comando)==0){
            fscanf(arqqry,"%d %d",&j,&k);
            fprintf(txt,"%s %d %d\n",comando,j,k);
            strcpy(comando,"null");

            aux = lista;

            while (aux->dados->id!=j){
                if(aux==NULL){
                    printf("J nao foi localizado durante o procedimento o?\n");
                    break;
                }
                aux = aux->prox;

                if(aux->dados->id == j){

                    aux2 = lista;

                    while (aux2->dados->id != k){
                        if(aux2==NULL){
                            printf("k nao foi localizado durante o procedimento o?\n");
                            break;
                        }
                        aux2 = aux2->prox;
                        if (aux2->dados->id == k){
                            if (aux->dados->forma == 'c' && aux2->dados->forma == 'r'){
                               lista = sobreposicaoCircRet(aux->dados->x,aux->dados->y,aux2->dados->x,aux2->dados->y,aux->dados->raio,aux2->dados->width,aux2->dados->height,lista,&verificacao);
                                if (verificacao == true){
                                    fprintf(txt,"%d: círculo %d: retângulo SIM\n",j,k);
                                }else
                                {
                                    fprintf(txt,"%d: círculo %d: retângulo NÃO\n",j,k);
                                }
                                
                                
                            }
                             if (aux2->dados->forma == 'c' && aux->dados->forma == 'r'){
                                lista = sobreposicaoCircRet(aux2->dados->x,aux2->dados->y,aux->dados->x,aux->dados->y,aux2->dados->raio,aux->dados->width,aux->dados->height,lista,&verificacao);
                                if (verificacao==true){
                                    fprintf(txt,"%d: retângulo %d: círculo SIM\n",j,k);
                                }else
                                {
                                    fprintf(txt,"%d: retângulo %d: círculo NÃO\n",j,k);
                                }
                            }

                            if (aux->dados->forma == 'c' && aux2->dados->forma == 'c'){
                                lista = sobreposicaoCirc(aux->dados->x,aux->dados->y,aux->dados->raio,aux2->dados->x,aux2->dados->y,aux2->dados->raio,lista,&verificacao);
                                if (verificacao==true){
                                    fprintf(txt,"%d: círculo %d: círculo SIM",j,k);
                                }else {
                                    fprintf(txt,"%d: círculo %d: círculo NÃO",j,k);
                                }
                                
                             }

                            else if (aux->dados->forma == 'r' && aux2->dados->forma == 'r'){
                                lista = sobreposicaoRet(aux->dados->x,aux->dados->y,aux->dados->width,aux->dados->height,aux2->dados->x,aux2->dados->y,aux2->dados->width,aux2->dados->height,lista,&verificacao);
                                if (verificacao == true){
                                    fprintf(txt,"%d: retângulo %d: retângulo SIM\n",j,k);
                                }
                                else
                                {
                                    fprintf(txt,"%d: retângulo %d: retângulo NÃO\n",j,k);
                                }
                                
                                
                            }
                            
                                          
                        }
                        
                    }
                    

                }
            }
            
        }


        if(strcmp("i?",comando)==0){
            fscanf(arqqry,"%d %f %f",&j,&x,&y);
            fprintf(txt,"%s %d %f %f\n",comando,j,x,y);
            strcpy(comando,"null");

            aux = lista;

            while (aux->dados->id != j){
                if (aux==NULL){
                    printf("Erro ao encontrar j em i?\n");
                    break;
                }
                aux = aux->prox;
            }
            if (aux->dados->id == j){
                if (aux->dados->forma == 'c'){
                    lista = PontoIntC(lista,x,y,aux->dados->x, aux->dados->y,aux->dados->raio,&verificacao);
                    if(verificacao==true){
                        fprintf(txt,"%d: círculo INTERNO\n\n",j);
                    }else if(verificacao == false){
                        fprintf(txt,"%d: círculo NAO INTERNO\n\n",j);
                    }
                }
                if (aux->dados->forma == 'r'){
                    lista = PontoIntRet(lista,x,y,aux->dados->x, aux->dados->y,aux->dados->width,aux->dados->height,&verificacao);
                    if(verificacao==true){
                        fprintf(txt,"%d: retângulo INTERNO\n\n",j);
                    }else if(verificacao == false){
                        fprintf(txt,"%d: retângulo NAO INTERNO\n\n",j);
                    }
                }
                
            }
            
            
        }


        if(strcmp("pnt",comando)==0){
            fscanf(arqqry,"%d %s %s",&j,corb,corp);
            fprintf(txt, "%s %d %s %s \n", comando, j, corb,corp);

            strcpy(comando,"null");

            while (aux!=NULL){
                if (j == aux->dados->id){
                    strcpy(aux->dados->corb,corb);
                    strcpy(aux->dados->corp,corp);
                    fprintf(txt,"x : %f y : %f \n",aux->dados->x,aux->dados->y);
                    break;
                } 
                aux=aux->prox; 
            }
            
        }

        
        if(strcmp("pnt*",comando)==0){
            fscanf(arqqry,"%d %d %s %s",&j,&k,corb,corp);
            fprintf(txt,"%s %d %d %s %s\n",comando,j,k,corb,corp);
            strcpy(comando,"null");

            aux = lista;

            if(j<=k){
                while (aux->dados->id != k){
                    aux = aux->prox;
                }
                if(aux->dados->id == k){
                    aux2 = lista;
                    while (aux2->dados->id != j){
                        aux2 = aux2->prox;
                    }
                    while (aux2 != aux->prox){
                        fprintf(txt,"x : %f y : %f\n",aux2->dados->x, aux2->dados->y);
                        strcpy(aux2->dados->corb,corb);
                        strcpy(aux2->dados->corp,corp);
                        aux2 = aux2->prox;
                    }                    
                }
            }

            if(j>k){
                while (aux->dados->id != j){
                    aux = aux->prox;
                }
                if(aux->dados->id == j){
                    aux2 = lista;
                    while (aux2->dados->id != k){
                        aux2 = aux2->prox;
                    }
                    while (aux2 != aux->prox){
                        fprintf(txt,"x : %f y : %f\n",aux2->dados->x, aux2->dados->y);
                        strcpy(aux2->dados->corb,corb);
                        strcpy(aux2->dados->corp,corp);
                        aux2 = aux2->prox;
                    }                    
                }
            }
            

        }


        if(strcmp("delf",comando)==0){
            fscanf(arqqry,"%d",&j);
            fprintf(txt,"%s %d\n",comando,j);
            strcpy(comando,"null");

            aux = lista;

            while (aux!=NULL){
                if (j == aux->dados->id){
                    aux2 = lista;
                    if(aux2==aux){
                        lista = lista->prox;
                        free(aux->dados);
                        free(aux);
                    }
                    else{
                        while (aux2->prox!=aux){
                            aux2 = aux2->prox;
                        }
                        aux2->prox = aux->prox;

                        if(aux->dados->forma=='c'){
                            fprintf(txt,"id : %d forma : %c raio : %f x : %f y : %f corb : %s corp : %s\n",aux->dados->id ,aux->dados->forma ,aux->dados->raio ,aux->dados->x ,aux->dados->y ,aux->dados->corb ,aux->dados->corp );
                        }
                        else if(aux->dados->forma=='r'){
                            fprintf(txt,"id : %d forma : %c  x : %f y : %f w : %f h : %f corb : %s corp : %s\n",aux->dados->id,aux->dados->forma,aux->dados->x,aux->dados->y,aux->dados->width,aux->dados->height,aux->dados->corb,aux->dados->corp);
                        }
                        else if(aux->dados->forma=='t'){
                            fprintf(txt,"id : %d forma : %c  x : %f y : %f corb : %s corp : %s texto : %s\n",aux->dados->id,aux->dados->forma,aux->dados->x,aux->dados->y,aux->dados->corb,aux->dados->corp,aux->dados->texto);
                        }

                        free(aux->dados);
                        free(aux);
                     
                    }
                    break;
                } 
                aux=aux->prox; 
            }
            
            
        }


        if(strcmp("delf*",comando)==0){
            fscanf(arqqry,"%d %d",&j,&k);
            fprintf(txt,"%s %d %d\n",comando,j,k);
            strcpy(comando,"null");

            aux = lista;

            if(j<=k){
               while (aux->dados->id!=k){
                   if (aux == NULL){
                       printf("K nao foi localizado no delf*\n");
                       break;
                   }
                   aux = aux->prox;
               }
               if (aux->dados->id == k){
                    aux = aux->prox;
                    aux2 = lista;

                    while (aux2->dados->id != j){
                        if (aux2 == NULL){
                            printf("J nao foi localizado no delf*\n");
                            break;
                        }
                        aux2 = aux2->prox;
                    }

                    if(aux2->dados->id == j){
                        aux3 = lista;

                        if (aux3 == aux2){
                            lista = aux->prox;
                            while (aux3!=lista){
                                aux3 = aux2->prox;

                                if(aux2->dados->forma=='c'){
                                    fprintf(txt,"id : %d forma : %c raio : %f x : %f y : %f corb : %s corp : %s\n",aux2->dados->id ,aux2->dados->forma ,aux2->dados->raio ,aux2->dados->x ,aux2->dados->y ,aux2->dados->corb ,aux2->dados->corp );
                                }
                                else if(aux2->dados->forma=='r'){
                                    fprintf(txt,"id : %d forma : %c  x : %f y : %f w : %f h : %f corb : %s corp : %s\n",aux2->dados->id,aux2->dados->forma,aux2->dados->x,aux2->dados->y,aux2->dados->width,aux2->dados->height,aux2->dados->corb,aux2->dados->corp);
                                }
                                else if(aux2->dados->forma=='t'){
                                    fprintf(txt,"id : %d forma : %c  x : %f y : %f corb : %s corp : %s texto : %s\n",aux2->dados->id,aux2->dados->forma,aux2->dados->x,aux2->dados->y,aux2->dados->corb,aux2->dados->corp,aux2->dados->texto);
                                }

                                free(aux2->dados);
                                free(aux2);
                                aux2 = aux3;
                            }
                        }
                        else{
                            while (aux3->prox != aux2){
                                aux3 = aux3->prox;
                            }
                            while (aux2!=aux){
                                aux3->prox = aux2->prox;

                                if(aux2->dados->forma=='c'){
                                    fprintf(txt,"id : %d forma : %c raio : %f x : %f y : %f corb : %s corp : %s\n",aux2->dados->id ,aux2->dados->forma ,aux2->dados->raio ,aux2->dados->x ,aux2->dados->y ,aux2->dados->corb ,aux2->dados->corp );
                                }
                                else if(aux2->dados->forma=='r'){
                                    fprintf(txt,"id : %d forma : %c  x : %f y : %f w : %f h : %f corb : %s corp : %s\n",aux2->dados->id,aux2->dados->forma,aux2->dados->x,aux2->dados->y,aux2->dados->width,aux2->dados->height,aux2->dados->corb,aux2->dados->corp);
                                }
                                else if(aux2->dados->forma=='t'){
                                    fprintf(txt,"id : %d forma : %c  x : %f y : %f corb : %s corp : %s texto : %s\n",aux2->dados->id,aux2->dados->forma,aux2->dados->x,aux2->dados->y,aux2->dados->corb,aux2->dados->corp,aux2->dados->texto);
                                }

                                free(aux2->dados);
                                free(aux2);
                                aux2 = aux3->prox;
                            }
                            
                        }
                        
                    }
               }
               
               
            }

            if(j>k){
                while (aux->dados->id!=j){
                   if (aux == NULL){
                       printf("J nao foi localizado no delf*\n");
                       break;
                   }
                   aux = aux->prox;
               }
               if (aux->dados->id == j){
                    aux = aux->prox;
                    aux2 = lista;

                    while (aux2->dados->id != k){
                        if (aux2 == NULL){
                            printf("K nao foi localizado no delf*\n");
                            break;
                        }
                        aux2 = aux2->prox;
                    }

                    if(aux2->dados->id == k){
                        aux3 = lista;

                        if (aux3 == aux2){
                            lista = aux->prox;
                            while (aux3!=lista){
                                aux3 = aux2->prox;

                                if(aux2->dados->forma=='c'){
                                    fprintf(txt,"id : %d forma : %c raio : %f x : %f y : %f corb : %s corp : %s\n",aux2->dados->id ,aux2->dados->forma ,aux2->dados->raio ,aux2->dados->x ,aux2->dados->y ,aux2->dados->corb ,aux2->dados->corp );
                                }
                                else if(aux2->dados->forma=='r'){
                                    fprintf(txt,"id : %d forma : %c  x : %f y : %f w : %f h : %f corb : %s corp : %s\n",aux2->dados->id,aux2->dados->forma,aux2->dados->x,aux2->dados->y,aux2->dados->width,aux2->dados->height,aux2->dados->corb,aux2->dados->corp);
                                }
                                else if(aux2->dados->forma=='t'){
                                    fprintf(txt,"id : %d forma : %c  x : %f y : %f corb : %s corp : %s texto : %s\n",aux2->dados->id,aux2->dados->forma,aux2->dados->x,aux2->dados->y,aux2->dados->corb,aux2->dados->corp,aux2->dados->texto);
                                }
                                
                                free(aux2->dados);
                                free(aux2);
                                aux2 =  aux3;
                            }
                        }
                        else{
                            while (aux3->prox != aux2){
                                aux3 = aux3->prox;
                            }
                            while (aux2!=aux){
                                aux3->prox = aux2->prox;

                                if(aux2->dados->forma=='c'){
                                    fprintf(txt,"id : %d forma : %c raio : %f x : %f y : %f corb : %s corp : %s\n",aux2->dados->id ,aux2->dados->forma ,aux2->dados->raio ,aux2->dados->x ,aux2->dados->y ,aux2->dados->corb ,aux2->dados->corp );
                                }
                                else if(aux2->dados->forma=='r'){
                                    fprintf(txt,"id : %d forma : %c  x : %f y : %f w : %f h : %f corb : %s corp : %s\n",aux2->dados->id,aux2->dados->forma,aux2->dados->x,aux2->dados->y,aux2->dados->width,aux2->dados->height,aux2->dados->corb,aux2->dados->corp);
                                }
                                else if(aux2->dados->forma=='t'){
                                    fprintf(txt,"id : %d forma : %c  x : %f y : %f corb : %s corp : %s texto : %s\n",aux2->dados->id,aux2->dados->forma,aux2->dados->x,aux2->dados->y,aux2->dados->corb,aux2->dados->corp,aux2->dados->texto);
                                }

                                free(aux2->dados);
                                free(aux2);
                                aux2 = aux3->prox;
                            }
                            
                        }
                        
                    }
               }
               
               
            }
        }
    }

    fclose(txt);
    fclose(arqqry);

    /* Escreve os dados alterados no passo anterior */

    svg = fopen(qrysaida,"w");
    fprintf(svg,"<svg> \n");

    aux = lista;

    while (aux!=NULL){
        if(aux->dados->forma=='c'){
            fprintf(svg, "\n\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\" />", aux->dados->x,aux->dados->y,aux->dados->raio,aux->dados->corp,aux->dados->corb);
        }
        if(aux->dados->forma=='r'){
            fprintf(svg,"\n\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" stroke=\"%s\" />",aux->dados->x,aux->dados->y,aux->dados->width,aux->dados->height,aux->dados->corp,aux->dados->corb);
        }
        if(aux->dados->forma=='t'){
            fprintf(svg,"\n\t<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\">%s</text>",aux->dados->x,aux->dados->y,aux->dados->corb,aux->dados->corp,aux->dados->texto);
        }
        if(aux->dados->forma=='n'){
            fprintf(svg,"\n\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"none\" stroke=\"black\" stroke-width= \"1\" />",aux->dados->x,aux->dados->y,aux->dados->width,aux->dados->height);
        }
        if(aux->dados->forma=='s'){
            fprintf(svg,"\n\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"none\" stroke=\"black\" stroke-dasharray=\"5\" stroke-width=\"1\" />",aux->dados->y,aux->dados->x,aux->dados->width,aux->dados->height);
        }
        if(aux->dados->forma=='i'){
            fprintf(svg, "\n\t<circle cx=\"%f\" cy=\"%f\" r=\"1\" fill=\"%s\" stroke=\"%s\" />", aux->dados->x2,aux->dados->y2,aux->dados->corl,aux->dados->corl);
            fprintf(svg, "\n\t<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"%s\" />", aux->dados->x, aux->dados->y, aux->dados->x2,aux->dados->y2, aux->dados->corl);
        }
        aux = aux->prox;
    }

    fprintf(svg,"\n</svg>");

    fclose(svg);
    return lista;
}