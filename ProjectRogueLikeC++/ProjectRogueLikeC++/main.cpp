#include "Display.h"
#include "EventsUser.h"

sf::RenderWindow window(sf::VideoMode(WINDOWX, WINDOWY), "SFML works!");

int main()
{
	sf::View viewDefault = window.getView();
	sf::View viewMap(sf::FloatRect(0, 0, 1600, 1600));
	
	bool action;
	Position tempPosition;
	srand(time(NULL));	
	srand(1251);
	
	std::vector<int> levelSeeds;
	levelSeeds.push_back(rand());	
	int level = 0;
	srand(levelSeeds[level]);
	std::vector<std::vector <bool>> doors;

	Carte *myCarte = new Carte();
	Movable *player = new Movable(1, "Player", 25, 25, 2);
	std::string playerAction = "";

	sf::Texture mapTexture;
	mapTexture.create(500, 500);

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
				break;
			}
				
		}
			myCarte->setTest();
			myCarte->dungeonTest(level);
			window.setView(viewMap);
			myCarte->displayCarte();
			//window.display();
			//system("Pause");
			mapTexture.update(window);
			sf::Sprite mapSprite(mapTexture, sf::IntRect(0, 0, 1600, 1600));
			mapSprite.setScale(3.2, 3.2);	
			//viewMap.zoom(0.5);
			//viewMap.setCenter(400, 400);
			window.setView(viewMap);

			
		refreshDate = 0;
		while (true)
		{
			while (clock() - refreshDate < 100);//Wait at least 0.1s before refreshing (10fps max)
			refreshDate = clock();

			playerAction = getMouvement(*myCarte, *player);
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
					doors.push_back(myCarte->saveDoors());
					//std::cout << "Saving New :" << doors.size() - 1 << std::endl;
				}
				else
				{
					doors[level-1] = myCarte->saveDoors();
					//std::cout << "Saving In :" << level - 1 << std::endl;
				}
				
				
				myCarte->setTest();
				myCarte->dungeonTest(level);
				
				//loadingDoors
				if (level < doors.size())
				{
					myCarte->setDoors(doors[level]);
					//std::cout << "Loading :" << level << std::endl;
				}
				
				//system("Pause");
				myCarte->displayCarte();
				//window.display();
				mapTexture.update(window);
				mapSprite.setTexture(mapTexture);
				tempPosition = myCarte->getPositionFromType(stairsUp);
				player->setPos(tempPosition.posX, tempPosition.posY);
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
					doors.push_back(myCarte->saveDoors());
					//std::cout << "Saving New :" << doors.size() - 1 << std::endl;
				}
				else
				{
					doors[level + 1] = myCarte->saveDoors();
					//std::cout << "Saving In :" << level + 1 << std::endl;
				}
				
				myCarte->setTest();
				myCarte->dungeonTest(level);
				//loadingDoors
				if (level < doors.size())
				{
					myCarte->setDoors(doors[level]);
					//std::cout << "Loading :" << level << std::endl;
				}

				myCarte->displayCarte();
				//window.display();
				mapTexture.update(window);
				mapSprite.setTexture(mapTexture);
				tempPosition = myCarte->getPositionFromType(stairsDown);
				player->setPos(tempPosition.posX, tempPosition.posY);
			}
			else
			{
				player->move(getMouvement(*myCarte, *player));
			}
			
			window.clear();
			window.draw(mapSprite);
			myCarte->displayDoors();
			//entityDisplay(*player);
			window.display();
			//system("PAUSE");
		}
	}

	return 0;
}