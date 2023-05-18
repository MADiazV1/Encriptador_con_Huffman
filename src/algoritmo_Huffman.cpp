#include "Nodos_Huffman.h"
#include "Heap.h"
#include "Nodos_Arbol.h"

using namespace std;

int main(){
    Nodo n;
    string texto = "Hola mundo, hola a todos'!";
    vector<Nodo*> arregloLetrasCantidades = n.vector_nodo_letras(texto);

    Heap miHeap;
    for(Nodo* item : arregloLetrasCantidades){
        miHeap.agregar(item);
    }
    for (int i = 0; i < miHeap.heap.size(); i++) {
        cout << miHeap.heap[i]->get_letra() << "|" << miHeap.heap[i]->get_cantidad_letras() << endl;
    }

    cout << "================" << endl;

    Nodo* a = miHeap.extraer_min();
    cout << a->get_letra() << "-|-" << a->get_cantidad_letras() << endl;

    miHeap.actualizar();
    for (int i = 0; i < miHeap.heap.size(); i++) {
        cout << miHeap.heap[i]->get_letra() << "|" << miHeap.heap[i]->get_cantidad_letras() << endl;
    }

    Nodo* b = miHeap.extraer_min();
    cout << b->get_letra() << "-|-" << b->get_cantidad_letras() << endl;

    // Nodo* c = miHeap.extraer_min();
    // cout << c->get_letra() << "|" << c->get_cantidad_letras() << endl;
    
    cout << "================" << endl;

    miHeap.actualizar();
    for (int i = 0; i < miHeap.heap.size(); i++) {
        cout << miHeap.heap[i]->get_letra() << "|" << miHeap.heap[i]->get_cantidad_letras() << endl;
    }


    return 0;
}