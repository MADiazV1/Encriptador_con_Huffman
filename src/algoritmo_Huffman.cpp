#include "Nodos_Huffman.h"
#include "Heap.h"

using namespace std;

int main(){
    Nodo n;
    string texto = "Hola mundo!";
    vector<Nodo*> arregloLetrasCantidades = n.vector_nodo_letras(texto);

    Heap miHeap;
    for(Nodo* item : arregloLetrasCantidades){
        miHeap.agregar(item);
    }
    miHeap.actualizar();
    miHeap.huffman();

    cout << endl;
    for (int i = 0; i < miHeap.heap.size(); i++) {
        cout << miHeap.heap[i]->get_letras() << " -> " << miHeap.heap[i]->get_cantidad_letras() << endl;
        if(miHeap.heap[i]->huff){
            cout << miHeap.heap[i]->izq->get_letras() << "-&-" << miHeap.heap[i]->der->get_letras() << endl;
        }
    }

    miHeap.imprimir();

    return 0;
}