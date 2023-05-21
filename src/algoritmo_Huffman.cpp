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
    miHeap.huffman();
    miHeap.imprimir();
    string encriptado = miHeap.encriptar(texto, arregloLetrasCantidades);
    cout << encriptado << endl;
    return 0;
}


