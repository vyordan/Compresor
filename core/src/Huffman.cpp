#include "Huffman.hpp"

std::vector<uint8_t> Huffman::compress (const std::vector<uint8_t>& buffer){
    std::vector<uint8_t> compressedBuffer; //sera el buffer final incluyendo el arbol binario
    int contadorTamanioLista = 0;
    std::string claves[256] = {""};
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
    
    mostrar();
    //pasar la lista al arbol
    if (contadorTamanioLista > 1)
    {
        convertirListaAArbol(contadorTamanioLista);
        generarCodigos(inicioL, claves, "");
    }
    for (int i = 0; i < 256; i++)
    {
        if (claves[i] != "")
        {
            std::cout<<"token: "<<i<<"\tclave: "<<claves[i]<<std::endl;
        }
        
    }
    
    liberarArbol(inicioL);

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
    //por si la lista esta vacia o si el nuevo valor es mas grande al del inicio 
    if (inicioL == nullptr || nuevoNodo->nRepeticiones >= inicioL->nRepeticiones){
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
    while (nodoActual->siguiente != nullptr && nodoActual->siguiente->nRepeticiones > nuevoNodo->nRepeticiones){
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
    while (tamanioLista > 2){ //estaba pensando en que esto lo puedo cambiar por un finaL -> anterior -> anterior != nullptr
        //creamos un nuevo nodo con la suma de los ultimos dos nodos de la lista
        Nodo* nuevo = new Nodo(0x00,(finalL->anterior->nRepeticiones + finalL->nRepeticiones));
        //el nuevo nodo va apuntar a sus dos hijos
        nuevo->siguienteDerecho = finalL;
        nuevo->siguienteIzquierdo = finalL->anterior;

        /* esto se vale, pero en no realidad solo necesito que finalL apunte al nodo que esta atras del penultimo, y este siguiente = nullptr ()
        //desconectamos estos dos nodos de la listas y hacemos que todos sus punteros de la listan sean nulos
        finalL = finalL->anterior;
        finalL->siguiente->anterior = nullptr;
        finalL->siguiente = nullptr;

        finalL = finalL->anterior;
        finalL->siguiente->anterior = nullptr;
        finalL->siguiente = nullptr;
        */
        //desconecto los ultimos dos nodos de la lista 
        finalL = finalL->anterior->anterior;
        finalL->siguiente = nullptr;
        
        insertarNodoListaOrdenado(nuevo);
        tamanioLista--;
    }
    Nodo* nuevo = new Nodo(0x00,(finalL->anterior->nRepeticiones + finalL->nRepeticiones));
    nuevo->siguienteDerecho = finalL;
    nuevo->siguienteIzquierdo = finalL->anterior;
    inicioL = nuevo;
    finalL = nullptr;
}
void Huffman::obtenerUltimoPuntero(){
    Nodo* aux = inicioL;
    while (aux->siguiente != nullptr){
        aux = aux->siguiente;
    }
    finalL = aux;
} 
//este codigo si sirve, pero lo hice nada mas para testiar la lista y ver que metiera bien los datos, por eso lo mente por que ya no le veo utilidad 
void Huffman::mostrar() {
    Nodo* temp = inicioL;
    while (temp != nullptr) {
        std::cout << temp->nRepeticiones<<" ("<<(int)temp->byte<<") "<< " <-> ";
        temp = temp->siguiente;
    }
    std::cout << "NULL" << std::endl;
}

void Huffman::generarCodigos(Nodo* nodo, std::string claves[], std::string clave){
    if (nodo == nullptr)
    {
        return;
    }
    if ((nodo->siguienteIzquierdo == nullptr) && (nodo->siguienteDerecho == nullptr))
    {   
        //es una hoja entoces ya puedo terminal el proceso y ya esta el codigo metido en el string
        claves[(int)nodo->byte] = clave;
        //std::cout<<nodo->nRepeticiones<<" ("<<(int)nodo->byte<<") "<<" ";
    }
    if (nodo->siguienteIzquierdo != nullptr)
    {
        generarCodigos(nodo->siguienteIzquierdo, claves, clave + "0");
    }
    if (nodo->siguienteDerecho != nullptr)
    {
        generarCodigos(nodo->siguienteDerecho, claves, clave + "1");
    }
}






void Huffman::liberarArbol(Nodo* &raiz) {
    if (raiz == nullptr) return;

    // Primero vamos a las hojas (recorrido post-orden)
    liberarArbol(raiz->siguienteIzquierdo);
    liberarArbol(raiz->siguienteDerecho);

    // Una vez los hijos están libres, borramos el actual
    delete raiz;
    
    // Buena práctica: poner a null para evitar punteros colgantes
    raiz = nullptr;
}