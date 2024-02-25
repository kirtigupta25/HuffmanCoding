#include "io.h"
#include <fstream>

std::string readFile(const std::string &filename) {
  std::ifstream file(filename);
  std::string content((std::istreambuf_iterator<char>(file)),
                      (std::istreambuf_iterator<char>()));
  file.close();
  return content;
}

void writeFile(const std::string &filename, const std::string &content) {
  std::ofstream file(filename);
  file << content;
  file.close();
}
