#include <stdio.h>
#include <cstring>
#include "lista.h"


////////////////////USO COMUN////////////////////
int primero(){
    return 1;
}

int anterior(int p){
    return p-1;
}

int siguiente(int p){
    return p+1;
}
////////////////////USO COMUN////////////////////

////////////////////USUARIO////////////////////
void ingresarUsuario(datoUsuario usuario, int posicion, listaUsuario &usuarios) {
    char *nombre=new char[25];
    printf("Por favor ingrese su nombre:\n");
    scanf("%[^\n]",nombre);
    fflush(stdin);

    strcpy(usuario.nombre, nombre);
    usuario.id = posicion;
    insertaUsuario(usuario, posicion, usuarios);

    printf("Secion iniciada con exito!!\n");
    delete nombre;
}

void insertaUsuario(datoUsuario x, int p, listaUsuario &lista){
    nodoUsuario* nuevo= new nodoUsuario(x);
    nodoUsuario* aux = lista.primero;
    if(primero()==p){
        nuevo->next=lista.primero;
        lista.primero = nuevo;
    }else{
        for(int i=0;i<p-2;i++)
            aux=aux->next;
        nuevo->next=aux->next;
        aux->next=nuevo;
    }
}
////////////////////USUARIO////////////////////

////////////////////SERIE////////////////////
int finSerie(listaSerie lista){
    int c=1;
    nodoSerie*aux = lista.primero;
    while(aux!=NULL){
        aux = aux->next;
        c++;
    }
    return c;
}

bool vaciaSerie(listaSerie lista){
    return finSerie(lista)==primero();
}

datoSerie recuperaSerie(int p, listaSerie lista){
    nodoSerie* aux = lista.primero;
    for(int i=1;i<p;i++)
        aux=aux->next;
    return aux->dato;
}

int posicionaSerie(char titulo[30], listaSerie lista){                          //Retorna a la posicion en donde deberia ir la seria segun el orden alfabetico
    for(int i=primero();i<finSerie(lista);i=siguiente(i)){
        if(strcmp(titulo,recuperaSerie(i,lista).titulo)<0){                  //Retorna "TRUE" cuando el titulo de la serie ingresada es menor con respecto al orden alfabetico
            return i;
        }
    }
    return finSerie(lista);
}

int localizaSerie(char titulo[30], listaSerie lista){                           //Retorna la posicion
    for(int i=primero();i<finSerie(lista);i=siguiente(i)){
        if(strcmp(recuperaSerie(i,lista).titulo,titulo)==0){
            return i;
        }
    }
    return finSerie(lista);
}

void insertaSerie(datoSerie x, int p, listaSerie &lista){
    nodoSerie* nuevo= new nodoSerie(x);
    nodoSerie* aux = lista.primero;
    if(primero()==p){
        nuevo->next=lista.primero;
        lista.primero = nuevo;
    }else{
        for(int i=0;i<p-2;i++)
            aux=aux->next;
        nuevo->next=aux->next;
        aux->next=nuevo;
    }
}

void ingresarSerie(datoSerie serie, listaSerie &series) {
    char *titulo=new char[30];
    int *temporadas=new int;
    int *capitulos=new int;
    printf("Ingrese Titulo:\n");
    scanf("%[^\n]",titulo);
    fflush(stdin);
    printf("Ingrese Temporadas:\n");
    scanf("%d",temporadas);
    fflush(stdin);
    printf("Ingrese Capitulos:\n");
    scanf("%d",capitulos);
    fflush(stdin);

    strcpy(serie.titulo, titulo);
    serie.temporadas = *temporadas;
    serie.capitulos = *capitulos;
    serie.reproducciones = 0;

    if(localizaSerie(titulo,series)!=finSerie(series)){
        printf("Esta serie ya fue ingresada anteriormente\n");
    }else{
        insertaSerie(serie, posicionaSerie(titulo, series), series);
        printf("SERIE INGRESADA CON EXITO!\n");
    }
    printf("Desea ingresar otro titulo?\n");
    delete titulo;
    delete temporadas;
    delete capitulos;
}

void imprimeSerie(listaSerie lista){
    for(int i=primero();i<finSerie(lista);i=siguiente(i)){
        datoSerie x = recuperaSerie(i,lista);
        printf("%s - Temporadas:%i - Capitulos:%i - Reproducciones:%i\n", x.titulo, x.temporadas, x.capitulos, x.reproducciones);
    }
}

void suprimeSerie(int p, listaSerie &lista){
    nodoSerie* aux = lista.primero;
    if(primero()==p)
        lista.primero=aux->next;
    else{
        nodoSerie* aux2 = lista.primero;
        for(int i=0;i<p-2;i++)
            aux2=aux2->next;
        aux=aux2->next;
        aux2->next = aux->next;
    }
    aux->next = NULL;
    delete aux;
}

void eliminarSerie(char titulo[30], listaSerie &lista){
    int i = localizaSerie(titulo, lista);
    if (i!=finSerie(lista)){

        if(recuperaSerie(i,lista).reproducciones>5){                          //No se elimina si tiene más de 5 reproducciones
            printf("La serie no se puede eliminar (tiene mas de 5 reproducciones).\n");
        }else{
            suprimeSerie(i,lista);
            printf("SERIE ELIMINADA CON EXITO.\n");
        }

    }else{
        printf("La serie ingresada no existe.\n");
    }
}

void reproducirSerie(char titulo[30], listaSerie &lista){
    nodoSerie *aux=lista.primero;
    for(int i=primero();i<finSerie(lista);i=siguiente(i)){
        if(strcmp(recuperaSerie(i,lista).titulo,titulo)==0){
            aux->dato.reproducciones++;
            printf("Se acaba de reproducir %s.\n", aux->dato.titulo);
            return;
        }
        if(i==(finSerie(lista)-1)){
            printf("La serie que busca no existe.\n");
            return;
        }
        aux = aux->next;
    }
}
////////////////////SERIE////////////////////

////////////////////PELICULA////////////////////
int finPelicula(listaPelicula lista){
    int c=1;
    nodoPelicula*aux = lista.primero;
    while(aux!=NULL){
        aux = aux->next;
        c++;
    }
    return c;
}

bool vaciaPelicula(listaPelicula lista){
    return finPelicula(lista)==primero();
}

datoPelicula recuperaPelicula(int p, listaPelicula lista){
    nodoPelicula* aux = lista.primero;
    for(int i=1;i<p;i++)
        aux=aux->next;
    return aux->dato;
}

int posicionaPelicula(char titulo[30], listaPelicula lista){
    for(int i=primero();i<finPelicula(lista);i=siguiente(i)){
        if(strcmp(titulo,recuperaPelicula(i,lista).titulo)<0){
            return i;
        }
    }
    return finPelicula(lista);
}

int localizaPelicula(char titulo[30], listaPelicula lista){
    for(int i=primero();i<finPelicula(lista);i=siguiente(i)){
        if(strcmp(recuperaPelicula(i,lista).titulo,titulo)==0){
            return i;
        }
    }
    return finPelicula(lista);
}

void insertaPelicula(datoPelicula x, int p, listaPelicula &lista){
    nodoPelicula* nuevo= new nodoPelicula(x);
    nodoPelicula* aux = lista.primero;
    if(primero()==p){
        nuevo->next=lista.primero;
        lista.primero = nuevo;
    }else{
        for(int i=0;i<p-2;i++)
            aux=aux->next;
        nuevo->next=aux->next;
        aux->next=nuevo;
    }
}

void ingresarPelicula(datoPelicula pelicula, listaPelicula &peliculas) {
    char *titulo=new char[30];
    printf("Por favor ingrese el titulo:\n");
    scanf("%[^\n]",titulo);
    fflush(stdin);

    strcpy(pelicula.titulo, titulo);
    pelicula.reproducciones = 0;

    if(localizaPelicula(titulo,peliculas)!=finPelicula(peliculas)){
        printf("Esta pelicula ya fue ingresada anteriormente\n");
    }else{
        insertaPelicula(pelicula, posicionaPelicula(titulo, peliculas), peliculas);
        printf("PELICULA INGRESADA CON EXITO!\n");
    }
    printf("Desea ingresar otro titulo?\n");
    delete titulo;
}

void imprimePelicula(listaPelicula lista){
    for(int i=primero();i<finPelicula(lista);i=siguiente(i)){
        datoPelicula x = recuperaPelicula(i,lista);
        printf("%s - Reproducciones:%i\n", x.titulo, x.reproducciones);
    }
}

void suprimePelicula(int p, listaPelicula &lista){
    nodoPelicula* aux = lista.primero;
    if(primero()==p)
        lista.primero=aux->next;
    else{
        nodoPelicula* aux2 = lista.primero;
        for(int i=0;i<p-2;i++)
            aux2=aux2->next;
        aux=aux2->next;
        aux2->next = aux->next;
    }
    aux->next = NULL;
    delete aux;
}

void eliminarPelicula(char titulo[30], listaPelicula &lista){
    int i = localizaPelicula(titulo, lista);
    if (i!=finPelicula(lista)){

        if(recuperaPelicula(i,lista).reproducciones>5){
            printf("La pelicula no se puede eliminar ya que tiene mas de 5 reproducciones.\n");
        }else{
            suprimePelicula(i,lista);
            printf("Pelicula eliminada con exito!!\n");
        }

    }else{
        printf("La pelicula ingresada no existe.\n");
    }
}

void reproducirPelicula(char titulo[30], listaPelicula &lista){
    nodoPelicula *aux=lista.primero;
    for(int i=primero();i<finPelicula(lista);i=siguiente(i)){
        if(strcmp(recuperaPelicula(i,lista).titulo,titulo)==0){
            aux->dato.reproducciones++;
            printf("Se acaba de reproducir %s.\n", aux->dato.titulo);
            return;
        }
        if(i==(finPelicula(lista)-1)){
            printf("La pelicula que busca no existe.\n");
            return;
        }
        aux = aux->next;
    }
}
////////////////////PELICULA////////////////////