#include <iostream>
#include <cmath>
#include "MySet.h"
#include "Point.h"

//option 21-11=10
/*
 * Не забыть перегрузить присваивание и создать конструктор копий +
 * 10. Сделать реализацию множества set (на основе массива с сортировкой) для хранения только уникальных элементов.
    -insert(const T& value) +
    -bool find(const T& value) +
    -size() возвращает количество элементов в множестве +
    -set union(const set& s) --- объединение (бросает исключение при объединении с пустым множеством) +
    -operator<< для вывода +
 */



using namespace std;

int main() {
    //Test Points
    cout << "-----Tests Point-----" << endl;
    cout << "--Test insert(), size(), union(), operator <<, >,< and etc.:" << endl;
    Point p1{3, 3, 3}, p2{1, 2, 3}, p3{0, 0, 1};
    MySet<Point> *setP = new MySet<Point>;
    setP->insert(p1);
    setP->insert(p2);
    setP->insert(p3);
    cout << "SetP: " << *setP << " Size: " << setP->size()
         << endl; //we see: 1.In ascending order vectors 2. Overloaded operators work
    MySet<Point> *setP2 = new MySet<Point>;
    Point p4{9, 8, 1}, p5{13, 9, 4};
    setP2->insert(p4);
    setP2->insert(p5);
    setP2->insert(p1);
    cout << "SetP2 before union: " << *setP2 << " Size: " << setP2->size() << endl;
    setP2->set_union(*setP);
    cout << "SetP2 after union with SetP: " << *setP2
         << endl; // we see: 1.In ascending order vectors 2. Unique values (3,3,3) Meets 1 time
    cout << "SetP size: " << setP->size() << " SetP2 size after union: " << setP2->size() << endl;
    cout << "--Test find():" << endl;
    cout << "find(1,2,3) in SetP : " << (setP->find(p2) ? "true" : "false") << endl;
    cout << "find(9,8,1) in SetP : " << (setP->find(p4) ? "true" : "false") << endl;
    cout << "--Test assignment operator and copy constructor: " << endl;
    *setP2 = *setP;
    MySet<Point> *setP3 = new MySet<Point>(*setP);
    cout << "SetP: " << *setP << " Size: " << setP->size() << endl;
    cout << "SetP2: " << *setP2 << " Size: " << setP2->size() << endl;
    cout << "SetP3: " << *setP3 << " Size: " << setP3->size() << endl;
    setP2->insert(p4);
    setP3->insert(p5);
    cout << "After inserts in SetP2, SetP3 from SetP" << endl;
    cout << "SetP: " << *setP << " Size: " << setP->size() << endl;
    cout << "SetP2: " << *setP2 << " Size: " << setP2->size() << endl;
    cout << "SetP3: " << *setP3 << " Size: " << setP3->size() << endl;
    // assignment operator and copy constructor work!
    cout << "-----Tests Point End-----" << endl << endl;
    //Test double
    cout << "-----Tests Double-----" << endl;
    cout << "--Test insert(), size(), union(), operator <<, >,< and etc.:" << endl;
    double d1 = 14.12, d2 = 15.0666, d3 = -1.551, d4 = .0, d5 = .256, d6 = 99.11;
    MySet<double> *setD = new MySet<double>;
    setD->insert(d1);
    setD->insert(d2);
    setD->insert(d3);
    cout << "SetD: " << *setD << " Size: " << setD->size()
         << endl; //we see: 1.In ascending order 2. Overloaded operators work
    MySet<double> *setD2 = new MySet<double>;
    setD2->insert(d4);
    setD2->insert(d5);
    setD2->insert(d1);
    cout << "SetD2 before union: " << *setD2 << " Size: " << setD2->size() << endl;
    setD2->set_union(*setD);
    cout << "SetD2 after union with SetD: " << *setD2
         << endl; // we see: 1.In ascending order 2. Unique values 14.12 Meets 1 time
    cout << "SetD size: " << setD->size() << " SetD2 size after union: " << setD2->size() << endl;
    cout << "--Test find():" << endl;
    cout << "find 14.12 in SetD : " << (setD->find(d1) ? "true" : "false") << endl;
    cout << "find 99.11 in SetD : " << (setD->find(d6) ? "true" : "false") << endl;
    cout << "--Test assignment operator and copy constructor: " << endl;
    *setD2 = *setD;
    MySet<double> *setD3 = new MySet<double>(*setD);
    cout << "SetD: " << *setD << " Size: " << setD->size() << endl;
    cout << "SetD2: " << *setD2 << " Size: " << setD2->size() << endl;
    cout << "SetD3: " << *setD3 << " Size: " << setD3->size() << endl;
    setD2->insert(-88.89);
    setD3->insert(0.131313);
    cout << "After inserts in SetD2, SetD3 from SetD" << endl;
    cout << "SetD: " << *setD << " Size: " << setD->size() << endl;
    cout << "SetD2: " << *setD2 << " Size: " << setD2->size() << endl;
    cout << "SetD3: " << *setD3 << " Size: " << setD3->size() << endl;
    // assignment operator and copy constructor work!
    cout << "-----Tests Double End-----" << endl << endl;
    cout << "-----Tests Exceptions-----" << endl;
    setP->erase();
    setD->erase();
    try {
        setP->set_union(*setP2);
    }
    catch (const char *msg) {
        cout << msg << endl;
    }
    try {
        setD->set_union(*setD2);
    }
    catch (const char *msg) {
        cout << msg << endl;
    }
    try {
        setP2->set_union(*setP3);
        cout << "all work!" << endl;
    }
    catch (const char *msg) {
        cout << msg << endl;
    }
    cout << "-----Tests Exceptions End-----" << endl << endl;
    cout << "----- That's all =) -----" << endl << endl;
    return 0;
}
