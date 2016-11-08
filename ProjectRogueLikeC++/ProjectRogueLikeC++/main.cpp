#include "Carte.h"
#include "Common.h"
#include "Display.h"

sf::RenderWindow window(sf::VideoMode(WINDOWX, WINDOWY), "SFML works!");

int main()
{
	bool action;
	unsigned int seed = 4005474148;	
	srand(time(NULL));
	Carte *myCarte = new Carte();
	Movable *player = new Movable(1, "Player", 25, 25, 2);

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
			myCarte->dungeonTest();
			myCarte->displayCarte();
			//window.display();
			mapTexture.update(window);
			sf::Sprite mapSprite(mapTexture, sf::IntRect(0, 0, 500, 500));
			
		refreshDate = 0;
		while (true)
		{
			while (clock() - refreshDate < 100);//Wait at least 0.1s before refreshing (10fps max)
			refreshDate = clock();

			//////////////////////////////////////CRONTROLLING PLAYER TO BE MOVED////////////
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
			{
				if (myCarte->isWalkable(player->getPosX() + 1, player->getPosY()))
				{
					player->moveRight();
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
			{
				if (myCarte->isWalkable(player->getPosX() - 1, player->getPosY()))
				{
					player->moveLeft();
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
			{
				if (myCarte->isWalkable(player->getPosX(), player->getPosY() - 1))
				{
					player->moveUp();
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
			{
				if (myCarte->isWalkable(player->getPosX(), player->getPosY() + 1))
				{
					player->moveDown();
				}
			}
			//////////////////////////////////////CRONTROLLING PLAYER TO BE MOVED////////////
			
			window.clear();
			window.draw(mapSprite);
			entityDisplay(*player);
			window.display();
			//system("PAUSE");
		}
	}

	return 0;
}