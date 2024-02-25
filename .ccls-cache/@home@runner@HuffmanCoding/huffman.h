#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <queue>
#include <string>
#include <unordered_map>

struct TreeNode {
  char data;
  int frequency;
  TreeNode *left, *right;
  TreeNode(char data, int frequency)
      : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

class Compare {
public:
  bool operator()(TreeNode *a, TreeNode *b) {
    return a->frequency > b->frequency;
  }
};

class HuffmanTree {
private:
  TreeNode *root;
  std::unordered_map<char, std::string> encodingMap;
  std::unordered_map<std::string, char> decodingMap; // Added for decoding

  void buildEncodingMap(TreeNode *root, std::string code);
  void buildDecodingMap(TreeNode *root, std::string code); // Added for decoding

public:
  HuffmanTree(const std::string &text);
  std::string encode(const std::string &text);
  std::string decode(const std::string &encodedText); // Added for decoding
};

#endif
