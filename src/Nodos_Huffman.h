#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Nodo{
    private:
        char letra_ch;
        string letras;
        int cantidadLetras;
    public:
        string recorrido;
        bool huff;
        Nodo* izq;
        Nodo* der;
        Nodo();
        Nodo(char letra, int cantidad);
        Nodo(string letras, int cantidad);

        string get_letras();
        char get_letra();
        void set_letra(char letra);

        int get_cantidad_letras();
        void set_cantidad_letras(int nuevaCantidad);

        vector<Nodo*> vector_nodo_letras(string texto);
};