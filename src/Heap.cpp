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

void Heap::remover(){
    
}
