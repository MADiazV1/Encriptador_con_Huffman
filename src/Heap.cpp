#include "Heap.h"

void Heap::agregar(Nodo* valor) {
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
        comparador_heap(i);
    }
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

void Heap::huffman(){
    Heap miHeap;
    while(this->heap.size() > 1){
        Nodo* nodoIzq;
        Nodo* nodoDer;
        Nodo* nodoNuevo;

        nodoIzq = this->extraer_min();
        this->actualizar();
        nodoDer = this->extraer_min();
        this->actualizar();

        string nuevasLetras;
        if(!nodoIzq->huff && !nodoDer->huff){
            string strIzq;
            strIzq.push_back(nodoIzq->get_letra());
            string strDer;
            strDer.push_back(nodoDer->get_letra());
            nuevasLetras = strIzq+strDer;
            cout << nuevasLetras << endl;
        }else if(nodoIzq->huff && !nodoDer->huff){
            string strDer;
            strDer.push_back(nodoDer->get_letra());
            nuevasLetras = nodoIzq->get_letras() + strDer;
            cout << nuevasLetras << endl;
        }else if(!nodoIzq->huff && nodoDer->huff){
            string strIzq;
            strIzq.push_back(nodoIzq->get_letra());
            nuevasLetras = strIzq + nodoDer->get_letras();
            cout << nuevasLetras << endl;
        }else{
            nuevasLetras = nodoIzq->get_letras() + nodoDer->get_letras();
            cout << nuevasLetras << endl;
        }

        int nuevaCantidad = nodoIzq->get_cantidad_letras() + nodoDer->get_cantidad_letras();

        nodoNuevo = new Nodo(nuevasLetras, nuevaCantidad);
        nodoNuevo->izq = nodoIzq;
        nodoNuevo->der = nodoDer;

        this->agregar(nodoNuevo);

    }
}