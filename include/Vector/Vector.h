#include <cmath>
#include <stdexcept>
#include <iostream>
#include <utility>
#include <memory>
#include <random>
#include <complex>

using namespace std;
template <typename T>
class Vector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;
    void resize();
public:
    static const double _accuracy;

    Vector() : _size(0), _capacity(0), _data(nullptr) {}

    Vector(size_t capacity, T& item) :_size(1), _capacity(capacity) {
        if (capacity < 1)
            throw std::invalid_argument("Uncorrected capacity");
        _data = new T[_capacity];
        _data[0] = item;
    }

    Vector(size_t size, T& high, T& low) ;

    Vector(const Vector<T>& Second);

    size_t get_capacity() const {
        return _capacity;
    }

    size_t get_size() const {
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
            throw std::out_of_range("Out of range");
        }
        return _data[index];
    }

    T& operator[](size_t index) {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Out of range");
        }
        return _data[index];
    }

    bool operator==(const Vector& Second) const;

    Vector<T>& operator+=(const Vector<T>& Second);

    Vector<T> operator+(const Vector<T>& Second) const {
        Vector Temporary(Second);
        return Temporary += *this;
    }

    bool operator!=(const Vector& Second) const {
        return (*this == Second) == false;
    }

    Vector<T>& operator-=(const Vector<T>& Second);

    Vector<T> operator-(const Vector& Second) const {
        Vector Temporary(Second);
        return Temporary -= *this;
    }

    T& operator*(const Vector<T>& Second);

    // ќператор умножени€ вектора на скал€р (слева)
    Vector<T> operator*(const T& scalar) const;

    // ќператор умножени€ вектора на скал€р (справа)
    friend Vector<T> operator*(const T& scalar, const Vector<T>& This) {
        return This * scalar;
    }

    //ќператор делени€ вектора на скал€р
    Vector<T> operator/(const T& scalar) const;

    friend ostream& operator<<(ostream& s, const Vector& o) {
        s << "(";
        for (size_t i = 0; i < o._size; ++i) {
            s << o._data[i];
            if (i != o._size - 1) s << ";";
        }
        s << ")";
        return s;
    }

    friend istream& operator>>(istream& s, Vector& o) {
        char c;
        cout << "Capacity is: ";
        s >> o._capacity;
        if (o._size > 0) {
            delete[] o._data;
            o._size = 0;
        }
        o._data = new T[o._capacity];
        cout << "Enter the vector elements: ";
        for (size_t i = 0; i < o._capacity; ++i) {
            s >> o._data[i];
            if (i != o._capacity) {
                s >> c; // ;
            }
        }
        return s;
    }

    ~Vector() {
        delete[] _data;
    }

};

const double Vector<complex<double>>::_accuracy = 0.000001;
