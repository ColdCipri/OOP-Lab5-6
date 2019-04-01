#include "Tests.h"
#include "Tutorial.h"
#include <assert.h>
#include "DynamicVector.h"
#include "Repository.h"
#include "Controller.h"
#include "WatchList.h"
#include "Comparator.h"
#include <stdio.h>
void Tests::testTutorial()
{
	Duration d{ 4, 54 };
	Tutorial t {  "C++ Tutorial","Dorel Moga",d,1,"https://www.exemplu.com" };
	assert(t.getTitle() == "C++ Tutorial");
	assert(t.getPresenter() == "Dorel Moga");
	assert(t.getLink() == "https://www.exemplu.com");
	assert(t.getLikes() == 1);
	assert(t.getDuration().getMinutes() == 4);
	assert(t.getDuration().getSeconds() == 54);
	assert(t.accessLink() == true);
	Tutorial t2{ "C++ Tutorial1","Dorel Moga",d,1,"https://www.exemplu.com" };
	assert(t == t2 == false);
}
void Tests::testWatchList()
{
	DynamicVector<Tutorial> v;
	Duration d{ 4, 54 };
	WatchList w;
	assert(w.getCurrentTutorial() == Tutorial{});
	Tutorial t{ "C++ Tutorial","Dorel Moga",d,1,"https://www.exemplu.com" };
	
	w.add(t);
	assert(w.getCurrentTutorial() == t);
	Tutorial t2{ "C++ Tutorial2","Dorel Moga",d,1,"https://www.exemplu.com2" };
	w.add(t2);
	w.next();
	assert(w.getCurrentTutorial() == t2);
	w.play();
	assert(w.getCurrentTutorial() == t);
	assert(w.getTutorials().getSize() == 2);

}

void Tests::testDynamicVector()
{
	DynamicVector<Tutorial> v;
	Duration d{ 4, 54 };
	Tutorial m{ "C++ Tutorial","Dorel Moga",d,1,"https://www.exemplu.com" };
	

	assert(v.getSize() == 0);

	v.add(m);
	assert(v.getSize() == 1);
	DynamicVector<Tutorial> v2(v);
	assert(v2.getSize() == 1);

	DynamicVector<Tutorial> v3;
	v3 = v;
	assert(v.getSize() == 1);

	Tutorial m1{ "C++ Tutorial","Dorel Moga",d,1,"https://www.exemplu.com" };
	v.update(0, m1);
	v.update(-1, m1);
	assert(v.getAllElems()[0].getTitle() == "C++ Tutorial");

	v.remove(0);
	v.remove(-2);
	assert(v.getSize() == 0);
	v - m;
	assert(v.getSize() == 0);

	v.add(m);
	v.add(m);
	v.add(m);
	v.add(m);
	v.add(m);
	v.add(m);
	v.add(m);
	v.add(m);
	v.add(m);
	v.add(m);
	v.add(m);
}

void Tests::testRepository()
{
	Repository repo{};
	assert(repo.findTutorialByTitle("C++ Tutorial") == Tutorial{});
	Duration d{ 4, 54 };
	Tutorial t{ "C++ Tutorial","Dorel Moga",d,1,"https://www.exemplu.com" };
	repo.addTutorial(t);
	assert(repo.findTutorialByTitle("C++ Tutorial").getTitle() == "C++ Tutorial");
	assert(repo.findTutorialByTitle("asd").getTitle() == "");

	Tutorial t1{ "C++ Tutorial1","Dorel Moga",d,1,"https://www.exemplu.com" };
	repo.updateTutorial(t, t1);
	assert(repo.findTutorialByTitle("C++ Tutorial1").getTitle() == "C++ Tutorial1");
	repo.updateTutorial(t, t1);

	repo.removeTutorial(t);
	assert(repo.findTutorialByTitle("C++ Tutorial").getTitle() == "");
	assert(repo.getTutorials().getSize()==1);

}
void Tests::testComparator()
{
	Duration d{ 4, 54 };
	ComparatorAscendingByTitle comp;
	Repository repo{};
	Controller c{ repo };
	Tutorial t{ "C++ Tutorial2","Dorel Moga",d,1,"https://www.exemplu.com" };
	Tutorial t2{ "C++ Tutorial1","Dorel Moga",d,1,"https://www.exemplu.com" };
	DynamicVector<Tutorial> vect;

	repo.addTutorial(t);
	repo.addTutorial(t2);
	vect = sortFunction(repo.getTutorials(), comp);
	assert(vect.getSize() == 2);
	assert(vect.getAllElems()[1].getTitle() == "C++ Tutorial2");
}
void Tests::testController()
{
	Repository repo{};
	Controller c{repo};
	assert(c.add("C++ Tutorial", "Dorel Moga", 4,5, 1, "https://www.exemplu.com") == true);
	assert(c.add("C++ Tutorial", "Dorel Moga", 4, 5, 1, "https://www.exemplu.com") == false);
	assert(c.getRepo().findTutorialByTitle("C++ Tutorial").getTitle() == "C++ Tutorial");
	assert(c.update("C++ Tutorial","C++ Tutorial1", "Dorel Moga", 4, 5, 1, "https://www.exemplu.com") == true);
	assert(c.getRepo().findTutorialByTitle("C++ Tutorial1").getLikes() == 1);
	assert(c.update("C++ Tutorial1", "C++ Tutorial", "Dorel Moga", 4, 5, 1, "https://www.exemplu.com") == true);
	assert(c.update("C++ Tutorial13412", "C++ Tutorial", "Dorel Moga", 4, 5, 1, "https://www.exemplu.com") == false);

	assert(c.remove("C++ Tutorial") == true);
	assert(c.remove("C++ Tutorial") == false);

	assert(c.getRepo().findTutorialByTitle("C++ Tutorial").getTitle() == "");


	Duration d{ 4, 54 };
	Tutorial t{ "C++ Tutorial4","Dorel Moga",d,1,"https://www.exemplu.com" };
	c.addTutorialToWatchList(t);
	c.nextTutorialWatchList();
	assert(c.getWatchList().getCurrentTutorial().getTitle() == "C++ Tutorial4");
	c.startWatchList();
	assert(c.getWatchList().getCurrentTutorial().getTitle() == "C++ Tutorial4");

	assert(c.getWatchList().getCurrentTutorial() == t);
	c.add("C++ Tutorial4", "Dorel Moga", 4, 5, 1, "https://www.exemplu.com");
	c.removeTutorialFromWatchList(true);
	assert(c.getRepo().findTutorialByTitle("C++ Tutorial4").getLikes() == t.getLikes()+1);

}