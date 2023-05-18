#include "Nodos_Arbol.h"

Arbol::Arbol(string letrasReferencia, int cantidad, Arbol* izq, Arbol* der){
    this->letrasReferencia = letrasReferencia;
    this->cantidadLetras = cantidad;
    this->izq = NULL;
    this->der = NULL;
}

void Arbol::agregar(Arbol* nodo){
    this->cabeza = nodo;
}