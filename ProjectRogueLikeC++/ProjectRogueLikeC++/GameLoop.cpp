#include "GameLoop.h"

sf::RenderWindow window(sf::VideoMode(WINDOWX, WINDOWY), "Projet Eugor!");

GameLoop::GameLoop()
{
	this->m_viewDefault = window.getView();
	this->m_viewMap = sf::View (sf::FloatRect(0, 0, 1600, 1600));
	this->m_viewMap.zoom(0.5);
	window.setView(m_viewMap);

	this->m_database = Database();
}

void GameLoop::startRun()
{
	Position tempPosition;//Used for setting the position of the player when switching levels
	std::string playerAction = "";
	srand(time(NULL));

	int numberOfLastAction = 0;//Used for speeding the movements when key is not realeased
	std::string lastAction;

	this->m_levelSeeds.push_back(rand());
	this->m_level = 0;
	srand(this->m_levelSeeds[this->m_level]);
	
	int refreshDate;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			default:
				break;
			case sf::Event::Closed:
				window.close();
			case sf::Event::Resized:
				std::cout << "new width: " << event.size.width << std::endl;
				std::cout << "new height: " << event.size.height << std::endl;
				break;
			}
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		this->m_database.createLevel(this->m_level);
		setViewOnPlayer();
		displayAll();

		refreshDate = 0;
		while (true)
		{
			while (clock() - refreshDate < 200);//Wait at least 0.1s before refreshing (10fps max)
			do
			{
				playerAction = getMouvement();//Getting the User Input
				if (lastAction != playerAction)
				{
					lastAction = playerAction;
					numberOfLastAction = 0;
				}
				else
					numberOfLastAction++;
			} while (playerAction == "no mouvement");
			refreshDate = clock();

			if (numberOfLastAction > 1)
				refreshDate -= 125;

			displayAll();
		}
	}
}

std::string GameLoop::getMouvement()
{
	std::string retour;
	Position tempPosition;

	//Camera Mouvement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		retour = "camRight";
		m_viewMap.move(32, 0);
		window.setView(m_viewMap);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		retour = "camLeft";
		m_viewMap.move(-32, 0);
		window.setView(m_viewMap);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		retour = "camUp";
		m_viewMap.move(0, -32);
		window.setView(m_viewMap);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		retour = "camDown";
		m_viewMap.move(0, 32);
		window.setView(m_viewMap);
	}

	//Player Mouvement
		//Moving
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
		{
			if (this->m_database.m_carte.walking(this->m_database.m_player.getPosX() + 1, this->m_database.m_player.getPosY()))
			{
				retour = "right";
				this->m_database.m_player.move(retour);
				setViewOnPlayer();
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
		{
			if (this->m_database.m_carte.walking(this->m_database.m_player.getPosX() - 1, this->m_database.m_player.getPosY()))
			{
				retour = "left";
				this->m_database.m_player.move(retour);
				setViewOnPlayer();
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
		{
			if (this->m_database.m_carte.walking(this->m_database.m_player.getPosX(), this->m_database.m_player.getPosY() - 1))
			{
				retour = "up";
				this->m_database.m_player.move(retour);
				setViewOnPlayer();
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
		{
			if (this->m_database.m_carte.walking(this->m_database.m_player.getPosX(), this->m_database.m_player.getPosY() + 1))
			{
				retour = "down";
				this->m_database.m_player.move(retour);
				setViewOnPlayer();
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
		{
			if (this->m_database.m_carte.walking(this->m_database.m_player.getPosX() + 1, this->m_database.m_player.getPosY() - 1))
			{
				retour = "upRight";
				this->m_database.m_player.move(retour);
				setViewOnPlayer();
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))
		{
			if (this->m_database.m_carte.walking(this->m_database.m_player.getPosX() - 1, this->m_database.m_player.getPosY() - 1))
			{
				retour = "upLeft";
				this->m_database.m_player.move(retour);
				setViewOnPlayer();
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
		{
			if (this->m_database.m_carte.walking(this->m_database.m_player.getPosX() + 1, this->m_database.m_player.getPosY() + 1))
			{
				retour = "downRight";
				this->m_database.m_player.move(retour);
				setViewOnPlayer();
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
		{
			if (this->m_database.m_carte.walking(this->m_database.m_player.getPosX() - 1, this->m_database.m_player.getPosY() + 1))
			{
				retour = "downLeft";
				this->m_database.m_player.move(retour);
				setViewOnPlayer();
			}
		}
		//Switching Levels//To Be cleaned
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (this->m_database.m_carte.getType(this->m_database.m_player.getPosX(), this->m_database.m_player.getPosY()) == stairsDown)
			{
				retour = "goingDown";
				this->m_level++;
				window.clear();
				window.display();
				if (this->m_level >= this->m_levelSeeds.size())
				{
					this->m_levelSeeds.push_back(rand());
				}
				srand(this->m_levelSeeds[this->m_level]);

				//doorsManagement
				//saving
				if (this->m_level - 1 >= this->m_database.m_doors.size())
				{
					this->m_database.m_doors.push_back(this->m_database.m_carte.saveDoors());
					//std::cout << "Saving New :" << this->m_database.m_doors.size() - 1 << std::endl;
				}
				else
				{
					this->m_database.m_doors[this->m_level - 1] = this->m_database.m_carte.saveDoors();
					//std::cout << "Saving In :" << level - 1 << std::endl;
				}

				this->m_database.createLevel(this->m_level);

				//loadingDoors
				if (this->m_level < this->m_database.m_doors.size())
				{
					this->m_database.m_carte.setDoors(this->m_database.m_doors[this->m_level]);
					//std::cout << "Loading :" << level << std::endl;
				}

				//system("Pause");
				tempPosition = this->m_database.m_carte.getPositionFromType(stairsUp);
				this->m_database.m_player.setPos(tempPosition.posX, tempPosition.posY);
				setViewOnPlayer();
			}
		}//To be cleaned
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		{
			if (this->m_database.m_carte.getType(this->m_database.m_player.getPosX(), this->m_database.m_player.getPosY()) == stairsUp)
			{
				if (m_level > 0)
				{
					retour = "goingUp";
					this->m_level--;
					window.clear();
					window.display();
					srand(this->m_levelSeeds[this->m_level]);

					//std::cout << "Level: " << level << "/" << levelSeeds[level] << std::endl;

					//doorsManagement
					//saving
					if (this->m_level + 1 >= this->m_database.m_doors.size())
					{
						this->m_database.m_doors.push_back(this->m_database.m_carte.saveDoors());
						//std::cout << "Saving New :" << this->m_database.m_doors.size() - 1 << std::endl;
					}
					else
					{
						this->m_database.m_doors[this->m_level + 1] = this->m_database.m_carte.saveDoors();
						//std::cout << "Saving In :" << level + 1 << std::endl;
					}

					this->m_database.createLevel(this->m_level);

					//loadingDoors
					if (this->m_level < this->m_database.m_doors.size())
					{
						this->m_database.m_carte.setDoors(this->m_database.m_doors[this->m_level]);
						//std::cout << "Loading :" << level << std::endl;
					}
					tempPosition = this->m_database.m_carte.getPositionFromType(stairsDown);
					this->m_database.m_player.setPos(tempPosition.posX, tempPosition.posY);
					setViewOnPlayer();
				}
			}
		}//To be cleaned
	else
	{
		retour = "no mouvement";
	}
	return retour;
}

void GameLoop::displayAll()
{
	window.clear();
	this->m_database.displayAll();
	window.display();
}

void GameLoop::setViewOnPlayer()
{
	m_viewMap.setCenter(((this->m_database.m_player.getPosX()) * 32) + 16, ((this->m_database.m_player.getPosY()) * 32) + 16);
	window.setView(m_viewMap);
}

GameLoop::~GameLoop()
{
}
