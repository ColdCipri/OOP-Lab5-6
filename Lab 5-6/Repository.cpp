#include "Repository.h"


void Repository::addTutorial(const Tutorial& t)
{
	//this->tutorials.add(t);
	this->tutorials = this->tutorials + t;
}
bool Repository::removeTutorial(const Tutorial& t)
{
	Tutorial* elems = this->tutorials.getAllElems();
	for (int i = 0; i < this->tutorials.getSize(); i++)
		if (t.getTitle() == elems[i].getTitle())
		{
			//tutorials.remove(i);
			this->tutorials=this->tutorials-t;
			return true;
		}
	return false;
	
}
bool Repository::updateTutorial(Tutorial& t, const Tutorial& t1)
{
	Tutorial* elems = this->tutorials.getAllElems();
	for (int i = 0; i < this->tutorials.getSize(); i++)
		if (t.getTitle() == elems[i].getTitle())
		{
			tutorials.update(i, t1);
			return true;
		}
	
	return false;
}
Tutorial Repository::findTutorialByTitle(const std::string& title)
{
	Tutorial* elems = this->tutorials.getAllElems();
	
	for (int i = 0; i < this->tutorials.getSize(); i++)
		if (title == elems[i].getTitle())
			return elems[i];
	return Tutorial{};
	
}
