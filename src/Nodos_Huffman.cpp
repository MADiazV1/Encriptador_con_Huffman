#include "Nodos_Huffman.h"

Nodo::Nodo(){
    this->letra = ' ';
    this->cantidadLetras = 0;    
}

Nodo::Nodo(char letra, int cantidad){
    this->letra = letra;
    this->cantidadLetras = cantidad;
}

char Nodo::get_letra(){
    return this->letra;
}

void Nodo::set_letra(char letras){
    this->letra = letras;
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

