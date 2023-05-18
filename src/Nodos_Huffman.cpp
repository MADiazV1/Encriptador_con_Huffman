#include "Nodos_Huffman.h"

Nodo::Nodo(){
    this->letra_ch = ' ';
    this->cantidadLetras = 0;    
}

Nodo::Nodo(char letra, int cantidad){
    this->letra_ch = letra;
    this->cantidadLetras = cantidad;
    this->huff = false;
}

Nodo::Nodo(string letras, int cantidad){
    this->letras = letras;
    this->cantidadLetras = cantidad;
    this->huff = true;
    this->izq = NULL;
    this->der = NULL;
}

string Nodo::get_letras(){
    return this->letras;
}

char Nodo::get_letra(){
    return this->letra_ch;
}

void Nodo::set_letra(char letras){
    this->letra_ch = letras;
}

int Nodo::get_cantidad_letras(){
    return this->cantidadLetras;
}

void Nodo::set_cantidad_letras(int nuevaCantidad){
    this->cantidadLetras = nuevaCantidad;
}

vector<Nodo*> Nodo::vector_nodo_letras(string texto){
    vector<Nodo*> vector;
    string textoTemp = texto;

    for(int i=0; i<textoTemp.length(); i++){
        bool agregar = true;
        for(Nodo* item : vector){
            if(item->get_letra() == textoTemp[i]){
                item->set_cantidad_letras(item->get_cantidad_letras()+1);
                agregar = false;
                break;
            }
        }
        if(agregar){
            Nodo* nodo = new Nodo(textoTemp[i], 1);
            vector.push_back(nodo);
        }  
    }
    return vector;
}