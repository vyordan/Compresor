# Compresor

EN DESARROLLO, este proyecto es un ejercicio y reto tecnico, por eso mismo no se utilizo tutoriales ni IA para generar codigo.

Este es un compreso echo en c++ desde cero.
algoritmos: 
* RLE basico (terminado)
* Huffman (en proceso, para su implementacion solo uso este video como referencia: https://youtu.be/0eh1mLqge_s) 
* LZ77 (pendiente)
* LZW (pendiente)

## Arbol de archivos
al terminar el proyecto tendre esta estructura, estoy usando una arquitectura modular para separar responsabilidades. Al compilar el compresor osea el codigo que esta dentro de la carpeta core se compila como una libreria, al core solo le llega un buffer de bytes (vector<uint8_t>) y regresa otro buffer, de esta manera no le importa de donde vengan los datos a comprimir, la carpeta cli tiene la interfaz por consola, la gui pues una interfaz grafica, y **gracias a la desicion de desacoplar el core nos permite que el compresor se comporte como un microservicio** asi que la carpeta grpc va tener la configuracion del servidor y el contrato proto, por el momento no tengo estos conocimientos pero voy a provechar este proyecto para adquirirlos he implementarlos aqui.
```
compresor/
│
├── CMakeLists.txt
├── README.md
├── .gitignore
├── Dockerfile
│
├── core/
│   ├── CMakeLists.txt
│   ├── include/
│   │   ├── ICompressor.hpp
│   │   ├── HuffmanCompressor.hpp
│   │   ├── RLECompressor.hpp
│   │   ├── LZ77Compressor.hpp
│   │   ├── LZWCompressor.hpp
│   │   └── structures/
│   │       ├── HuffmanNode.hpp
│   │       └── BitBuffer.hpp
│   └── src/
│       ├── HuffmanCompressor.cpp
│       ├── RLECompressor.cpp
│       ├── LZ77Compressor.cpp
│       ├── LZWCompressor.cpp
│       └── BitBuffer.cpp
│
├── cli/
│   ├── CMakeLists.txt
│   ├── include/
│   └── src/
│       └── main.cpp
│
├── gui/
│   ├── CMakeLists.txt
│   ├── include/
│   └── src/
│       └── main.cpp
│
└── grpc/
    ├── CMakeLists.txt
    ├── proto/
    │   └── compressor.proto
    ├── include/
    └── src/
        └── server.cpp
```

## Compilacion

Si queres compilar lo que llevo hasta el momento debes tener instalado CMake y un compilador en mi caso tengo GCC y cmake lo reconoce de manera automatica, seguir los siguientes pasos:

```bash
cd ~/Compresor    #(vas a la carpeta del proyecto)
mkdir -p build          #(aqui creas la carpeta build)
cd build                #(entras a la carpeta build que es la que acabas de crear)
cmake ..                #(preparas la compilacion)
make                    #(compilas)

#en build/cli se genera un archivo llamado Compresor de tipo ejecutable si lo ejecutas (/.Compresor) por el 
#momento es un pequenio test, pero mas adelante sera el ejecutable donde por medio de la terminal se mostrar un menu
#y vas a poder pasar tus archivos para comprimirlos
```
