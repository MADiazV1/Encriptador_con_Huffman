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

void Heap::actualizar(){
    for(int i=this->heap.size()/2 -1; i>=0; i--){
        cout << "a";
        comparador_heap(i);
    }
    cout << endl;
}

void Heap::comparador_heap(int indice){
    int tamanno = this->heap.size();
    int indiceMenor = indice;
    int hijoIzq = 2*indice+1;
    int hijoDer = 2*indice+2;

    if((hijoIzq < tamanno) && (this->heap[hijoIzq]->get_cantidad_letras() < this->heap[indiceMenor]->get_cantidad_letras())){
        indiceMenor = hijoIzq;
    }

    if((hijoDer < tamanno) && (this->heap[hijoDer]->get_cantidad_letras() < this->heap[indiceMenor]->get_cantidad_letras())){
        indiceMenor = hijoDer;
    }

    if(indiceMenor != indice){
        swap(this->heap[indice], this->heap[indiceMenor]);
        comparador_heap(indiceMenor);
    }
}