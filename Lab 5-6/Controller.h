#pragma once
#include "Repository.h"
#include "WatchList.h"
class Controller
{
private:
	Repository repo;
	WatchList watchList;
public:
	Controller(const Repository& r): repo{r}{}
	Repository getRepo() { return repo; }
	WatchList getWatchList() { return watchList; }
	bool add(const std::string& title,const std::string& presenter, const double& minutes, const double& seconds, const int& likes, const std::string& link);
	bool remove(const std::string& title);
	bool update(const std::string& oldTitle,const std::string& title, const std::string& presenter, const double& minutes, const double& seconds, const int& likes, const std::string& link);
	void addTutorialToWatchList(const Tutorial& tutorial);
	void removeTutorialFromWatchList(bool like);
	void startWatchList();
	void nextTutorialWatchList();
};

