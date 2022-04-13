//
// Created by atlon on 13.09.2021.
//

#ifndef MYSET_H
#define MYSET_H

template<typename T>
class MySet {
private:
    unsigned len;
    unsigned capacity;
    T *array;
public:
    MySet();

    MySet(MySet &set);

    ~MySet();

    void insert(const T &value);

    bool find(const T &value);

    unsigned size();

    MySet<T> &set_union(const MySet &s);

    void show();

    void erase();

    template<typename T1>
    friend std::ostream &operator<<(std::ostream &, const MySet<T1> &);

    MySet &operator=(const MySet<T> &set);

    T& operator[](int i);
};

#include "MySet.ipp"

#endif //MYSET_H
