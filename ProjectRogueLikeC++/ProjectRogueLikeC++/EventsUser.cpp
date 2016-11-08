#include "EventsUser.h"


std::string getMouvement(Carte &myCarte, Movable &player)
{
	std::string retour;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
	{
		if (myCarte.walking(player.getPosX() + 1, player.getPosY()))
		{
			retour = "right";
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
	{
		if (myCarte.walking(player.getPosX() - 1, player.getPosY()))
		{
			retour = "left";
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
	{
		if (myCarte.walking(player.getPosX(), player.getPosY() - 1))
		{
			retour = "up";
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
	{
		if (myCarte.walking(player.getPosX(), player.getPosY() + 1))
		{
			retour = "down";
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
	{
		if (myCarte.walking(player.getPosX() + 1, player.getPosY() - 1))
		{
			retour = "upRight";
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))
	{
		if (myCarte.walking(player.getPosX() - 1, player.getPosY() - 1))
		{
			retour = "upLeft";
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
	{
		if (myCarte.walking(player.getPosX() + 1, player.getPosY() + 1))
		{
			retour = "downRight";
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
	{
		if (myCarte.walking(player.getPosX() - 1, player.getPosY() + 1))
		{
			retour = "downLeft";
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (myCarte.getType(player.getPosX(), player.getPosY()) == stairsDown)
		{
			retour = "goingDown";
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	{
		if (myCarte.getType(player.getPosX(), player.getPosY()) == stairsUp)
		{
			retour = "goingUp";
		}
	}
	else
	{
		retour = "no mouvement";
	}
	return retour;
}
