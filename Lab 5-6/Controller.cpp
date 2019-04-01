#include "Controller.h"



bool Controller::add(const std::string& title,const std::string& presenter, const double& minutes,const double& seconds, const int& likes, const std::string& link)
{
	Duration d{ minutes,seconds };
	if (repo.findTutorialByTitle(title).getTitle() != "")
		return false;
	Tutorial t{ title,presenter,d,likes,link };
	repo.addTutorial(t);
	return true;
}
bool Controller::remove(const std::string& title)
{	
	Tutorial t = repo.findTutorialByTitle(title);
	if (t.getTitle() != "")
	{
		repo.removeTutorial(t);
		return true;
	}
	return false;
}
void Controller::removeTutorialFromWatchList(bool like)
{
	Tutorial t = this->watchList.getCurrentTutorial();
	this->watchList.remove(t);
	if (like == true)
	{
		update(t.getTitle(), t.getTitle(), t.getPresenter(), t.getDuration().getMinutes(), t.getDuration().getSeconds(), t.getLikes() + 1, t.getLink());
	}

}

bool Controller::update(const std::string& oldTitle,const std::string& title, const std::string& presenter, const double& minutes, const double& seconds, const int& likes, const std::string& link)
{
	Tutorial old = repo.findTutorialByTitle(oldTitle);
	if (old.getTitle() != "")
	{
		Duration d{ minutes,seconds };
		Tutorial t{ title,presenter,d,likes,link };

		repo.updateTutorial(old,t);
		return true;
	}
	return false;
}

void Controller::addTutorialToWatchList(const Tutorial& tutorial)
{
	this->watchList.add(tutorial);
}
void Controller::startWatchList()
{
	this->watchList.play();
}
void Controller::nextTutorialWatchList()
{
	this->watchList.next();
}