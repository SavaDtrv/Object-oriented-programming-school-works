#pragma once
#include <iostream>
using namespace std;

class DynamicArray
{
	int* elements;
	int size;
	int capacity;
	
	void copy(const DynamicArray& other);

	void resize();
	
	void add(int elem);
	
	void erase();
	
	
public:
	DynamicArray();
	DynamicArray(const DynamicArray& other);
	DynamicArray& operator=(const DynamicArray& other);
	~DynamicArray();

	DynamicArray(int* _elements, int _size);

	void print();
	int getSize() const;
	bool isEmpty();
	int getIndex(int index);
	void setValue(int index, int newValue);
	void push(int element);
	void pop();
	void insertAt(int index, int element);
	int removeAt(int index);
	int operator[](int newindex); 
	
	DynamicArray& operator+=(const DynamicArray& other);
	DynamicArray operator+ (const DynamicArray& other);
	DynamicArray& operator-=(const DynamicArray& other);
	DynamicArray operator-(const DynamicArray& other);


};
