#ifndef LISTA_STRUCT_H
#define LISTA_STRUCT_H

#define datoUsuario usuario
#define datoPelicula pelicula
#define datoSerie serie

////////////////////USUARIO////////////////////
struct usuario{
    int id;
    char nombre[25];
    struct cliente *sgte;
};

struct nodoUsuario{
    datoUsuario dato;
    struct nodoUsuario* next;
    nodoUsuario(){
        next=NULL;
    }
    nodoUsuario(datoUsuario x){
        nodoUsuario();
        dato=x;
    }
};

struct listaUsuario{
    struct nodoUsuario* primero;
    listaUsuario(){
        primero=NULL;
    }
};
////////////////////USUARIO////////////////////

////////////////////SERIE////////////////////
struct serie{
    char titulo[30];
    int temporadas;
    int capitulos;
    int reproducciones;                                         //Se agrega la variable "reproducciones" para facilitar la eliminacion
    struct usuario *lista;
                                                                //struct serie *sgte; Se extirpa de la struct porque se agrega en el nodoSerie
};

struct nodoSerie{
    datoSerie dato;
    struct nodoSerie* next;
    nodoSerie(){
        next=NULL;
    }
    nodoSerie(datoSerie x){
        nodoSerie();
        dato=x;
    }
};

struct listaSerie{
    struct nodoSerie* primero;
    listaSerie(){
        primero=NULL;
    }
};
////////////////////SERIE////////////////////

////////////////////PELICULA////////////////////
struct pelicula{
    char titulo[30];
    int reproducciones;                                           //Se agrega la variable reproducciones para facilitar la eliminacion
    struct usuario *lista;
                                                                  //struct pelicula *sgte; Se extirpa de la struct porque se agrega en el nodoPelicula
};

struct nodoPelicula{
    datoPelicula dato;
    struct nodoPelicula* next;
    nodoPelicula(){
        next=NULL;
    }
    nodoPelicula(datoPelicula x){
        nodoPelicula();
        dato=x;
    }
};

struct listaPelicula{
    struct nodoPelicula* primero;
    listaPelicula(){
        primero=NULL;
    }
};
////////////////////PELICULA////////////////////

#endif