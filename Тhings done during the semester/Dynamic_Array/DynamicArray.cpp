#include "DynamicArray.h"

int const INITIAL_SIZE = 0;
int const INITIAL_CAPACITY = 8;

void DynamicArray::copy(const DynamicArray & other)
{
	size = other.size;
	capacity = other.capacity;
	for (int i = 0; i < size; i++)	
	{
		elements[i] = other.elements[i];
	}
}

void DynamicArray::resize()
{
	capacity *= 2;
	int* elements2 = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		elements2[i] = elements[i];
	}
	erase(); 
	elements = elements2; 
}

void DynamicArray::add(int elem)
{
	if (size == capacity - 1) 
	{
		resize();
	}
	size++;
	elements[size] = elem;
}

void DynamicArray::erase()
{
	delete[] elements;
	elements = nullptr;
}

DynamicArray::DynamicArray()
{
	size = INITIAL_SIZE;
	capacity = INITIAL_CAPACITY;
	elements = new int[capacity]; 

}

DynamicArray::DynamicArray(const DynamicArray & other)
{
	copy(other);
		
}

DynamicArray & DynamicArray::operator=(const DynamicArray & other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}

	return *this;

}

DynamicArray::~DynamicArray()
{
	erase();
}

DynamicArray::DynamicArray(int * _elements, int _size)
{
	size = _size;
	capacity = size;
	elements = new int[size];
	for (int i = 0; i < size; i++)
	{
		elements[i] = _elements[i];
	}

}

void DynamicArray::print()
{
	cout << "[";
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1) 
		{
			cout << elements[i];
		}
		else cout << elements[i] << ",";
	}
	cout << "]" <<  endl;
}

int DynamicArray::getSize() const  
{
	return size;
}

bool DynamicArray::isEmpty()
{
	if (size == INITIAL_SIZE)
	{
		return true;
	}
	else return false;
}

int DynamicArray::getIndex(int index)
{
	return elements[index];

}

void DynamicArray::setValue(int index, int newValue)
{
	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			elements[i] = newValue;
		}
	}
}

void DynamicArray::push(int element)
{
	add(element);

}

void DynamicArray::pop()
{
	cout << elements[size] << '\n';
	size--;
}

void DynamicArray::insertAt(int index, int element)
{
	if (size == capacity)
	{
		resize();
	}
	
	for (int i = size; i > index; i--)
	{
		elements[i] = elements[i - 1];
    }
	size++;
	elements[index] = element;

}

int DynamicArray::removeAt(int index)
{
	int temporary = elements[index];
	for (int i = index; i < size; i++)
	{
		elements[i] = elements[i + 1];
	}
	size--;
	return temporary;
}

int DynamicArray::operator[](int newindex)
{
	return elements[newindex];
}

DynamicArray & DynamicArray::operator+=(const DynamicArray & other)
{
	
	for (int i = 0; i < other.size; ++i) { 
		push(other.elements[i]); 
	} 
	
	return *this;
}

DynamicArray DynamicArray::operator+(const DynamicArray & other) 
{
	DynamicArray result = *this;  
	return result += other; 
	
}

DynamicArray & DynamicArray::operator-=(const DynamicArray & other)
{
	for (int i = 0; i < other.size; ++i)
	{
		if (elements[i] == other.elements[i]) { removeAt(i); }
		
	}
	return *this;
	
}

DynamicArray DynamicArray::operator-(const DynamicArray & other)
{
	DynamicArray result1 = *this;

	for (int i = 0; i < other.size; i++)
	{
		if (elements[i] == other.elements[i]) { removeAt(i); }
		
	}
	return result1;

}



