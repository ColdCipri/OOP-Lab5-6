#pragma once
#include "Tutorial.h"
#include "DynamicVector.h"
class Repository
{
private:
	DynamicVector<Tutorial> tutorials;
public:
	Repository() {}
	void addTutorial(const Tutorial& t);
	bool removeTutorial(const Tutorial& t);
	bool updateTutorial(Tutorial& t, const Tutorial& t1);
	Tutorial findTutorialByTitle(const std::string& title);
	DynamicVector<Tutorial> getTutorials() const { return tutorials; }
};

