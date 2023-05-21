#pragma once
#include "Heap.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Archivo{
    private:
    public:
        void crear_archivo_bin(string texto);
        string leer_documento(string nombre);
        string desencriptar(string texto, Heap arbol);
        void crear_archivo_txt(string texto);
};