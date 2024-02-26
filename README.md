# Huffman Encoding and Decoding

This project implements Huffman encoding and decoding algorithms in C++. Huffman coding is a widely used method for lossless data compression.

## Overview

The project consists of the following components:

1. **Main Program (`main.cpp`)**:
   - Reads input text from a file (`input.txt`).
   - Constructs a Huffman tree based on the frequency of characters in the input text.
   - Encodes the input text using Huffman coding and saves the encoded data to an output file (`encoded_output.txt`).
   - Decodes the encoded data back to the original text and saves it to another output file (`decoded_output.txt`).

2. **Huffman Tree Implementation (`huffman.h` and `huffman.cpp`)**:
   - Defines the `HuffmanTree` class, which represents the Huffman tree data structure.
   - Constructs the Huffman tree based on the frequency of characters in the input text.
   - Provides functions to encode and decode text using the constructed Huffman tree.

3. **File Input/Output Utilities (`io.h` and `io.cpp`)**:
   - Provides functions for reading from and writing to files.

## Usage

To use this program, follow these steps:

1. Compile the source files using a C++ compiler.
