//
// Created by utec on 27/08/19.
//

#ifndef MYVECTOR_MYVECTOR_H
#define MYVECTOR_MYVECTOR_H

namespace UTEC {
    class MyVector {
    private:
        int *data;
        int nelem;
    public:
        MyVector();

        MyVector(int);

        virtual ~MyVector();

        int size();

        void push_back(int);

        void insert(int, int);

        void pop_back();

        void erase(int);

        void print();

        int operator[](int);

       /* void Exception(int );

        void Exception2();

        void Exception3();
       */
        MyVector operator+(MyVector v2);

    };

}
#endif //MYVECTOR_MYVECTOR_H
