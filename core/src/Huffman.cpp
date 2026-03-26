#include "Huffman.hpp"

std::vector<uint8_t> Huffman::compress (const std::vector<uint8_t>& buffer){
    std::vector<uint8_t> compressedBuffer; //sera el buffer final incluyendo el arbol binario

    //cada posicion [n] es un token y en el espacio en memoria de esa posicion se va almacenar el la cantidad de veces que se repita ese token
    int contadorRepeticiones[256] = {0};
    for (int i = 0; i < buffer.size(); i++){
        contadorRepeticiones[(int)buffer[i]]++;
    }
    


    return {};
} 

void Huffman::insertarNodoListaOrdenado(int contadorR, uint8_t token){
    Nodo* nuevoNodo = new Nodo(token, contadorR);

    //por si la lista esta vacia o si el nuevo valor es mas grande al del inicio 
    if (inicioL == nullptr || contadorR >= inicioL->nRepeticiones){
        nuevoNodo->siguiente = inicioL;
        if (inicioL != nullptr){
            inicioL->anterior = nuevoNodo;
        }
        inicioL = nuevoNodo;
        return;
    }

    //buscamos la posicion donde va ir el nodo
    Nodo* nodoActual = inicioL;
    //hacemos esa consulta tan adelantada para tener que usar otro nodo auxiliar que vaya guardando la pposicion anterior
    while (nodoActual->siguiente != nullptr && nodoActual->siguiente->nRepeticiones > contadorR){
        nodoActual = nodoActual->siguiente;
    }
    //vamos a insertar despues del Nodo Actual que es nuestro nodo auxiliar para recorrer la lista
    nuevoNodo->siguiente = nodoActual->siguiente;
    nuevoNodo->anterior = nodoActual;

    if (nodoActual->siguiente != nullptr){
        nodoActual->siguiente->anterior = nuevoNodo;
    }
    nodoActual->siguiente = nuevoNodo;
}
void Huffman::mostrar() {
    Nodo* temp = inicioL;
    while (temp != nullptr) {
        std::cout << temp->nRepeticiones<<" ("<<(int)temp->byte<<") "<< " <-> ";
        temp = temp->siguiente;
    }
    std::cout << "NULL" << std::endl;
}