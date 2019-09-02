#include <iostream>
#include <cassert>
#include "MyVector.h"

using namespace UTEC;

int main() {

    MyVector v1;
    assert(v1.size() == 0);
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    assert(v1.size() == 3);
    MyVector v2;
    v2.push_back(40);
    v2.push_back(50);
    assert(v2.size()==2);

    MyVector v3 = v1+v2;
    v3.print();

    assert(v3.size()==5);

    v3.pop_back();
    v3.print();
    assert(v3.size()==4);

    v3.erase(2);
    v3.print();
    assert(v3.size()==3);

    int total = 0;
    for (int i = 0; i < v1.size(); ++i)
        total += v1[i];
    assert(total == 60);

    std::string resultado;
    try {
       v3.insert(10,10);
    } catch ( const std::exception& e) {
        resultado=e.what();
    }
    assert(resultado == "Fuera de limite");


    std::string resultado1, resultado2, resultado3, resultado4, resultado5;


    try {
        v3.erase(8);
    } catch ( const std::exception& e) {
        resultado1 = e.what();
    }
        assert(resultado1 == "Fuera de limite");


    try {
        v3[5];
    } catch ( const std::exception& e) {
        resultado2=e.what();
    }
    assert(resultado2 == "Fuera de limite");


    try {
        MyVector v4(-5);
    } catch ( const std::exception& e) {
        resultado3=e.what();
    }
    assert(resultado3 == "Negative size");

    MyVector v5;


    try {
        v5.erase(3);
    } catch ( const std::exception& e) {
        resultado4=e.what();
    }
    assert(resultado4 == "Vector vacio");



    try {
        v5.pop_back();
    } catch ( const std::exception& e) {
        resultado5=e.what();
    }
    assert(resultado5 == "Vector vacio");



    return 0;
}