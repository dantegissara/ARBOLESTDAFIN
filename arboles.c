#include <stdio.h>
#include <stdlib.h>
#include "arboles.h"
#include <string.h>
#define CADENA_SIN_PARSEAR 40
struct ArbolE{
    char nombre[25];
    int edad;
    float altura;
};

Arbol leerArbol(){
    Arbol arbol = malloc(sizeof(struct ArbolE));

    FILE * archivo = fopen("arboles.txt","r");

    while(!feof(archivo)){

        char datos[40] = "";
        fgets(datos,40,archivo);

        arbol = parsearArboles(datos);
    }

    fclose(archivo);

    return arbol;
}

Arbol parsearArboles(char arbolSinParsear[40]){
    int posDelimitador = -1;
    int posSegLimitador = -1;

    //busuqeda primer delimitador
    for(int i = 0; i<CADENA_SIN_PARSEAR; i++){
        if (arbolSinParsear[i] == '+'){
            posDelimitador = i;
            i=50;
        }
    }
    //seg delimitador
    for (int i=posDelimitador+1;i<CADENA_SIN_PARSEAR;i++){
        if(arbolSinParsear[i] == '+'){
            posSegLimitador = i;
            i = 50;
        }
    }

    char arbolAUX[25] = "";
    char edadAUX[6] = "";
    char alturaAUX[6] = "";
    ///SEPARO NOMBRE
    for(int i = 0; i<posDelimitador;i++){
        arbolAUX[i] = arbolSinParsear[i];
    }
    for(int i= posDelimitador+1;i<posSegLimitador;i++){
        edadAUX[i] = arbolSinParsear[i];
    }

    for(int i=posSegLimitador+1;i<CADENA_SIN_PARSEAR;i++){
        alturaAUX[i]=arbolSinParsear[i];
    }

    return crearArbol(arbolAUX,atoi(edadAUX),atof(alturaAUX));
}

Arbol crearArbol(char nombre[],int edad,float altura){
    Arbol arbol = malloc(sizeof(struct ArbolE));

    strcpy(arbol->nombre,nombre);
    arbol->edad = edad;
    arbol->altura = altura;

    return crearArbol(nombre,edad,altura);


}
