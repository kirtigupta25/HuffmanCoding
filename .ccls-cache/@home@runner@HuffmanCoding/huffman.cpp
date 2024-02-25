#include "huffman.h"
#include <queue>
#include <unordered_map>

void HuffmanTree::buildEncodingMap(TreeNode *root, std::string code) {
  if (root) {
    if (!root->left && !root->right) {
      encodingMap[root->data] = code;
    }
    buildEncodingMap(root->left, code + "0");
    buildEncodingMap(root->right, code + "1");
  }
}

void HuffmanTree::buildDecodingMap(TreeNode *root, std::string code) {
  if (root) {
    if (!root->left && !root->right) {
      decodingMap[code] = root->data;
    }
    buildDecodingMap(root->left, code + "0");
    buildDecodingMap(root->right, code + "1");
  }
}

HuffmanTree::HuffmanTree(const std::string &text) {
  std::unordered_map<char, int> freqMap;
  for (char c : text) {
    freqMap[c]++;
  }

  std::priority_queue<TreeNode *, std::vector<TreeNode *>, Compare> minHeap;
  for (auto &pair : freqMap) {
    minHeap.push(new TreeNode(pair.first, pair.second));
  }

  while (minHeap.size() > 1) {
    TreeNode *left = minHeap.top();
    minHeap.pop();
    TreeNode *right = minHeap.top();
    minHeap.pop();
    TreeNode *mergedNode =
        new TreeNode('$', left->frequency + right->frequency);
    mergedNode->left = left;
    mergedNode->right = right;
    minHeap.push(mergedNode);
  }

  root = minHeap.top();
  buildEncodingMap(root, "");
  buildDecodingMap(root, ""); // Build decoding map
}

std::string HuffmanTree::encode(const std::string &text) {
  std::string encodedText;
  for (char c : text) {
    encodedText += encodingMap[c];
  }
  return encodedText;
}

std::string HuffmanTree::decode(const std::string &encodedText) {
  std::string decodedText;
  std::string code;
  for (char bit : encodedText) {
    code += bit;
    if (decodingMap.find(code) != decodingMap.end()) {
      decodedText += decodingMap[code];
      code = "";
    }
  }
  return decodedText;
}
