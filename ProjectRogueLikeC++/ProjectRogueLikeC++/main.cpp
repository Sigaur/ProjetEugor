#include "Display.h"
#include "EventsUser.h"

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


			player->move(getMouvement(*myCarte, *player));
			
			window.clear();
			window.draw(mapSprite);
			entityDisplay(*player);
			window.display();
			//system("PAUSE");
		}
	}

	return 0;
}