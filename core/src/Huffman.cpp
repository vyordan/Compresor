#include "Huffman.hpp"

std::vector<uint8_t> Huffman::compress (const std::vector<uint8_t>& buffer){
    std::vector<uint8_t> compressedBuffer; //sera el buffer final incluyendo el arbol binario
    int contadorTamanioLista = 0;

    //cada posicion [n] es un token y en el espacio en memoria de esa posicion se va almacenar el la cantidad de veces que se repita ese token
    int contadorRepeticiones[256] = {0}; //el indice representa el token (osea el byte) y el dato que se guarda va ser las veces que se repita
    for (int i = 0; i < buffer.size(); i++){
        contadorRepeticiones[(int)buffer[i]]++;
    }
    
    //paso contadorRepeticiones a la lista 
    for (int i = 0; i < 256; i ++){
        if (contadorRepeticiones[i] > 0){
            insertarNodoListaOrdenado(contadorRepeticiones[i], static_cast<uint8_t>(i)); //use es cast para pasar ese int a uint8_t esto sin ninguna veriricacion pues estoy seugor que esta en el rango que le cabe a un byte
            contadorTamanioLista++;
        }
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
void Huffman::insertarNodoListaOrdenado(Nodo*& nuevoNodo){
    //Nodo* nuevoNodo = new Nodo(token, contadorR);
    int contadorR = nuevoNodo->nRepeticiones;

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
void Huffman::convertirListaAArbol(int& tamanioLista){
    obtenerUltimoPuntero();
    while (tamanioLista > 1){
        Nodo* nuevo = new Nodo(0x00,(finalL->anterior->nRepeticiones + finalL->nRepeticiones));
        
        desconectamos estos dos nodos de la listas
        finalL = finalL->anterior;
        finalL->siguiente->anterior = nullptr;
        finalL->siguiente = nullptr;

        finalL = finalL->anterior;
        finalL->siguiente->anterior = nullptr;
        finalL->siguiente = nullptr;

        insertarNodoListaOrdenado(nuevo);
        tamanioLista--;
    }
}
/* este codigo si sirve, pero lo hice nada mas para testiar la lista y ver que metiera bien los datos, por eso lo mente por que ya no le veo utilidad 
void Huffman::mostrar() {
    Nodo* temp = inicioL;
    while (temp != nullptr) {
        std::cout << temp->nRepeticiones<<" ("<<(int)temp->byte<<") "<< " <-> ";
        temp = temp->siguiente;
    }
    std::cout << "NULL" << std::endl;
}
*/
void Huffman::obtenerUltimoPuntero(){
    Nodo* aux = inicioL;
    while (aux->siguiente != nullptr){
        aux = aux->siguiente;
    }
    finalL = aux;
}