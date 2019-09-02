//
// Created by utec on 27/08/19.
//


#include <iostream>
#include <stdexcept>
#include "MyVector.h"

using namespace std;

namespace UTEC {

    MyVector::MyVector() : data{nullptr}, nelem{0} {

    }

    MyVector::MyVector(int n) : nelem{n} {
        /*try{
            Exception2();
        }
        catch( const std::exception& e){
            std::cout<<e.what();
            return;
        }
        */
        if (n < 0) throw logic_error("Negative size");

        data = new int[nelem];
    }

    MyVector::~MyVector() {
        delete[] data;
    }

    int MyVector::size() {
        return nelem;
    }

    void MyVector::push_back(int value) {
        // 1. Crear temporal
        int *temp = new int[nelem + 1];

        // 2. Transferir los datos a temp
        for (int i = 0; i < nelem; ++i)
            temp[i] = data[i];

        // 3. Borrar memoria anterior
        delete[] data;

        // 4. Apuntando a memoria actual
        data = temp;

        // 5. Actualizando valor
        data[nelem] = value;

        // 6. Actualizando valor
        nelem++;
    }

    void MyVector::insert(int position, int value) {

        /*  try{
            Exception(position);
        }
        catch( const std::exception& e){
            std::cout<<e.what();
            return;
        } */


        if (position >= nelem || position < 0)
            throw std::out_of_range("Fuera de limite");


        int *temp = new int[++nelem];
        for (int i = 0; i < nelem; ++i) {
            if (i > position) temp[i] = data[i - 1];
            else if (i < position) temp[i] = data[i];
        }

        temp[position] = value;

        delete[] data;
        data = temp;

    }

    void MyVector::pop_back() {

        /*try{
          Exception3();
      }
      catch( const std::exception& e){
          std::cout<<e.what();
          return;
      }
       */

        if (nelem == 0) throw logic_error("Vector vacio");


        int *temp = new int[--nelem];

        for (int i = 0; i < nelem; ++i)
            temp[i] = data[i];

        delete[] data;

        data = temp;

    }


    void MyVector::erase(int position) {

        /*
        try{
            Exception(position);
            Exception3();
        }
        catch( const std::exception& e){
            std::cout<<e.what();
            return;
        }
        */


        if (nelem == 0) throw logic_error("Vector vacio");
        else if (position >= nelem || position < 0) throw std::out_of_range("Fuera de limite");


        int *temp = new int[nelem - 1];

        for (int i = 0; i < nelem; ++i) {
            if (i < position) temp[i] = data[i];
            else if (i > position) temp[i - 1] = data[i];
        }

        delete[] data;

        data = temp;
        --nelem;

    }

    MyVector MyVector::operator+(MyVector v2) {
        int n = 0, l;
        for (int i = 0; i < nelem; ++i)
            for (int j = 0; j < v2.size(); ++j)
                if (data[i] == v2[j]) {
                    n++;
                    break;
                }

        MyVector temp(nelem + v2.size() - n);

        for (int i = 0; i < nelem; i++) temp.data[i] = data[i];
        n = 0;
        for (int i = 0; i < v2.size(); ++i) {
            l = 1;
            for (int j = 0; j < nelem; ++j)
                if (v2[i] == data[j]) {
                    l = 0;
                    break;
                }
            if (l) {
                temp.data[nelem + n] = v2[i];
                n++;
            }
        }

        return temp;
    }


    int MyVector::operator[](int index) {
        if (index < 0 or index > nelem) throw std::out_of_range("Fuera de limite");
        return data[index];
    }


    void MyVector::print() {

        for (int i = 0; i < nelem; i++) printf("%d ", data[i]);
        printf("\n");
    }
}

 /*   void MyVector::Exception(int pos) {
        if (pos>=nelem|| pos<0)
            throw logic_error("Fuera de limite\n");
    }

    void MyVector::Exception2() {
        if(nelem<0) throw logic_error("Negative size");
    }

    void MyVector::Exception3() {
        if(nelem==0) throw logic_error("Vector vacío");
    }
}
  */