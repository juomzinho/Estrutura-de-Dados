#ifndef _LISTA_H_
#define _LISTA_H_


typedef struct Dados{
    int id;
    float raio, x, y, width, height, x2, y2;
    char corb[20], corp[20], texto[50], corl[20], forma;
}Infos;

typedef struct Elemento{
    int nelementos;
    Infos *dados;
    struct Elemento *prox; 
}No;


/*inicia lista */
No *inicializaLista();


/*insere elmentos de circulo na lista */
No *insereCirculo(int id, float raio, float x, float y, char corp[], char corb[], No *lista);


/*insere elmentos de retangulo na lista */
No *insereRetangulo(int id, float w, float h, float x, float y, char corp[], char corb[], No *lista);


/*insere elmentos de texto na lista */
No *insereTexto(int id, float x, float y, char corp[], char corb[], char texto[], No *lista);


/* dasaloca Lista */
void destroiLista(No *lista);


#endif