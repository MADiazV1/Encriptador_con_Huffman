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
    for (int i = 0; i < miHeap.heap.size(); i++) {
        cout << miHeap.heap[i]->get_letra() << "|" << miHeap.heap[i]->get_cantidad_letras() << endl;
    }
    return 0;
}