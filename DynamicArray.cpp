//
// Created by remy on 4/3/22.
//

#include <algorithm>
#include "DynamicArray.h"

const static std::size_t DEFAULT_CAP {16};
const static std::size_t GROWTH_FAC {2};

DynamicArray::DynamicArray(std::size_t capacity) :
    m_capacity {capacity ? capacity : DEFAULT_CAP},
    m_size {0},
    m_data { new double[this->m_capacity] } {
    s_tracker.add_instance();
    s_tracker.add_memory(this->m_capacity);
}

DynamicArray::DynamicArray() : DynamicArray {DEFAULT_CAP} {

}

DynamicArray::~DynamicArray() {
    delete[] this->m_data;
    s_tracker.remove_memory(this->m_capacity);
    s_tracker.remove_instance();
}

double *DynamicArray::get() {
    return this->m_data;
}

const double *DynamicArray::get() const {
    return this->m_data;
}

double &DynamicArray::at(std::size_t index) {
    return this->m_data[index];
}

const double &DynamicArray::at(std::size_t index) const {
    return this->m_data[index];
}

std::size_t DynamicArray::size() const {
    return this->m_size;
}

std::size_t DynamicArray::capacity() const {
    return this->m_capacity;
}

void DynamicArray::push_n(std::size_t count, double val) {
    reserve(this->m_size + count);
    std::fill_n(&m_data[m_size], count, val);
    m_size += count;
}

void DynamicArray::push_back(double val) {
    reserve(this->size() + 1);
    this->m_data[this->m_size++] = val;
}

double DynamicArray::pop_back() {
    this->m_size--;
    return this->m_data[this->m_size];
}

void DynamicArray::insert(std::size_t index, double val) {
    reserve(this->size() + 1);
    std::move(&this->m_data[index], &this->m_data[this->m_size], &this->m_data[index + 1]);
    this->m_data[index] = val;
    this->m_size++;
}

double DynamicArray::remove(std::size_t index) {
    auto result { this->m_data[index] };
    std::move(&this->m_data[index + 1], &this->m_data[this->m_size], &this->m_data[index]);
    this->m_size--;
    return result;
}

void DynamicArray::reserve(std::size_t min_capacity) {
    auto new_capacity = this->m_capacity;
    while (new_capacity < min_capacity) {
        new_capacity *= GROWTH_FAC;
    }

    if (new_capacity != this->m_capacity) {
        // Add memory to the tracker
        auto delta_size = new_capacity - this->m_capacity;
        s_tracker.add_memory(delta_size);
        // Create a new array
        auto data = new double[new_capacity]{};
        std::copy(&this->m_data[0], &this->m_data[this->m_size], &data[0]);
        // Deallocate old array
        delete[] this->m_data;
        this->m_data = data;
        this->m_capacity = new_capacity;
    }
}

const Tracker &DynamicArray::tracker() {
    return s_tracker;
}
