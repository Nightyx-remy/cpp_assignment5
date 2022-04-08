//
// Created by remy on 3/30/22.
//

#ifndef CPP_ASSIGNMENT5_TRACKER_H
#define CPP_ASSIGNMENT5_TRACKER_H


#include <cstddef>

class Tracker {
public:
    Tracker();

    void add_instance();
    void remove_instance();
    void add_memory(std::size_t memory);
    void remove_memory(std::size_t memory);

    std::size_t memory() const;
    std::size_t instances() const;
private:
    std::size_t m_instance_count;
    std::size_t m_memory_count;
};


#endif //CPP_ASSIGNMENT5_TRACKER_H
