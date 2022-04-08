//
// Created by remy on 4/8/22.
//

#ifndef CPP_ASSIGNMENT5_FILEWRITER_H
#define CPP_ASSIGNMENT5_FILEWRITER_H


#include <string>

class FileWriter {
private:
    std::FILE* file;
    unsigned int new_lines;
    unsigned int chars;
public:
    FileWriter(std::string file_name);
    ~FileWriter();

    bool is_open() const;

    FileWriter& write(std::string value);
    FileWriter& write(const char* value);
    FileWriter& write(char value);
    FileWriter& write(int value);
    FileWriter& write(double value);
    FileWriter& write(bool value);

    FileWriter& then(std::string value);
    FileWriter& then(const char* value);
    FileWriter& then(char value);
    FileWriter& then(int value);
    FileWriter& then(double value);
    FileWriter& then(bool value);

    FileWriter& new_line();

    unsigned int lines() const;

    unsigned int size() const;
};


#endif //CPP_ASSIGNMENT5_FILEWRITER_H
