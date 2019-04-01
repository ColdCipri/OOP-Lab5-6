#include "Tutorial.h"
#include <Windows.h>
#include <shellapi.h>
Tutorial::Tutorial() : title(""), presenter(""), duration(Duration()), likes(0), link("") {}
Tutorial::Tutorial(const std::string& title, const std::string& presenter, const Duration& duration, const int& likes, const std::string& link)
{
	this->title = title;
	this->presenter = presenter;
	this->duration = duration;
	this->likes = likes;
	this->link = link;
}


bool Tutorial::accessLink()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
	return true;

}
bool Tutorial::operator==(const Tutorial& t)
{
	if (this->title == t.getTitle())
		return true;
	return false;
}