#pragma once
#include "Controller.h"
class ui
{
private:
	Controller ctrl;
public:
	ui(const Controller& c) : ctrl(c) {}
	void run();
private:
	static void printMenu();
	void administrator();
	void user();
	void printAdministratorMenu();
	void ui_add();
	void ui_printAllTutorials();
	void ui_remove();
	void ui_update();
	void printUserMenu();
	void ui_printTutorialsByPresenter();
	std::string play(Tutorial& t);
	void ui_printWatchList();
	void ui_removeTutorialFromWatchList();

};

