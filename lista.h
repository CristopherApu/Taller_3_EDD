#include <stdio.h>
#include "listaStruct.h"

////////////////////USO COMUN////////////////////
int primero();
int anterior(int p);
int siguiente(int p);
////////////////////USO COMUN////////////////////

////////////////////USUARIO////////////////////
void ingresarUsuario(datoUsuario usuario, int posicion, listaUsuario &usuarios);
void insertaUsuario(datoUsuario x, int p, listaUsuario &lista);
////////////////////USUARIO////////////////////

////////////////////SERIE////////////////////
int finSerie(listaSerie lista);
bool vaciaSerie(listaSerie lista);
datoSerie recuperaSerie(int p, listaSerie lista);
int posicionaSerie(char titulo[30], listaSerie lista);
int localizaSerie(char titulo[30], listaSerie lista);
void insertaSerie(datoSerie x, int p, listaSerie &lista);
void ingresarSerie(datoSerie serie, listaSerie &series);
void imprimeSerie(listaSerie lista);
void suprimeSerie(int p, listaSerie &lista);
void eliminarSerie(char titulo[30], listaSerie &lista);
void reproducirSerie(char titulo[30], listaSerie &lista);
////////////////////SERIE////////////////////

////////////////////PELICULA////////////////////
int finPelicula(listaPelicula lista);
bool vaciaPelicula(listaPelicula lista);
datoPelicula recuperaPelicula(int p, listaPelicula lista);
int posicionaPelicula(char titulo[30], listaPelicula lista);
int localizaPelicula(char titulo[30], listaPelicula lista);
void insertaPelicula(datoPelicula x, int p, listaPelicula &lista);
void ingresarPelicula(datoPelicula pelicula, listaPelicula &peliculas);
void imprimePelicula(listaPelicula lista);
void suprimePelicula(int p, listaPelicula &lista);
void eliminarPelicula(char titulo[30], listaPelicula &lista);
void reproducirPelicula(char titulo[30], listaPelicula &lista);
////////////////////PELICULA////////////////////