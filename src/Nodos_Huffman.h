#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Nodo{
    private:
        char letra;
        int cantidadLetras;
    public:
        Nodo();
        Nodo(char letra, int cantidad);

        char get_letra();
        void set_letra(char letra);

        int get_cantidad_letras();
        void set_cantidad_letras(int nuevaCantidad);

        vector<Nodo*> vector_nodo_letras(string texto);
};