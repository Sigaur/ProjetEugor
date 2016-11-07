#include "carte.h"
#include "common.h"
#include "display.h"

sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

void testDisplay(Entity entity)
{
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(5, 5));
	shape.setPosition((entity.getPosX() * 10), (entity.getPosY() * 10));
	//shape.setPosition(250, 250);
	std::cout << "test" << shape.getPosition().x << "  " << shape.getPosition().x << std::endl;
	shape.setFillColor(sf::Color::Green);
	window.draw(shape);
}

int main()
{
	unsigned int seed = 4005474148;
	srand(time(NULL));
	Carte *myCarte = new Carte();
	std::vector <Entity> player;
	player.push_back(Entity(1, "Player", 25, 25));
	
	
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
			//window.clear();
			myCarte->displayCarte();
			entityDisplay(player[0]);
			window.display();
			system("PAUSE");
		}
	}

	return 0;
}