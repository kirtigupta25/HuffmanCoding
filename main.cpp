#include "huffman.h"
#include "io.h"
#include <iostream>

int main() {
    // Read input file
    std::string inputFileName = "input.txt";
    std::string inputFileContent = readFile(inputFileName);

    // Perform Huffman coding
    HuffmanTree huffmanTree(inputFileContent);
    std::string encodedData = huffmanTree.encode(inputFileContent);

    // Write encoded data to output file
    std::string encodedOutputFileName = "encoded_output.txt";
    writeFile(encodedOutputFileName, encodedData);

    std::cout << "Huffman encoding completed. Encoded data saved in " << encodedOutputFileName << std::endl;

    // Decode the encoded data
    std::string decodedData = huffmanTree.decode(encodedData);

    // Write decoded data to another output file
    std::string decodedOutputFileName = "decoded_output.txt";
    writeFile(decodedOutputFileName, decodedData);

    std::cout << "Huffman decoding completed. Decoded data saved in " << decodedOutputFileName << std::endl;

    return 0;
}
