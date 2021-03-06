#pragma once

#include "Database.h"

class GameLoop
{
public:
	GameLoop();
	~GameLoop();
	
	void startRun();
	void displayAll();
	void setViewOnPlayer();
	void updateAll();
	
	std::string getMouvement();	
private:
	int refreshRate;//Nb of miliseconds before another action is done
	Position m_posCam;
	sf::View m_viewDefault, m_viewMap;
	Database m_database;
	std::vector<int> m_levelSeeds;
	int m_level;
};

