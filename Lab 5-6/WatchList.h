#pragma once
#include "DynamicVector.h"
class WatchList
{
private:
	DynamicVector<Tutorial> tutorials;
	int current;
public:
	WatchList();
	void add(const Tutorial& tutorial);
	Tutorial getCurrentTutorial();
	void play();
	void next();
	void remove(const Tutorial& tutorial);
	bool isEmpty();
	DynamicVector<Tutorial> getTutorials() { return tutorials; };
};

