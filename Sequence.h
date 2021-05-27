#pragma once
#include <iostream>
using namespace std;

template <class T> class Sequence{
public:
    virtual T getFirst() = 0; //arr
    virtual T getLast() = 0;
    virtual bool isEmpty() = 0; //arr
    virtual void overFlow() = 0; //arr
    virtual void empty() = 0; //arr
    virtual T getIndex(int index) = 0; //arr 
    virtual int getlen() = 0; //arr
    virtual void push_back(T item) = 0; //arr
    virtual void push_front(T item) = 0; //arr
    virtual void deleteAt(int) = 0; //arr
    virtual void insertAt(T item, int index) = 0;
    virtual void deleteLast() = 0;
    virtual void deleteFirst() = 0;
    /*virtual void map() = 0; 
    virtual void where() = 0;*/
    //virtual void sort() = 0;
    virtual void print() = 0;
};

