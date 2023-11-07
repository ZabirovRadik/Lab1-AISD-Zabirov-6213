#include <cmath>
#include <stdexcept>
#include <iostream>
#include <utility>
#include <memory>
#include <windows.h>
#include <random>
#include <complex>

using namespace std;
template <typename T>
class Vector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;
    void resize() {
        _capacity += 10;
        T* new_data = new T[_capacity];
        for (int i = 0; i < _size; ++i) {
            new_data[i] = _data[i];
        }
        if(_data)
            delete[] _data;
        _data = new_data;
    }
public:
    static const double accuracy;

    Vector() : _size(0), _capacity(0), _data(nullptr) {}

    Vector(size_t capacity, T& item) :_size(1), _capacity(capacity) {
        if (capacity < 1)
            throw std::invalid_argument("Uncorrected capacity");
        _data = new T[_capacity];
        _data[0] = item;
    }

    Vector(size_t size, T& low, T& high);

    Vector(const Vector<T>& Second) :_size(Second._size), _capacity(Second._capacity) {
        if (Second._capacity != 0) {
            _data = new T[Second._capacity];
            for (size_t i = 0; i < Second._size; ++i)
                _data[i] = Second._data[i];
        }
        else
            _data = nullptr;
    }

    size_t get_capacity() const {
        return _capacity;
    }

    size_t get_size() const {
        return _size;
    }

    void push_back(const T& value) {
        if (!_data) {
            _data = new T[5];
            _capacity = 5;
        }
        if (_size >= _capacity) {
            resize();
        }
        _data[_size] = value;
        ++_size;
    }

    const T& operator[](size_t index) const {
        if (index < 0 || index >= _capacity) {
            throw std::out_of_range("Out of range");
        }
        return _data[index];
    }

    T& operator[](size_t index) {
        if (index < 0 || index >= _capacity) {
            throw std::out_of_range("Out of range");
        }
        return _data[index];
    }

    void insert(size_t index, T& item) {
        _data[index] = item;
    }

    bool operator==(const Vector& Second) const;

    Vector<T>& operator+=(const Vector<T>& Second) {
        if (_size != Second._size)
            throw std::logic_error("Different dimensions");
        for (size_t i = 0; i < _size; ++i)
            _data[i] += Second._data[i];
        return *this;
    }

    Vector<T> operator+(const Vector<T>& Second) const {
        Vector Temporary(Second);
        return Temporary += *this;
    }

    bool operator!=(const Vector& Second) const {
        return (*this == Second) == false;
    }

    Vector<T>& operator-=(const Vector<T>& Second) {
        if (_size != Second._size)
            throw std::logic_error("Different dimensions");
        for (size_t i = 0; i < _size; ++i)
            _data[i] -= Second._data[i];
        return *this;
    }

    Vector<T> operator-(const Vector& Second) const {
        Vector Temporary(Second);
        return Temporary -= *this;
    }

    T& operator*(const Vector<T>& Second);

    // ќператор умножени€ вектора на скал€р (слева)
    Vector<T> operator*(const T& scalar) const {
        Vector<T> result(*this);
        for (int i = 0; i < _size; ++i) {
            result._data[i] *= scalar;
        }
        return result;
    }

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

    friend istream& operator>>(istream& is, Vector& ivec){
        cout << "\nSize of vector:";
        is >> ivec._capacity;
        if (ivec._capacity == 0) {
            ivec._data = nullptr;
            ivec._size = 0;
            return is;
        }
        else{
            ivec._data = new T[ivec._capacity];
            ivec._size = insert_data<T>(is, ivec._data, ivec._capacity);
            return is;
        }
    }

    Vector<T>& normalize();

    ~Vector() {
        delete[] _data;
    }
};

template<typename T>
const double Vector<T>::accuracy = 0.000001;



