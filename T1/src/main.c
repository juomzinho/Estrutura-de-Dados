#include "readgeo.h"
#include "readqry.h"
#include "svg.h"
#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


char *tratamento(char nomeArq[]){
    int i,x,y;
    char *prefixo, caractere;

    for(i=strlen(nomeArq);i>=0;i--) {
		caractere = nomeArq[i];
        if(caractere=='/') {
			y = strlen(nomeArq)-i;
        	prefixo = (char*) malloc(y*sizeof(char));

        	for(x=0;x<=y;x++){
            	prefixo[x] = nomeArq[i+1];
            	i++; 
        	}  
			return strtok(prefixo,".");
        }        
    }
	return strtok(nomeArq,".");
}


int main(int argc, char *argv[]){
    No *lista;
    int i = 1;
    char *nomeArq = NULL;
    char *geo = NULL;
    char *qry = NULL;
    char *arqqry = NULL;
    char *path = NULL;
    char *arq = NULL;
    char *saida = NULL;
    char *arqsvg = NULL;
    char *pgeo = NULL;
    char *pqry = NULL;
    char *parq = NULL;
    char *qrysaida = NULL;
    char str[100];
    FILE *f;


    while (i<argc){

            if (strcmp("-f",argv[i])==0){
                i++;
                if(argv[i]==NULL){
                    printf("\n-f nao recebeu parametros");
                    exit(1);
                }
                nomeArq = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
                strcpy(nomeArq,argv[i]);
            }
            if (strcmp("-e",argv[i])==0){
                i++;
                if(argv[i]==NULL){
                    printf("\n-q nao recebeu parametros");
                    exit(1);
                }
                path = (char *) malloc ((strlen(argv[i])+2) * sizeof(char));
                strcpy(path,argv[i]);
            }
            
            if (strcmp("-q",argv[i])==0){
                i++;
                if(argv[i]==NULL){
                    printf("\n-q nao recebeu parametros");
                    exit(1);
                }
                qry = (char *) malloc ((strlen(argv[i])+2) * sizeof(char));
                strcpy(qry,argv[i]);
            }
            if (strcmp("-o",argv[i])==0){
                i++;
                if(argv[i]==NULL){
                    printf("\n-o nao recebeu parametros");
                    exit(1);
                }
                saida = (char *) malloc ((strlen(argv[i])+1) * sizeof(char));
                strcpy(saida,argv[i]);
            }
            i++;
    }

    if(path!=NULL){
        geo = (char *)malloc((strlen(nomeArq)+strlen(path)+2)*sizeof(char));
    	sprintf(geo,"%s/%s",path,nomeArq);

        arqqry = (char *)malloc((strlen(qry)+strlen(path)+2)*sizeof(char));
    	sprintf(arqqry,"%s%s",path,qry);
    }else {
		geo = (char *)malloc((strlen(nomeArq)+1)*sizeof(char));
    	strcpy(geo, nomeArq);

    	arqqry = (char *)malloc((strlen(qry)+1)*sizeof(char));
    	strcpy(arqqry, qry);
	}


    pgeo = (char *) malloc((strlen(nomeArq)+1)*sizeof(char));	
    pgeo = tratamento(nomeArq);  

    pqry = (char *) malloc((strlen(qry)+1)*sizeof(char));	
    pqry = tratamento(qry); 
    

    lista = inicializaLista();

    arqsvg = (char *)malloc((strlen(saida)+strlen(pgeo)+6)*sizeof(char));
    sprintf(arqsvg, "%s/%s.svg", saida, pgeo);

    lista = leituraGeo(lista,geo,arqsvg);


    parq = (char *) malloc((strlen(arqsvg)+strlen(pqry)+6)*sizeof(char));
    sprintf(parq,"%s/%s-%s", saida, pgeo, pqry);

    lista = leituraQRY(lista,parq,qry);
    

    destroiLista(lista);
    free(qrysaida);
    free(parq);
    free(arqsvg);
    free(pqry);
    free(pgeo);
    free(arqqry);
    free(geo);
    free(saida);
    free(qry);
    free(path);
    free(nomeArq);
}