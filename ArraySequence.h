#pragma once
#include <iostream>
#include "Sequence.h"
using namespace std;

template <class T> class ArraySequence : public Sequence<T> {
private:
	T* data;
	int size;
	int capacity=8;
public:
	ArraySequence() {
		data = new T[capacity];
		size = 0;
	}

	ArraySequence(const ArraySequence<T>& src) : size(src.size), capacity(src.capacity){
		this->data = new T[size];
		copy(array.data, array.data + size, data);
	}

	ArraySequence(ArraySequence&& src) : data(src.data), size(src.size), capacity(src.capacity){
		src.data = nullptr;
		src.size = src.capacity = 0;
	}

	~ArraySequence(){
		delete[] data;
	}

	void setSize(int size) {
		this->size = size;
	}

	void setCapacity(int capacity) {
		this->capacity = capacity;
	}

	void setData(T* data) {
		this->data = data;
	}

	int getSize() {
		return size;
	}

	int getCapacity() {
		return capacity;
	}

	T* getData() {
		return data;
	}
	bool isEmpty() override {
		if (size == 0) {
			return true;
		}
		else
			return false;
	}

	void overFlow() override {
		cout << "Over flow!\n";
	}
	void empty() override {
		cout << "Sequence is empty!\n";
	}

	T getFirst() override {
		if (isEmpty()) {
			empty();
			return 0;
		}
		else {
			return data[0];
		}
	}

	T getLast() override {
		if (isEmpty()) {
			empty();
			return 0;
		}
		else {
			return data[size - 1];
		}
	}

	T getIndex(int index) override{
		if (IndexisValid(index)) {
			if (isEmpty()) {
				empty();
				return 0;
			}
			else {
				return data[index];
			}
		}
		else {
			cout << "Input index is invalid!";
			return 0;
		}
	}

	int getlen() override {
		return size;
	}

	void push_back(T item) override{
		if (size == capacity) {
			int new_cap = capacity * 2;
			T* new_arr = new T[new_cap];
			for (int i = 0; i < size; i++) {
				new_arr[i] = data[i];
			}
			delete[] data;
			data = new_arr;
			capacity = new_cap;
		}
		data[size] = item;
		size++;
	}

	void push_front(T item) override {
		if (size == capacity) {
			capacity *= 2;
		}
		T* new_arr = new T[capacity];
		for (int i = 0; i < size; i++) {
			new_arr[i + 1] = data[i];
		}
		delete[] data;
		data = new_arr;
		data[0] = item;
		size++;
	}

	void deleteAt(int index) override{
		if (IndexisValid(index)) {
			for (int i = index; i < size; i++) {
				data[i] = data[i + 1];
			}
			size--;
		}
		else
			cout << "Input index undefined!";
	}

	void insertAt(int index, T item) override {
		if (IndexisValid(index)) {
			if (size == capacity) {
				capacity *= 2;
			}
			T* new_arr = new T[capacity];
			copy(data, data + index, new_arr);
			for (int i = index; i < size; i++) {
				new_arr[i + 1] = data[i];
			}
			delete[] data;
			data = new_arr;
			data[index] = item;
			size++;
		}
		else
			cout << "Input index undefined !";
	}

	void deleteLast() override {
		if (isEmpty()) {
			cout << "Cannot delete any more!";
		}
		else {
			size--;
		}
	}
	
	void deleteFirst() override{
		if (isEmpty())
			cout << "Cannot delete any more!";
		else {
			int* new_arr = new int[capacity];
			copy(data + 1, data + size, new_arr);
			delete[] data;
			data = new_arr;
			size--;
		}
	}

	void concate(ArraySequence<T>* arr) {
		int arr_size = arr->getSize();
		int arr_capacity = arr->getCapacity();
		T* arr_data = arr->getData();
		while (arr_size + size >= capacity) {
			capacity *= 2;
		}
		T* new_arr = new T[capacity];
		copy(data, data + size, new_arr);
		copy(arr_data, arr_data + arr_size, new_arr + size);
		delete[] data;
		data = new_arr;
		size = size + arr_size;
	}

	bool IndexisValid(int index) {
		if (index < size && index >= 0)
			return true;
		else
			return false;
	}
	ArraySequence<T>* getSubSequence(int startId, int endId) {
		if (IndexisValid(startId) && IndexisValid(endId) && startId <= endId) {
			ArraySequence<T>* arr = new ArraySequence<T>();
			int arr_capacity = arr->getCapacity();
			int arr_size = 0;
			while (arr_capacity <= size) {
				arr_capacity *= 2;
			}
			arr->setCapacity(arr_capacity);
			for (int i = startId; i <= endId; i++) {
				arr->push_back(data[i]);
				arr_size++;
			}
			arr->setSize(arr_size);
			return arr;
		}
		else {
			cout << "Input indexes are invalid!";
			return nullptr;
		}
	}

	void print() override
	{
		if (isEmpty()) {
			empty();
		}
		else {
			for (int i = 0; i < size; i++) {
				cout << "| " << data[i] << " ";
			}
			cout << endl;
		}

	}
};

