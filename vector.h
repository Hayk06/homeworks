#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>

template <typename T>
class Vector {
private:
    T* data;
    int size;
    int capacity;

public:
    Vector();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);

    void push_back(const T& value);
    void pop_back();
    T& operator[](int index);
    const T& operator[](int index) const;
    int size_() const;
    T* begin() const;
    T* end() const;
    ~Vector();
};

template <typename T>
Vector<T>::Vector() {
    data = nullptr;
    size = 0;
    capacity = 0;
}

template <typename T>
Vector<T>::Vector(const Vector& other) {
    size = other.size;
    capacity = other.capacity;
    data = (capacity > 0) ? new T[capacity] : nullptr;
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        T* new_data = (other.capacity > 0) ? new T[other.capacity] : nullptr;
        for (int i = 0; i < other.size; i++) {
            new_data[i] = other.data[i];
        }
        delete[] data;
        data = new_data;
        size = other.size;
        capacity = other.capacity;
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity) {
        int new_capacity = (capacity == 0) ? 1 : capacity * 2;

        T* new_data = new T[new_capacity];

        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }

        delete[] data;

        data = new_data;
        capacity = new_capacity;
    }

    data[size] = value;
    size++;
}

template <typename T>
void Vector<T>::pop_back() {
    if (size > 0) {
        size--;
    }
}

template <typename T>
T& Vector<T>::operator[](int index) {
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
    return data[index];
}

template <typename T>
int Vector<T>::size_() const {
    return size;
}

template <typename T>
T* Vector<T>::begin() const {
    return data;
}

template <typename T>
T* Vector<T>::end() const {
    return data + size;
}

#endif
