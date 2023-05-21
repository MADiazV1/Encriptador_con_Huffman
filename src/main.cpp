#include "Heap.h"
#include "archivos.h"

using namespace std;

int main(){
    Nodo nodo;
    Archivo archivo;
    Heap miHeap;

    string texto = archivo.leer_documento("archivo.txt");
    vector<Nodo*> arregloLetrasCantidades = nodo.vector_nodo_letras(texto);
    for(Nodo* item : arregloLetrasCantidades){
        miHeap.agregar(item);
    }
    miHeap.huffman();
    // miHeap.imprimir();

    bool activo = true;
    cout << "/===============================================================================================================/" << endl;
    cout << "*Copia en 'archivo.txt' lo que quiere encriptar.\n*Una vez hecho eso, puedes usar la opcion 2.\n*El programa no mostrara por consola los resultados, solo generara los archivos necesarios.\n*Todo lo que vaya en 'archivo.txt' debe de ir en texto plano o copiado a mano, pronto se corregira ese detalle.\n*Procurar que 'archivo.txt' tenga texto." << endl;
    cout << "/===============================================================================================================/" << endl;
    
    while(activo){
    int seleccion;
        cout << "1. Encriptar archivo" << endl;
        cout << "2. Desencriptar archivo" << endl;
        cout << "3. Salir" << endl;
        cout << endl;
        cout << "Opcion: ";
        cin >> seleccion;
        switch(seleccion){
            case 1:{
                string encriptado = miHeap.encriptar(texto, arregloLetrasCantidades);
                archivo.crear_archivo_bin(encriptado);
                break;
            }case 2:{
                string texto = archivo.leer_documento("archivo.bin");
                string a = archivo.desencriptar(texto, miHeap);
                archivo.crear_archivo_txt(a);
                break;
            }case 3:{
                activo = false;
                break;
            }default:{
                cout << "Opcion invalida." << endl;
                break;
            }
        }
    }
    return 0;
}