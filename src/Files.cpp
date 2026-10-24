#include "Files.h"

#include <fstream>
#include <stdexcept>
#include <iostream>

std::string Files::loadFileContent(const std::string& path)
{
    std::ifstream file(path, std::ios::in);
    std::string fileContents;

    if (!file.good())
        throw std::runtime_error("Files::loadFileContent - File '" + path + "' not found");

    file.seekg(0, std::ios::end);
    fileContents.resize(file.tellg());

    file.seekg(0, std::ios::beg);

    file.read(&fileContents[0], fileContents.size());
    file.close();

    return fileContents;
}
