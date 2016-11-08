#include "EventsUser.h"


std::string getMouvement(Carte &myCarte, Movable &player)
{
	std::string retour;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
	{
		if (myCarte.isWalkable(player.getPosX() + 1, player.getPosY()))
		{
			retour = "right";
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
	{
		if (myCarte.isWalkable(player.getPosX() - 1, player.getPosY()))
		{
			retour = "left";
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
	{
		if (myCarte.isWalkable(player.getPosX(), player.getPosY() - 1))
		{
			retour = "up";
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
	{
		if (myCarte.isWalkable(player.getPosX(), player.getPosY() + 1))
		{
			retour = "down";
		}
	}
	else
	{
		retour = "no mouvement";
	}
	return retour;
}
