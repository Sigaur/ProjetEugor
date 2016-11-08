#include "Display.h"
#include "EventsUser.h"

sf::RenderWindow window(sf::VideoMode(WINDOWX, WINDOWY), "SFML works!");

int main()
{
	bool action;
	Position tempPosition;
	srand(time(NULL));	
	//srand(1250);
	std::vector<int> levelSeeds;
	levelSeeds.push_back(rand());	
	int level = 0;
	srand(levelSeeds[level]);

	Carte *myCarte = new Carte();
	Movable *player = new Movable(1, "Player", 25, 25, 2);
	std::string playerAction = "";

	sf::Texture mapTexture;
	mapTexture.create(WINDOWX, WINDOWY);
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
			myCarte->displayCarte();
			//window.display();
			mapTexture.update(window);
			sf::Sprite mapSprite(mapTexture, sf::IntRect(0, 0, 500, 500));
			
		refreshDate = 0;
		while (true)
		{
			while (clock() - refreshDate < 100);//Wait at least 0.1s before refreshing (10fps max)
			refreshDate = clock();

			playerAction = getMouvement(*myCarte, *player);
			if (playerAction == "goingDown")
			{
				window.clear();
				window.display();
				if (level >= levelSeeds.size() - 1)
				{
					levelSeeds.push_back(rand());
				}
				level++;
				srand(levelSeeds[level]);
				std::cout << "Level: " << level << "/" << levelSeeds[level] << std::endl;

				
				myCarte->setTest();
				myCarte->dungeonTest(level);
				myCarte->displayCarte();
				//window.display();
				mapTexture.update(window);
				mapSprite.setTexture(mapTexture);
				tempPosition = myCarte->getPositionFromType(stairsUp);
				player->setPos(tempPosition.posX, tempPosition.posY);
			}
			if (playerAction == "goingUp" && level > 0)
			{
				window.clear();
				window.display();
				level--;
				srand(levelSeeds[level]);
				std::cout << "Level: " << level << "/" << levelSeeds[level] << std::endl;
				
				myCarte->setTest();
				myCarte->dungeonTest(level);
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
			entityDisplay(*player);
			window.display();
			//system("PAUSE");
		}
	}

	return 0;
}