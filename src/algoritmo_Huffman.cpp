#include "Nodos_Huffman.h"
#include "Heap.h"

using namespace std;

int main(){
    Nodo n;
    string texto = "Hola mundo!";
    vector<Nodo*> arregloLetrasCantidades = n.vector_nodo_letras(texto);

    for(Nodo* i : arregloLetrasCantidades){
        cout << i->get_letra() << "|" << i->get_cantidad_letras() << endl;
    }

    cout << endl;

    Heap miHeap;
    for(Nodo* item : arregloLetrasCantidades){
        miHeap.agregar(item);
    }
    miHeap.actualizar();
    for (int i = 0; i < miHeap.heap.size(); i++) {
        cout << miHeap.heap[i]->get_letra() << "|" << miHeap.heap[i]->get_cantidad_letras() << endl;
    }
    miHeap.huffman();
    cout << endl;
    for (int i = 0; i < miHeap.heap.size(); i++) {
        cout << miHeap.heap[i]->get_letras() << "|" << miHeap.heap[i]->get_cantidad_letras() << endl;
    }



    return 0;
}