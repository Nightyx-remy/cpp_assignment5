//
// Created by remy on 4/8/22.
//

#include <iostream>
#include "FileWriter.h"
#include <cstring>
#include <math.h>

FileWriter::FileWriter(std::string file_name) : file{std::fopen(file_name.c_str(), "w")}, chars{0}, new_lines{0} {
    if (!this->file) {
        std::cout << "Failed to open file '" << file_name << "'!" << std::endl;
    }
}

FileWriter::~FileWriter() {
    std::fflush(this->file);
    std::fclose(this->file);
}

bool FileWriter::is_open() const {
    return this->file;
}

FileWriter &FileWriter::write(std::string value) {
    std::fputs(value.c_str(), this->file);

    this->chars += value.length();
    for (char c : value) if (c == '\n') this->new_lines++;

    return *this;
}

FileWriter &FileWriter::write(const char *value) {
    std::fputs(value, this->file);

    std::size_t len = std::strlen(value);
    this->chars += len;
    for (int i = 0; i < len; i++) if(value[i] == '\n') this->new_lines++;

    return *this;
}

FileWriter &FileWriter::write(char value) {
    std::fputc(value, this->file);
    this->chars++;
    if (value == '\n') this->new_lines++;
    return *this;
}

FileWriter &FileWriter::write(int value) {
    std::fprintf(this->file, "%d", value);
    this->chars += (int) std::floor(std::log10((float) value));
    return *this;
}

FileWriter &FileWriter::write(double value) {
    std::fprintf(this->file, "%d", value);
    this->chars += (int) std::floor(std::log10((float) value));
    return *this;
}

FileWriter &FileWriter::write(bool value) {
    if (value) {
        std::fputs("true", this->file);
        this->chars += 4;
    } else {
        std::fputs("false", this->file);
        this->chars += 5;
    }
    return *this;
}

FileWriter &FileWriter::then(std::string value) {
    std::fputs(value.c_str(), this->file);

    this->chars += value.length();
    for (char c : value) if (c == '\n') this->new_lines++;

    return *this;
}

FileWriter &FileWriter::then(const char *value) {
    std::fputs(value, this->file);

    std::size_t len = std::strlen(value);
    this->chars += len;
    for (int i = 0; i < len; i++) if(value[i] == '\n') this->new_lines++;

    return *this;
}

FileWriter &FileWriter::then(char value) {
    std::fputc(value, this->file);
    this->chars++;
    if (value == '\n') this->new_lines++;
    return *this;
}

FileWriter &FileWriter::then(int value) {
    std::fprintf(this->file, "%d", value);
    this->chars += (int) std::ceil(std::log10((float) value));
    return *this;
}

FileWriter &FileWriter::then(double value) {
    std::fprintf(this->file, "%d", value);
    this->chars += (int) std::floor(std::log10((float) value));
    return *this;
}

FileWriter &FileWriter::then(bool value) {
    if (value) {
        std::fputs("true", this->file);
        this->chars += 4;
    } else {
        std::fputs("false", this->file);
        this->chars += 5;
    }
    return *this;
}

FileWriter &FileWriter::new_line() {
    std::fputs("\n", this->file);
    this->new_lines++;
    this->chars++;
    return *this;
}

unsigned int FileWriter::lines() const {
    return this->new_lines;
}

unsigned int FileWriter::size() const {
    return this->chars;
}
