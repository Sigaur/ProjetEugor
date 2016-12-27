#include "EventsUser.h"

sf::RenderWindow window(sf::VideoMode(WINDOWX, WINDOWY), "Projet Eugor!");

int main()
{
	sf::View viewDefault = window.getView();
	sf::View viewMap(sf::FloatRect(0, 0, 1600, 1600));
	viewMap.zoom(0.5);
	viewMap.setCenter(528, 528);
	
	Position tempPosition;
	srand(time(NULL));
	//srand(1251);

	int numberOfLastAction;
	std::string lastAction;
	
	std::vector<int> levelSeeds;
	levelSeeds.push_back(rand());	
	int level = 0;
	srand(levelSeeds[level]);
	std::vector<std::vector <bool>> doors;

	Carte myCarte = Carte();
	Movable player = Movable(1, "Player", 25, 25, 2);
	std::string playerAction = "";

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
			viewMap.setCenter(((player.getPosX()) * 32) + 16, ((player.getPosY()) * 32) + 16);
			window.setView(viewMap);
			myCarte.setTest();
			myCarte.dungeonTest(level);
			myCarte.displayCarte(player);
			//myCarte.displayDoors();
			myCarte.m_display.entityDisplay(player);
			window.display();
			
		refreshDate = 0;
		while (true)
		{
			while (clock() - refreshDate < 200);//Wait at least 0.1s before refreshing (10fps max)
			do
			{
				playerAction = getMouvement(myCarte, player);//Getting the User Action
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

			if (playerAction == "camRight")
			{
				viewMap.move(32, 0);
				window.setView(viewMap);
			}
			if (playerAction == "camLeft")
			{
				viewMap.move(-32, 0);
				window.setView(viewMap);
			}
			if (playerAction == "camUp")
			{
				viewMap.move(0, -32);
				window.setView(viewMap);
			}
			if (playerAction == "camDown")
			{
				viewMap.move(0, 32);
				window.setView(viewMap);
			}
			if (playerAction == "goingDown")
			{
				level++;
				window.clear();
				window.display();
				if (level >= levelSeeds.size())
				{
					levelSeeds.push_back(rand());
				}
				srand(levelSeeds[level]);
				//std::cout << "Level: " << level << "/" << levelSeeds[level] << std::endl;

				//doorsManagement
				//saving
				if (level - 1 >= doors.size())
				{
					doors.push_back(myCarte.saveDoors());
					//std::cout << "Saving New :" << doors.size() - 1 << std::endl;
				}
				else
				{
					doors[level-1] = myCarte.saveDoors();
					//std::cout << "Saving In :" << level - 1 << std::endl;
				}
				
				
				myCarte.setTest();
				myCarte.dungeonTest(level);
				
				//loadingDoors
				if (level < doors.size())
				{
					myCarte.setDoors(doors[level]);
					//std::cout << "Loading :" << level << std::endl;
				}
				
				//system("Pause");
				tempPosition = myCarte.getPositionFromType(stairsUp);
				player.setPos(tempPosition.posX, tempPosition.posY);
			}
			if (playerAction == "goingUp" && level > 0)
			{
				level--;
				window.clear();
				window.display();				
				srand(levelSeeds[level]);
				
				//std::cout << "Level: " << level << "/" << levelSeeds[level] << std::endl;

				//doorsManagement
				//saving
				if (level + 1 >= doors.size())
				{
					doors.push_back(myCarte.saveDoors());
					//std::cout << "Saving New :" << doors.size() - 1 << std::endl;
				}
				else
				{
					doors[level + 1] = myCarte.saveDoors();
					//std::cout << "Saving In :" << level + 1 << std::endl;
				}
				
				myCarte.setTest();
				myCarte.dungeonTest(level);
				//loadingDoors
				if (level < doors.size())
				{
					myCarte.setDoors(doors[level]);
					//std::cout << "Loading :" << level << std::endl;
				}
				tempPosition = myCarte.getPositionFromType(stairsDown);
				player.setPos(tempPosition.posX, tempPosition.posY);
			}
			
			{
				player.move(playerAction);
				viewMap.setCenter(((player.getPosX()) * 32) + 16, ((player.getPosY()) * 32) + 16);
			}
			
			window.clear();
			window.setView(viewMap);
			myCarte.displayCarte(player);
			myCarte.displayDoors();
			myCarte.m_display.entityDisplay(player);
			window.display();
			//system("PAUSE");
		}
	}

	return 0;
}