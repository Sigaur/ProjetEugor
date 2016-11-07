#include "carte.h"
#include "common.h"

sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

int main()
{
	srand(time(NULL));
	Carte *myCarte = new Carte();
	
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		while (true)
		{
			myCarte->setTest();
			myCarte->dungeonTest();
			window.clear();
			myCarte->displayCarte();
			window.display();
			system("PAUSE");
		}
	}

	return 0;
}