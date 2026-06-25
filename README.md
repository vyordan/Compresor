# Compresor (Compression Tool)

**Status:** In active development – This is a personal challenge and technical exercise, built without tutorials or AI-generated code.

A custom compression tool written from scratch in C++. Implements multiple algorithms in a modular core, with CLI/GUI/gRPC interfaces.

## Supported Algorithms
- **Run-Length Encoding (RLE)** – Basic implementation (completed).
- **Huffman Coding** – In progress (reference: [this video](https://youtu.be/0eh1mLqge_s) for conceptual understanding).
- **LZ77** – Planned.
- **LZW** – Planned.

## Project Architecture

The code is organized into four modules, enforcing a strong separation of concerns:

| Module | Purpose |
|--------|---------|
| `core` | Compression algorithms library – Takes a raw byte buffer (`vector<uint8_t>`) and returns a compressed buffer. No knowledge of data source or destination. |
| `cli`  | Command-line interface for the compressor. |
| `gui`  | (Future) Graphical interface. |
| `grpc` | (Future) gRPC server – Exposes the core as a microservice using Protocol Buffers. |

This decoupled design means the core can be reused in any context (local CLI, remote microservice, embedded system) without modification.

### Planned File Tree
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


## Build Instructions (Current State)

**Requirements:** CMake, a C++ compiler (tested with GCC on Linux).

```bash
cd Compresor
mkdir -p build
cd build
cmake ..
make

#The executable Compresor will be placed in build/cli/. For now it runs a small internal test; a full CLI menu with  file input/output is under development.
```
## Motivation & Learning Goals
- Implement classic compression algorithms from scratch, deepening my understanding of data structures, bit-level operations, and algorithm design.

- Practice modular C++ architecture and clean API design (ICompressor interface, library separation).

- Explore modern system communication by adding a gRPC microservice layer.

- Prove self-directed learning: no AI-generated code, minimal reliance on tutorials – only conceptual references.
