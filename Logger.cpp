//
// Created by remy on 4/8/22.
//

#include "Logger.h"
#include <iomanip>
#include <iostream>

Logger::Logger() : m_out{""} {
    // generate automatic file name with the current date/ time
    std::ostringstream oss{};
    auto time = std::time(nullptr);
    oss << std::put_time(std::localtime(&time), "Log_%F_%H_%M_%S.txt");
    // open a new log file
    this->m_out = FileWriter {oss.str()};
    if (!m_out.is_open())
        std::cerr << "Logger::Logger: error opening log file " << oss.str() <<
                  '\n';
}

// notice: no `static`in the signature here!
// `static`is only placed in the declaration
Logger& Logger::get(){
    static Logger the_only_instance{};
    return the_only_instance;
}

void Logger::log(const std::string& msg){
    if (m_out.is_open()){
        // each message is prepended with the current time
        auto time = std::time(nullptr);
        char mbstr[100];
        if (std::strftime(mbstr, sizeof(mbstr), "%A %c", std::localtime(&time))) {
            m_out.write(mbstr).new_line();
        }
    }
    else{
        std::cerr << "Logger::log: log file not open\n";
    }
}


