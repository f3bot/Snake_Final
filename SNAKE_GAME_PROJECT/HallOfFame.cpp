#include "HallOfFame.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

HallOfFame::HallOfFame()
{
	loadFont();
	height = 1080;
	width = 720;
	heightDivider = 0;
	userEntered = false;
	currentUser.setFont(Arial);
	currentUser.setFillColor(sf::Color::Red);
	inputUsernameText.setFont(Arial);
	inputUsernameText.setFillColor(sf::Color::Red);
	ScoreDesc.setFont(Arial);
	Score.setFont(Arial);
	Score.setFillColor(sf::Color::Red);
	ScoreDesc.setFillColor(sf::Color::Red);
	username = "";
	score = 0;
	time = 0;
	i = 0;
	j = 1;
	for (int i = 0; i < 10; i++)
	{
		winners[i].setFont(Arial);
		winners[i].setFillColor(sf::Color::Red);
	}
}

void HallOfFame::setWinners(int element)
{
	winners[element].setPosition(350, 100 * j);
	winners[element].setString(allUsers[element].username);
	winners[element + 1].setPosition(650, 100 * j);
	winners[element + 1].setString(to_string(allUsers[element].score));
	i++;
	j++;
	std::cout << "ELEMENT NR -> " << i << allUsers[element].username << "SCORE +>" << allUsers[element].score << endl;
}


void HallOfFame::draw(sf::RenderWindow& window)
{
	setWinners(0);
	setWinners(2);
	setWinners(4);
	setWinners(6);
	setWinners(8);
	cout << "DRAW FUNCTION" << endl;
	while (window.isOpen())
	{
		sf::sleep(sf::Time(sf::milliseconds(100)));
		sf::Event event; //JK
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		for (int i = 0; i < 10; i++) {
			window.draw(winners[i]);
		}
		window.display();
	}
	cout << "END OF DRAW FUNCTION" << endl;
}

void HallOfFame::loadFont()
{
	if (!Arial.loadFromFile("arial.ttf")) {
		std::cout << "Nie wczytano fonta\n";
	}
}

string HallOfFame::inputUsername(sf::RenderWindow& window)
{
	inputUsernameText.setString("Wpisz username, kliknij enter aby zakonczyc");
	inputUsernameText.setPosition(260, 100);
	sf::Event event;
	while (!userEntered)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == '\r')
				{
					userEntered = true;
				}
				else if (event.text.unicode == '\b')
				{
					username.pop_back();
				}
				else if (event.text.unicode < 128)
				{
					username += static_cast<char>(event.text.unicode);
				}
			}
		}

		currentUser.setString(username);
		currentUser.setPosition(500, 400);

		window.draw(inputUsernameText);
		window.draw(currentUser);
		window.display();
		window.clear();
	}
	std::cout << username << std::endl;
	return username;
}

void HallOfFame::fStream()
{
	getTotalTimePlayed();

	fstream dane;
	dane.open("leaderboard.txt", ios::out | ios::app);

	dane << username << endl;
	dane << score << endl;
	dane << time << endl;
}

int HallOfFame::filelength()
{
	string line;
	ifstream file("leaderboard.txt");
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			length++;
		}
		file.close();
		length--;
	}
	return length;
}

int HallOfFame::addScore()
{
	score++;
	std::cout << "wynik=>" << score << std::endl;
	return score;
}

 void HallOfFame::readFromFile()
{
	filelength();
	ifstream file("leaderboard.txt");
	string line;
	file.clear();
	file.seekg(0, ios::beg);
	int i = 0;
	while (getline(file, line))
	{
		HallOfFame obiekt;
		obiekt.username = line;
		getline(file, line);
		obiekt.score = stoi(line);
		getline(file, line);
		obiekt.time = stoi(line);
		allUsers.push_back(obiekt);
		i++;
	}
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < allUsers.size() - 1; i++)
		{
			if (sortByScore(allUsers[i + 1], allUsers[i]))
			{
				swap(allUsers[i], allUsers[i+1]);
				sorted = false;
			}
		}
	}
}


void HallOfFame::drawCurrentScore(sf::RenderWindow& window)
{
	ScoreDesc.setString("Twoj wynik to => ");
	ScoreDesc.setPosition(0,0);
	Score.setString(to_string(score));
	Score.setPosition(230, 0);
	window.draw(ScoreDesc);
	window.draw(Score);
}

int HallOfFame::getTotalTimePlayed()
{
	std::cout << clock.getElapsedTime().asSeconds() << std::endl;
	time = clock.getElapsedTime().asSeconds();
	return time;
}

bool HallOfFame::sortByScore(const HallOfFame& a, const HallOfFame& b)
{
	return a.score > b.score;
}

