#include "WatchList.h"
#include <iostream>

WatchList::WatchList()
{
	this->current = 0;
}

void WatchList::add(const Tutorial& tutorial)
{
	this->tutorials.add(tutorial);
}
Tutorial WatchList::getCurrentTutorial()
{
	if (this->current == this->tutorials.getSize())
		this->current = 0;
	Tutorial* elems = this->tutorials.getAllElems();
	if (elems != NULL)
		return elems[this->current];
}
void WatchList::play()
{
	if (this->tutorials.getSize() >= 0)
	{
		this->current = 0;
		Tutorial currentTutorial = this->getCurrentTutorial();
		currentTutorial.accessLink();
	}
}
void WatchList::next()
{
	if (this->tutorials.getSize() >= 0)
	{
		this->current++;
		Tutorial currentTutorial = this->getCurrentTutorial();
		currentTutorial.accessLink();
	}
}
void WatchList::remove(const Tutorial& tutorial)
{
	Tutorial* elems = this->tutorials.getAllElems();
	int i = 0;
	bool da = 0;
	while (i < this->tutorials.getSize() && da==0)
	{
		if (elems[i] == tutorial)
			da = 1;
		i++;
	}
	i--;
	this->tutorials.remove(i);
	if(isEmpty())
		this->current=0;
}
bool WatchList::isEmpty()
{
	return this->tutorials.getSize() == 0;
}
