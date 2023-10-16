#include <cmath>
#include <stdexcept>
#include <iostream>
#include <utility>
#include <memory>
#include <random>
#include <complex>
#include <Vector/Vector.h>
using namespace std;
template <typename T>
void Vector<T>::resize() {
    _capacity += 10;
    T* newData = new T[_capacity];
    for (int i = 0; i < _size; ++i) {
        newData[i] = _data[i];
    }
    delete[] _data;
    _data = newData;
}


template <typename T>
Vector<T>::Vector(size_t size, T& high, T& low) : _size(size), _capacity(size) {
    _data = new T[size];
    for (size_t i = 0; i < size; ++i) {
        _data[i] = low + (rand() % (high - low + 1));
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T>& Second) :_size(Second._size), _capacity(Second._capacity) {
    if (Second._capacity != 0) {
        _data = new T[Second._capacity];
        for (size_t i = 0; i < Second._size; ++i)
            _data[i] = Second._data[i];
    }
    else
        _data = nullptr;
}

template <typename T>
bool Vector<T>::operator==(const Vector& Second) const {
    if (_size != Second._size)
        throw std::invalid_argument("Different dimensions");
    if (typeid(T) == typeid(float) || typeid(T) == typeid(double) || typeid (T) == typeid(std::complex<double>) || typeid (T) == typeid(std::complex<float>)) {
        for (size_t i = 0; i < _size; ++i) {
            T tmp = abs(_data[i]) - abs(Second._data[i]);
            if (tmp.real() > _accuracy || tmp.imag() > _accuracy)
                return false;
        }
    }
    else {
        for (size_t i = 0; i < _size; ++i) {
            if (_data[i] != Second._data[i])
                return false;
        }
    }
    return true;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& Second) {
    if (_size != Second._size)
        throw std::logic_error("Different dimensions");
    for (size_t i = 0; i < _size; ++i)
        _data[i] += Second._data[i];
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& Second) {
    if (_size != Second._size)
        throw std::logic_error("Different dimensions");
    for (size_t i = 0; i < _size; ++i)
        _data[i] -= Second._data[i];
    return *this;
}

template <typename T>
T& Vector<T>::operator*(const Vector<T>& Second) {
    T answer = _data[0] * Second._data[0];
    for (size_t i = 1; i < _size; ++i)
        answer += _data[i] * Second._data[i];
    return answer;
}

// ќператор умножени€ вектора на скал€р (слева)
template <typename T>
Vector<T> Vector<T>::operator*(const T& scalar) const {
    Vector<T> result(*this);
    for (int i = 0; i < _size; ++i) {
        result._data[i] *= scalar;
    }
    return result;
}

//ќператор делени€ вектора на скал€р
template <typename T>
Vector<T> Vector<T>::operator/(const T& scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    Vector<T> result(*this);
    for (int i = 0; i < _size; ++i) {
        result._data[i] /= scalar;
    }
    return result;
}
