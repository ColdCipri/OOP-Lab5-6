#pragma once
#include <iostream>

class Duration
{
private:
	double minutes;
	double seconds;
public:
	Duration() : minutes(0), seconds(0) {}
	Duration(double min, double sec) : minutes(min), seconds(sec) {}

	double getMinutes() const { return minutes; }
	double getSeconds() const { return seconds; }
	void setMinutes(double min) { minutes = min; }
	void setSeconds(double sec) { seconds = sec; }
};

class Tutorial
{
private:
	std::string title;
	std::string presenter;
	Duration duration;
	int likes;
	std::string link;

public:
	Tutorial();
	Tutorial(const std::string& title, const std::string& presenter, const Duration& duration, const int& likes, const std::string& link);
	std::string getTitle() const { return title; }
	std::string getPresenter() const { return presenter;}
	Duration getDuration() const { return duration; }
	std::string getLink() const { return link; }
	int getLikes() const { return likes; }
	bool accessLink();
	bool operator==(const Tutorial& t);

};

