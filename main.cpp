#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "lista.h"

listaUsuario usuarios;
listaPelicula peliculas;
listaSerie series;

int main() {

    datoUsuario usuario;
    datoPelicula pelicula;
    datoSerie serie;

    int *idUsuario=new int;
    *idUsuario=0;

    int *n=new int;
    *n=0;
    while((*n)!=3){

        printf("!Bienvenido a Streaming UFRO! Elija una opcion:\n");
        printf("[1] Iniciar Sesion\n[2] Administrar\n[3] Salir\n");

        scanf("%d",n);
        fflush(stdin);                                                      //Limpio la entrada stdin

        if((*n)==1){                                                        //Opcion 1
            *idUsuario=*idUsuario+1;
            ingresarUsuario(usuario, *idUsuario, usuarios);

            int *n2=new int;
            *n2=0;
            while((*n2)!=3){

                printf("[CARTELERA]\n");
                printf("[1] Series\n[2] Peliculas\n[3] Cerrar Sesion\n");

                scanf("%d",n2);
                fflush(stdin);

                if((*n2)==1){                                               //Ver Series

                    if(vaciaSerie(series)==1){
                        printf("No hay series disponibles.\n");
                    }else{
                        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                        imprimeSerie(series);
                        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                        printf("Ingrese el nombre de la serie que desea reproducir:\n");
                        char *titulo=new char[30];
                        scanf("%[^\n]",titulo);
                        fflush(stdin);
                        reproducirSerie(titulo, series);
                        delete titulo;
                    }

                }else if((*n2)==2){                                         //Ver Peliculas

                    if(vaciaPelicula(peliculas)==1){
                        printf("No hay peliculas disponibles.\n");
                    }else{
                        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                        imprimePelicula(peliculas);
                        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                        printf("Ingrese el nombre de la pelicula que desea reproducir:\n");
                        char *titulo=new char[30];
                        scanf("%[^\n]",titulo);
                        fflush(stdin);
                        reproducirPelicula(titulo,peliculas);
                        delete titulo;
                    }

                }
            }

            delete n2;

        }else if((*n)==2){                                                  //Opcion 2

            int *n2=new int;
            *n2=0;

            while((*n2)!=3){

                printf("[ADMINISTRADOR]\n");
                printf("[1] Ingresar Titulo\n[2] Eliminar Titulo\n[3] Volver\n");

                scanf("%d",n2);
                fflush(stdin);
                if((*n2)==1){                                               //Ingresa un titulo, ya sea de serie o pelicula
                    int *n3=new int;
                    *n3=0;
                    while ((*n3)!=3){

                        printf("[INGRESO TITULO]\n");
                        printf("[1] Serie\n[2] Pelicula\n[3] Volver\n");
                        scanf("%d",n3);
                        fflush(stdin);
                        if((*n3)==1){                                       //El titulo a ingresar es una serie
                            ingresarSerie(serie,series);
                        }else if((*n3)==2){                                 //El titulo a ingresar es una pelicula
                            ingresarPelicula(pelicula,peliculas);
                        }
                    }
                    delete n3;
                }else if((*n2)==2){                                         //El titulo se pretende eliminar
                    int *n3=new int;
                    *n3=0;
                    while ((*n3)!=3){

                        printf("[ELIMINAR TITULO]\n");
                        printf("[1] Serie\n[2] Pelicula\n[3] Volver\n");
                        scanf("%d",n3);
                        fflush(stdin);
                        if((*n3)==1){                                       //El titulo a eliminar es una serie

                            if(vaciaSerie(series)==1){
                                printf("No hay series disponibles.\n");
                            }else{
                                printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                                imprimeSerie(series);
                                printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                                printf("Ingrese el nombre de la serie que desea eliminar:\n");
                                char *titulo=new char[30];
                                scanf("%[^\n]",titulo);
                                fflush(stdin);
                                eliminarSerie(titulo,series);
                                delete titulo;

                            }

                        }else if((*n3)==2){                                  ////El titulo a eliminar es una pelicula

                            if(vaciaPelicula(peliculas)==1){
                                printf("No hay peliculas disponibles.\n");
                            }else{
                                printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                                imprimePelicula(peliculas);
                                printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
                                printf("Ingrese el nombre de la pelicula que desea eliminar:\n");
                                char *titulo=new char[30];
                                scanf("%[^\n]",titulo);
                                fflush(stdin);
                                eliminarPelicula(titulo,peliculas);
                                delete titulo;

                            }

                        }

                    }

                    delete n3;
                }
            }

            delete n2;
        }

    }

    delete idUsuario;
    delete n;
    return 0;
}