#include "archivos.h"

void Archivo::crear_archivo_bin(string texto){
    ofstream archivo("archivo.bin", ios::binary);
    if(archivo.is_open()){
        archivo.write(texto.c_str(), texto.length());
        archivo.close();
        cout << "Archivo creado" << endl;
        cout << "/---------------------------------------------------------------------------------------------/" << endl;
    }else{
        cout << "No se pudo crear el archivo." << endl;
        cout << "/---------------------------------------------------------------------------------------------/" << endl;
    }
}

string Archivo::leer_documento(string nombre){
    ifstream archivo(nombre);
    if (archivo.is_open()) {
        string contenido((istreambuf_iterator<char>(archivo)),
        istreambuf_iterator<char>());
        archivo.close();
        return contenido;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
        cout << "/---------------------------------------------------------------------------------------------/" << endl;
        return "";
    }
}

string Archivo::desencriptar(string texto, Heap arbol){
    string nuevoTexto;
    Nodo* nodo = arbol.heap[0];
    for(char str : texto){
        if(str == '1'){
            nodo = nodo->izq;
        }else{
            nodo = nodo->der;
        }
        if(!nodo->huff){
            nuevoTexto += nodo->get_letra();
            nodo = arbol.heap[0];
        }
    }
    return nuevoTexto;
}

void Archivo::crear_archivo_txt(string texto){
    ofstream archivo("archivoNuevo.txt", ios::binary);
    if(archivo.is_open()){
        archivo.write(texto.c_str(), texto.length());
        archivo.close();
        cout << "Archivo creado" << endl;
        cout << "/---------------------------------------------------------------------------------------------/" << endl;
    }else{
        cout << "No se pudo crear el archivo." << endl;
        cout << "/---------------------------------------------------------------------------------------------/" << endl;
    }
}