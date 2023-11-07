#include <cmath>
#include <stdexcept>
#include <iostream>
#include <utility>
#include <memory>
#include <random>
#include <complex>
#include <Vector/Vector.h>
using namespace std;



//Оператор деления вектора на скаляр
template <>
Vector<complex<double>> Vector<complex<double>>::operator/(const complex<double>& scalar) const {
    if (norm(scalar) == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    Vector<complex<double>> result(*this);
    for (size_t i = 0; i < _size; i++) {
        result[i] = _data[i] / scalar;
    }
    return result;

}

template <>
Vector<complex<float>> Vector<complex<float>>::operator/(const complex<float>& scalar) const {
    if(norm(scalar) == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    Vector<complex<float>> result(*this);
    for (int i = 0; i < _size; i++) {
        result[i] = _data[i] / scalar;
    }
    return result;

}

template <typename T>
Vector<T> Vector<T>::operator/(const T& scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    Vector<T> result(*this);
    for (size_t i = 0; i < _size; ++i) {
        result._data[i] /= scalar;
    }
    return result;
}


template <>
bool Vector<complex<double>>::operator==(const Vector& Second) const {
    if (_size != Second._size)
        throw std::invalid_argument("Different dimensions");
    for (size_t i = 0; i < _size; ++i) {
        if (std::fabs(_data[i].real() - Second._data[i].real()) > accuracy && std::fabs(_data[i].imag() - Second._data[i].imag()) > accuracy)
            return false;
    }
    return true;
}

template <>
bool Vector<complex<float>>::operator==(const Vector& Second) const {
    if (_size != Second._size)
        throw std::invalid_argument("Different dimensions");
    for (size_t i = 0; i < _size; ++i) {
        if (std::fabs(_data[i].real() - Second._data[i].real()) > accuracy && std::fabs(_data[i].imag() - Second._data[i].imag()) > accuracy)
            return false;
    }
    return true;
}


template<>
bool Vector<int>::operator==(const Vector& Second) const {
    if (_size != Second._size)
        throw std::invalid_argument("Different dimensions");
    for (size_t i = 0; i < _size; ++i) {
        if (_data[i] != Second._data[i])
            return false;
    }
    return true;
}

template <typename T>
bool Vector<T>::operator==(const Vector& Second) const {
    if (_size != Second._size)
        throw std::invalid_argument("Different dimensions");
    for (size_t i = 0; i < _size; ++i) {
        if (std::fabs(_data[i] - Second._data[i]) > accuracy)
            return false;
    }
    return true;
}

size_t insert_data(istream& is, complex<double>* data, size_t capacity) {
    size_t i;
    for (i = 0; i < capacity; ++i) {
        cout << "shall we continue??(Y/N) ";
        char c;
        is >> c;
        if (c == 'N') {
            return i;
        }
        cout << "enter " << i + 1 << " el: ";
        double real, im;
        is >> real >> im;
        data[i] = complex<double>(real, im);
    }
}

size_t insert_data(istream& is, complex<float>* data, size_t capacity) {
    size_t i;
    for (i = 0; i < capacity; ++i) {
        cout << "shall we continue??(Y/N) ";
        char c;
        is >> c;
        if (c == 'N') {
            return i;
        }
        cout << "enter " << i + 1 << " el: ";
        float real, im;
        is >> real >> im;
        data[i] = complex<float>(real, im);
    }
}

template<typename T>
size_t insert_data(istream& is, T* data, size_t capacity) {
    size_t i;
    for (i = 0; i < capacity; ++i) {
        cout << "Shall we continue?(Y/N) ";
        char c;
        is >> c;
        if (c == 'N') {
            return i;
        }
        cout << "enter " << i + 1 << " el: ";
        T item;
        is >> item;
        T tmp = item;
        data[i] = tmp;
    }
}



template <>
Vector<complex<double>>::Vector(size_t size, complex<double>& low, complex<double>& high) : _size(size), _capacity(size) {
    if (low.real() > high.real() || low.imag() > high.imag())
        throw std::invalid_argument("High < low");
    _data = new complex<double>[size];
    for (size_t i = 0; i < size; ++i) {
        srand((size_t)time(NULL) + i + rand());
        double rand_real = low.real() + static_cast<double>(rand()) * static_cast<double>(high.real() - low.real()) / RAND_MAX;
        srand((size_t)time(NULL) + i + rand());
        double rand_imag = low.imag() + static_cast<double>(rand()) * static_cast<double>(high.imag() - low.imag()) / RAND_MAX;
        _data[i] = complex<double>(rand_real, rand_imag);
    }
}

template <>
Vector<complex<float>>::Vector(size_t size, complex<float>& low, complex<float>& high) : _size(size), _capacity(size) {
    if (low.real() > high.real() || low.imag() > high.imag())
        throw std::invalid_argument("High < low");
    _data = new complex<float>[size];
    for (size_t i = 0; i < size; ++i) {
        srand((size_t)time(NULL) + i + rand());
        float rand_real = low.real() + static_cast<float>(rand()) * static_cast<float>(high.real() - low.real()) / RAND_MAX;
        srand((size_t)time(NULL) + i + rand());
        float rand_imag = low.imag() + static_cast<float>(rand()) * static_cast<float>(high.imag() - low.imag()) / RAND_MAX;
        _data[i] = complex<float>(rand_real, rand_imag);
    }
}

template <>
Vector<int>::Vector(size_t size, int& low, int& high) : _size(size), _capacity(size) {
    _data = new int[_capacity]; // Создаем массив заданной емкости

    std::random_device rd; // Генератор случайных чисел
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(low, high); // Равномерное распределение чисел в заданном диапазоне

    for (size_t i = 0; i < _size; i++) {
        _data[i] = dis(gen); // Заполняем вектор случайными числами
    }
}

template <typename T>
Vector<T>::Vector(size_t size, T& low, T& high) : _size(size), _capacity(size) {
    if (low > high)
        throw std::invalid_argument("High < low");
    _data = new T[size];
    for (size_t i = 0; i < size; ++i) {
        srand((size_t)time(NULL) + rand());
        _data[i] = low + static_cast<T>(rand()) * static_cast<T>(high - low) / RAND_MAX;
    }
}

template<>
complex<double>& Vector<complex<double>>::operator*(const Vector<complex<double>>& Second) {
    complex<double> answer(0, 0);
    for (size_t i = 0; i < _size; ++i) {
        answer += complex<double>(_data[i].real() * Second._data[i].real(), _data[i].imag() * Second._data[i].imag());
    }
    return answer;
}

template<>
complex<float>& Vector<complex<float>>::operator*(const Vector<complex<float>>& Second) {
    complex<float> answer(0, 0);
    for (size_t i = 0; i < _size; ++i) {
        answer += complex<float>(_data[i].real() * Second._data[i].real(), _data[i].imag() * Second._data[i].imag());
    }
    return answer;
}

template <typename T>
T& Vector<T>::operator*(const Vector<T>& Second) {
    T answer = _data[0] * Second._data[0];
    for (size_t i = 1; i < _size; ++i)
        answer += _data[i] * Second._data[i];
    return answer;
}


template <>
Vector<complex<double>>& Vector<complex<double>>::normalize() {
    double magnitude = 0.0;
    for (size_t i = 0; i < _size; ++i) {
        magnitude += norm(_data[i]);
    }
    if (magnitude == 0)
        throw logic_error("Division by zero");
    double magnitude_sqrt = sqrt(magnitude);
    for (size_t i = 0; i < _size; ++i) {
        _data[i] /= magnitude_sqrt;
    }
    return *this;
}

template <>
Vector<complex<float>>& Vector<complex<float>>::normalize() {
    float magnitude = 0.0;
    for (size_t i = 0; i < _size; ++i) {
        magnitude += norm(_data[i]);
    }
    if (magnitude == 0)
        throw logic_error("Division by zero");
    float magnitude_sqrt = sqrt(magnitude);
    for (size_t i = 0; i < _size; ++i) {
        _data[i] /= magnitude_sqrt;
    }
    return *this;
}

template<>
Vector<int>& Vector<int>::normalize() {
    double length = 0;
    for (size_t i = 0; i < _size; ++i) {
        length += pow(_data[i], 2);
    }
    if (length == 0)
        throw logic_error("Division by zero");
    length = ceil(sqrt(length));
    for (size_t i = 0; i < _size; ++i) {
        _data[i] = round(double(_data[i]) / length);
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::normalize() {
    T length = 0;
    for (size_t i = 0; i < _size; ++i) {
        length += pow(_data[i], 2);
    }
    if (length == 0)
        throw logic_error("Division by zero");
    length = sqrt(length);
    for (size_t i = 0; i < _size; ++i) {
        _data[i] /= length;
    }
    return *this;
}


template<typename T>
Vector<T> find_orthogonal(const Vector<T>& Main_vector) {
    Vector<T> Answer(Main_vector);
    size_t i, j, main_size = Main_vector.get_size();
    for (i = 0; i < main_size && Main_vector[i] == 0; ++i);
    for (j = i + 1; j < main_size && Main_vector[j] == 0; ++j);
    if (i == main_size && j == main_size)
        throw std::invalid_argument("vector with one or zero values");
    else {
        if (i == main_size)
            return Answer;
        else if (j == main_size)
            return Answer;
    }
    T pos = Main_vector[j];
    T neg = Main_vector[i];
    for (size_t k = 0; k < main_size; ++k) {
        if (k == i)
            Answer[k] = pos;
        else {
            if (k == j)
                Answer[k] = neg;
            else {
                Answer[k] = 0;
            }
        }
    }
    if (abs(Answer * Main_vector) < Vector<T>::accuracy)
        return Answer;
    else
        throw std::logic_error("The code is incorrect!");
}

template<>
Vector<int> find_orthogonal(const Vector<int>& Main_vector) {
    Vector<int> Answer(Main_vector);
    size_t i, j, main_size = Main_vector.get_size();
    for (i = 0; i < main_size && Main_vector[i] == 0; ++i);
    if (i == main_size)
        throw std::invalid_argument("zero vector");
    for (j = i + 1; j < main_size && Main_vector[j] == 0; ++j);
    if (j == main_size)
        throw std::invalid_argument("zero vector");
    for (size_t k = 0; k < main_size; ++k) {
        if (k == i)
            Answer[i] = -Main_vector[j];
        else {
            if (k == j)
                Answer[j] = Main_vector[i];
            else
                Answer[k] = 0;
        }
    }
    if (Answer * Main_vector == 0)
        return Answer;
    else
        throw std::logic_error("The code is incorrect!");
}


template<>
Vector<complex<double>> find_orthogonal(const Vector<complex<double>>& Main_vector) {
    Vector<complex<double>> Answer(Main_vector);
    size_t i, j, main_size = Main_vector.get_size();
    for (i = 0; i < main_size && Main_vector[i].real() == 0 && Main_vector[i].imag() == 0; ++i);
    for (j = i + 1; j < main_size && Main_vector[j].real() == 0 && Main_vector[j].imag() == 0; ++j);
    if (i == main_size || j == main_size)
        throw std::invalid_argument("vector with one or zero values");
    complex<double> pos, neg;
    double real_pos = Main_vector[j].real(), imag_pos = Main_vector[j].imag();
    double real_neg = Main_vector[i].real(), imag_neg = Main_vector[i].imag();
    if (real_pos == 0 || real_neg == 0) {
        pos = complex<double>(0, imag_pos);
        neg = complex<double>(0, -imag_neg);
    }
    else {
        if (imag_pos == 0 || imag_neg == 0) {
            pos = complex<double>(real_pos, 0);
            neg = complex<double>(-real_neg, 0);
        }
        else {
            pos = complex<double>(real_pos, imag_pos);
            neg = complex<double>(-real_neg, -imag_neg);
        }
    }
    for (size_t k = 0; k < main_size; ++k) {
        if (k == i)
            Answer[k] = pos;
        else {
            if (k == j)
                Answer[k] = neg;
            else {
                Answer[k] = complex<double>(0, 0);
            }
        }
    }
    if (abs(Answer * Main_vector) < Vector<complex<double>>::accuracy)
        return Answer;
    else
        throw std::logic_error("The code is incorrect!");
}

template<>
Vector<complex<float>> find_orthogonal(const Vector<complex<float>>& Main_vector) {
    Vector<complex<float>> Answer(Main_vector);
    size_t i, j, main_size = Main_vector.get_size();
    for (i = 0; i < main_size && Main_vector[i].real() == 0 && Main_vector[i].imag() == 0; ++i);
    for (j = i + 1; j < main_size && Main_vector[j].real() == 0 && Main_vector[j].imag() == 0; ++j);
    if (i == main_size || j == main_size)
        throw std::invalid_argument("vector with one or zero values");
    complex<float> pos, neg;
    float real_pos = Main_vector[j].real(), imag_pos = Main_vector[j].imag();
    float real_neg = Main_vector[i].real(), imag_neg = Main_vector[i].imag();
    if (real_pos == 0 || real_neg == 0) {
        pos = complex<float>(0, imag_pos);
        neg = complex<float>(0, -imag_neg);
    }
    else {
        if (imag_pos == 0 || imag_neg == 0) {
            pos = complex<float>(real_pos, 0);
            neg = complex<float>(-real_neg, 0);
        }
        else {
            pos = complex<float>(real_pos, imag_pos);
            neg = complex<float>(-real_neg, -imag_neg);
        }

    }
    if (abs(Answer * Main_vector) == Vector<complex<float>>::accuracy)
        return Answer;
    else
        throw std::logic_error("The code is incorrect!");
}


template<typename T>
Vector<T> find_normal_orthogonal(const Vector<T>& Main_vector) {
    return find_orthogonal(Main_vector).normalize();
}


//int main() {
//    std::complex<double> z(0.34, 1.3421);
//    std::complex<double> z1(488.234, 0.13940);
//    std::complex<double> z2(0.340000001, 3.2);
//    std::complex<double> z3(0.25, 133.4);
//    Vector<complex<double>> v(1, z);
//    v.push_back(z1);
//    v.push_back(z2);
//    v.push_back(z3);
//    cout << "First vector:" << v << endl;
//    cout << find_orthogonal(v);
//    cin >> v;
//}
