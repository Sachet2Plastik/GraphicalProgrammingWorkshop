#ifndef FILES_H
#define FILES_H
#include <string>

class Files
{
public:
    static std::string loadFileContent(const std::string &path);
};

#endif // FILES_H