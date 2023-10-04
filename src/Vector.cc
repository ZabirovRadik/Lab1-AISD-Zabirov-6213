#include <cmath>
#include <stdexcept>
#include <iostream>
#include <utility>
#include <memory>
#include <algorithm>

using namespace std;
template <typename T>
class Vector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;

    void resize() {
        _capacity += 10;
        T* newData = new T[_capacity];
        for (int i = 0; i < _size; ++i) {
            newData[i] = _data[i];
        }
        delete[] _data;
        _data = newData;
    }
public:
    Vector() : _size(0), _capacity(10) {
        _data = new T[_capacity];
    }

    Vector(size_t capacity, T& item) :_size(1), _capacity(capacity) {
        _data = new T[_capacity];
        _data[0] = item;
    }

    Vector(const Vector<T>& Second) :_size(Second._size), _capacity(Second._capacity) {
        _data = new T[_capacity];
        for (size_t i; i < _size; ++i)
            _data[i] = Second._data[i];
    }

    int getSize() const {
        return _size;
    }

    void push_back(const T& value) {
        if (_size >= _capacity) {
            resize();
        }
        _data[_size++] = value;
    }

    const T& operator[](size_t index) const {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("»ндекс вне диапазона");
        }
        return _data[index];
    }

    T& operator[](size_t index) {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("»ндекс вне диапазона");
        }
        return _data[index];
    }

    Vector<T>& operator+=(const Vector<T>& Second) {
        if (_size != Second._size) :
            throw std::logic_error("Different dimensions");
        for (size_t i; i < _size; ++i)
            _data[i] += Second._data[i];
        return *this;
    }

    Vector<T> operator+(const Vector<T>& Second) const {
        Vector Temporary(Second);
        return Temporary += *this;
    }

    Vector<T>& operator-=(const Vector<T>& Second) {
        if (_size != Second._size) :
            throw std::logic_error("Different dimensions");
        for (size_t i; i < _size; ++i)
            _data[i] -= Second._data[i];
        return *this;
    }

    Vector<T> operator-(const Vector& Second) const {
        Vector Temporary(Second);
        return Temporary -= *this;
    }

    T& operator*(const Vector<T>& Second) {
        T answer;
        for (size_t i; i < _size; ++i)
            answer += _data[i] * Second._data[i];
        return answer;
    }

    // ќператор умножени€ вектора на скал€р (слева)
    Vector<T> operator*(const T& scalar) const {
        Vector<T> result(*this); 
        for (int i = 0; i < size; ++i) {
            result.data[i] *= scalar;
        }
        return result;
    }

    // ќператор умножени€ вектора на скал€р (справа)
    friend Vector<T> operator*(const T& scalar, const Vector<T>& This) {
        return This * scalar;
    }

    //ќператор делени€ вектора на скал€р
    Vector<T> operator/(const T& scalar) const {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero is not allowed");
        }
        Vector<T> result(*this); 
        for (int i = 0; i < size; ++i) {
            result.data[i] /= scalar; 
        }
        return result;
    }

    ~Vector() {
        delete[] _data;
    }

};