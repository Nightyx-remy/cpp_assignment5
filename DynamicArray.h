//
// Created by remy on 4/3/22.
//

#ifndef CPP_ASSIGNMENT5_DYNAMICARRAY_H
#define CPP_ASSIGNMENT5_DYNAMICARRAY_H


#include <cstddef>
#include "Tracker.h"

class DynamicArray {
public:
    DynamicArray(std::size_t capacity);
    DynamicArray();
    ~DynamicArray();

    double* get();
    const double* get() const;

    double& at(std::size_t index);
    const double& at(std::size_t index) const;

    std::size_t size() const;
    std::size_t capacity() const;

    void push_n(std::size_t count, double val);
    void push_back(double val);
    double pop_back();

    void insert(std::size_t index, double val);
    double remove(std::size_t index);

    static const Tracker& tracker();
private:
    std::size_t m_capacity;
    std::size_t m_size;
    double* m_data;

    void reserve(std::size_t min_capacity);

    static inline Tracker s_tracker {};
};


#endif //CPP_ASSIGNMENT5_DYNAMICARRAY_H
