#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class HallOfFame
{
public:
	int i;
	string username;
	int score;
	int time;
	HallOfFame();
	void draw(sf::RenderWindow& window);
	void loadFont();
	string inputUsername(sf::RenderWindow& window);
	void fStream();
	int filelength();
	int addScore();
	bool userEntered;
	vector <HallOfFame>allUsers;
	void readFromFile();
	void drawCurrentScore(sf::RenderWindow& window);
	int getTotalTimePlayed();
	bool sortByScore(const HallOfFame&, const HallOfFame&);
	void setWinners(int element);
	int j;
private:
	int length;
	sf::Text inputUsernameText;
	sf::Text currentUser;
	sf::Font Arial;
	sf::Text winners[10];
	sf::Text ScoreDesc;
	sf::Text Score;
	sf::Clock clock;
	int height;
	int width;
	float heightDivider;
};

