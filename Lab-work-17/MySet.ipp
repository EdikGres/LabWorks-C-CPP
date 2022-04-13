
#include "MySet.h"
#include <algorithm>
#ifdef MYSET_H


template<typename T>
MySet<T>::MySet() : len(0), capacity(10) {
    array = new T[capacity];
}

template<typename T>
MySet<T>::MySet(MySet &set) : len(set.len), capacity(set.capacity) {
    this->array = new T[capacity];
    //memcpy_s(this->array, sizeof(T) * len, set.array, sizeof(T) * len);
    for (int i = 0; i < set.len; ++i) {
        this->array[i] = set.array[i];
    }
}

template<typename T>
MySet<T>::~MySet() {
    delete[] array;
}

template<typename T>
void MySet<T>::insert(const T &value) {
    for (int i = 0; i < len; ++i)
        if (value == array[i])
            return;

    if (len >= capacity) {
        capacity *= 2;
        T *dest = new T[capacity];
        //memcpy_s(dest, sizeof(T) * len, array, sizeof(T) * len);
        for (int i = 0; i < len; ++i) {
            dest[i] = array[i];
        }
        delete[] array;
        array = dest;
    }
    if (len == 0) {
        array[len++] = value;
        return;
    }
    unsigned cur = 0;
    //binary search from algorithm dop task
    T* cur_p = std::lower_bound(array, array+len-1, value);
    cur = cur_p-array;
    for (int i = len; i > cur; --i) {
        array[i] = array[i - 1];
    }
    if (array[cur] > value) {
        array[cur + 1] = array[cur];
        array[cur] = value;
        len++;
        return;
    }
    array[cur + 1] = value;
    len++;
}

template<typename T>
bool MySet<T>::find(const T &value) {
    for (int i = 0; i < len; ++i) {
        if (value == array[i])
            return true;
    }
    return false;
}

template<typename T>
unsigned MySet<T>::size() {
    return len;
}

template<typename T>
MySet<T> &MySet<T>::set_union(const MySet &s) {
    if (s.len == 0 || this->len == 0)
        throw "Exception: union is empty!";
    for (int i = 0; i < s.len; ++i) {
        insert(s.array[i]);
    }
    return *this;
}

template<typename T>
void MySet<T>::show() {
    if (len == 0) {
        std::cout << "set is empty!" << std::endl;
        return;
    }
    for (int i = 0; i < len; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void MySet<T>::erase() {
    this->len = 0;
    this->capacity = 10;
    delete[] this->array;
    this->array = new T[capacity];
}

template<typename T1>
std::ostream &operator<<(std::ostream &out, const MySet<T1> &set) {
    for (int i = 0; i < set.len; ++i) {
        std::cout << set.array[i] << " ";
    }
    return out;
}

template<typename T>
MySet<T> &MySet<T>::operator=(const MySet<T> &set) {
    if (this == &set)
        return *this;
    this->len = set.len;
    this->capacity = set.capacity;
    this->array = new T[capacity];
    for (int i = 0; i < set.len; ++i) {
        this->array[i] = set.array[i];
    }
    return *this;
}

template<typename T>
T &MySet<T>::operator[](int i) {
    if(i >=len)
        throw "out of bounds of an array";
    return array[i];
}


#endif // MYSET_H