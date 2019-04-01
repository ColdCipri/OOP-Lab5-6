#pragma once
#include "Tutorial.h"

template <typename TElement>


class DynamicVector
{
private:
	TElement * elems;
	int size;
	int capacity;

	void resize(double factor = 2);

public:
	DynamicVector(int capacity = 10);
	/*
	Creates a dynamic array of generic elements, with a given capacity.
	input: capacity - int (maximum capacity for the dynamic array)
	*/

	DynamicVector(const DynamicVector& arr);
	/*makes a copy of the dyn. array*/

	~DynamicVector();
	/*Destroys the dynamic array.*/

	DynamicVector& operator = (const DynamicVector& arr);
	/* equal operator*/

	void add(const TElement& e);
	/*
	Adds a generic to the dynamic array.
	input: e - TElement& (The movie to be added)
	*/

	void remove(int pos);
	/*
	Deletes a generic at a given position from the dynamic array.
	input: pos - int
	*/

	void update(int pos, const TElement e);
	/*
	Updates a generic at a given position with a given element, from the dynamic array.
	input:  pos - int
	e - TElement&
	*/

	TElement* getAllElems() const;
	/*
	Returns the elements of the dynamic array.
	output: the elements (this->elems)
	*/

	int getSize() const;
	/*
	Returns the length of the dynamic array.
	output: this->size (the length of the array)
	*/

	DynamicVector& operator-(const TElement& e);

	DynamicVector& operator+(const TElement & e);

};

template <typename TElement>
DynamicVector <TElement>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

template <typename TElement>
DynamicVector<TElement>::DynamicVector(const DynamicVector<TElement>& arr)
{
	this->size = arr.size;
	this->capacity = arr.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = arr.elems[i];
}

template <typename TElement>
DynamicVector<TElement>::~DynamicVector()
{
	delete[] this->elems;
}

template <typename TElement>
DynamicVector<TElement>& DynamicVector<TElement>:: operator=(const DynamicVector& arr)
{
	if (this == &arr)
		return *this;
	this->size = arr.size;
	this->capacity = arr.capacity;
	delete[] this->elems;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = arr.elems[i];
	return *this;
}

template <typename TElement>
void DynamicVector <TElement>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);
	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];
	delete[] this->elems;
	this->elems = els;
}

template <typename TElement>
void DynamicVector<TElement>::add(const TElement& e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template <typename TElement>
void DynamicVector <TElement>::remove(int pos)
{
	if (pos < 0 || pos >= this->size)
		return;
	for (int i = pos; i < this->size - 1; i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;
}

template <typename TElement>
void DynamicVector <TElement>::update(int pos, const TElement e)
{
	if (pos < 0 || pos >= this->size)
		return;
	this->elems[pos] = e;
}

template <typename TElement>
TElement* DynamicVector <TElement>::getAllElems() const
{
	return this->elems;
}

template <typename TElement>
int DynamicVector <TElement>::getSize() const
{
	return this->size;
}

template <typename TElement>
DynamicVector<TElement>& DynamicVector<TElement>:: operator-(const TElement& e)
{
	for (int i = 0; i < this->size; i++)
	{
		TElement e2 = this->elems[i];
		if (e2 == e)
			this->remove(i);
	}
	return *this;
}

template <typename TElement>
DynamicVector<TElement>& DynamicVector<TElement>:: operator+(const TElement& e)
{
	this->add(e);
	return *this;
}