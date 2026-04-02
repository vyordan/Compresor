#pragma once

//#include <iostream>
//#include <map>
#include "ICompressor.hpp"

struct Nodo{
    int nRepeticiones;
    uint8_t byte;
    Nodo* anterior;
    Nodo* siguiente;
    Nodo* siguienteIzquierdo;
    Nodo* siguienteDerecho;
    
    //constructor del nodo
    Nodo(uint8_t token, int contador):  byte(token), nRepeticiones(contador), 
                                        anterior(nullptr), siguiente(nullptr), siguienteIzquierdo(nullptr), siguienteDerecho(nullptr) {} 
};
 
class Huffman: public ICompressor{
    private:
        const uint8_t idAlgoritmo = 0x02;
        Nodo* inicioL;
        Nodo* finalL;
    public:
        Huffman(){inicioL = nullptr;}
        ~Huffman(){}

        std::vector<uint8_t> compress (const std::vector<uint8_t>& buffer) override;
        std::vector<uint8_t> decompress (const std::vector<uint8_t>& buffer) override {
            return {}; //solo temporal
        }

        void insertarNodoListaOrdenado(int nRepeticiones, uint8_t token);
        void insertarNodoListaOrdenado(Nodo*& nuevoNodo);
        void convertirListaAArbol(int& tamanioLista);\
        void obtenerUltimoPuntero();
        //void mostrar(); //mostrar la lista
};