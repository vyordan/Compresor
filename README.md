# Compresor
Compresor de archivos en C++ reduce el tamaño de datos eliminando redundancias usando los algoritmos mas conocidos.

Proyecto Personal.
algoritmos agregados: 
    RLE basico (terminado)
    Huffman (en proceso)
    LZ77 (pendiente)
    LZW (pendiente)

Si queres compilar lo que llevo hasta el momento debes tener instalado CMake y un compilador en mi caso tengo GCC y cmake lo reconoce de manera automatica, (tambien tene en cuenta que lo desarrolle en linux, lo mensiono por el tema de las rutas que estan escritas con "/"),luego seguir los siguientes pasos:

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
