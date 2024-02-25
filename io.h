#ifndef IO_H
#define IO_H

#include <string>

std::string readFile(const std::string &filename);
void writeFile(const std::string &filename, const std::string &content);

#endif
