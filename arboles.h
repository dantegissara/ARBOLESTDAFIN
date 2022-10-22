#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

struct ArbolE;

typedef struct ArbolE * Arbol;



Arbol crearArbol(char nombre[],int edad, float altura);
Arbol cargarArbol();
void mostrarArbol(Arbol arbol);

Arbol leerArbol();

Arbol parsearArboles(char arbol[40]);


#endif // ARBOLES_H_INCLUDED
