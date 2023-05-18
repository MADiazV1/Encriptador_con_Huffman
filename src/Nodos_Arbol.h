#pragma once
#include "Nodos_Huffman.h"
#include "Heap.h"

class Arbol{
    private:
        string letrasReferencia;
        int cantidadLetras;
        Arbol* cabeza;
    public:
        Arbol* izq;
        Arbol* der;

        Arbol(){
            this->cabeza = NULL;
        }
        Arbol(string letrasReferencia, int cantidad, Arbol* izq, Arbol* der);
        void agregar(Arbol* nodo);
        
};