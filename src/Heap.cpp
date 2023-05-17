#include "Heap.h"

void Heap::agregar(Nodo*valor) {
    heap.push_back(valor);
    posiciones.push_back(heap.size() - 1);
    subir(posiciones.back());
}

void Heap::subir(int i) {
    int padre = i / 2;
    while ((i > 1) && (heap[i]->get_cantidad_letras() < heap[padre]->get_cantidad_letras())) {
        swap(heap[i], heap[padre]);
        swap(posiciones[i], posiciones[padre]);
        i = padre;
        padre = i / 2;
    }
}

Nodo* Heap::extraer_min(){
    Nodo* nodoMin;
    nodoMin = this->heap[0];
    this->heap[0] = this->heap[heap.size()-1];
    this->heap.pop_back();
    return nodoMin;
}
