#include "Sequence.h"
#include "ArraySequence.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cout << "Hello LABS!\n";
	ArraySequence<int>* Q = new ArraySequence<int>();
    Q->push_front(2);
    Q->push_front(0);
    Q->push_back(4);
    Q->push_back(6);
    Q->push_back(8);
    Q->push_back(10);
    Q->print();

    ArraySequence<int>* M = new ArraySequence<int>();
    M = Q->getSubSequence(3, 5);
    M->print();
    cout << M->getSize();
	return 0;
}