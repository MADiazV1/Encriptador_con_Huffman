#pragma once
#include "Nodos_Huffman.h"
#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> posiciones;
public:
    vector<Nodo*> heap;

    Heap(){}

    void agregar(Nodo* valor);
    void subir(int valor);
    Nodo* extraer_min();

    void actualizar();
    void comparador_heap(int indice);
};