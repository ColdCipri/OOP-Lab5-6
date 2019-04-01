#pragma once
#include "Tutorial.h"
#include "DynamicVector.h"
#include "stdio.h"
template <typename T>
class Comparator
{
public:
	virtual bool compare(const T& e1, const T& e2) const = 0;
};
class ComparatorAscendingByTitle : public Comparator <Tutorial>
{
public:
	bool compare(const Tutorial& t1, const Tutorial&t2) const override { return t1.getTitle() < t2.getTitle(); }
};
class ComparatorDescendingByPresenter : public Comparator <Tutorial>
{
public:
	bool compare(const Tutorial& t1, const Tutorial& t2) const override { return t1.getPresenter() > t2.getPresenter(); }
};
template <typename T>
DynamicVector <T> sortFunction(DynamicVector<T> vect, Comparator<T>& comp)
{
	DynamicVector<T> res = vect;
	T aux;
	for (int i = 0; i < res.getSize() - 1; i++)
		for (int j = i + 1; j < res.getSize(); j++)
		{
			if (comp.compare(res.getAllElems()[i], res.getAllElems()[j]) == 0)
			{
				aux = res.getAllElems()[i];
				res.getAllElems()[i] = res.getAllElems()[j];
				res.getAllElems()[j] = aux;
			}
		}
	return res;
}
