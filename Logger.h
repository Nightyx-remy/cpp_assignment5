//
// Created by remy on 4/8/22.
//

#ifndef CPP_ASSIGNMENT5_LOGGER_H
#define CPP_ASSIGNMENT5_LOGGER_H


#include <string>
#include "FileWriter.h"

class Logger {
public:
    Logger& get();
    void log(const std::string& msg);
private:
    Logger();
    FileWriter m_out;
};

#endif //CPP_ASSIGNMENT5_LOGGER_H
