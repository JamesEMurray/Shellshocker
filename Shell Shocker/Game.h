/// <summary>
///author James Murray
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
#include "MyVector2.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();
	void makeCircle();
	void splashScreen(); //displays the splash screen (3 seconds)
	void circleMove(); // temp - When game begins, circle moves

	float screenWidth = 800.0;
	float screenHeight = 600.0;

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	bool m_exitGame; // control exiting game
	sf::CircleShape m_shell{ 50.0f }; // shell
	sf::Sprite m_splashScreen; // splashscreen
	sf::Texture m_splashScreenT; // splashscreen texture
	short countSplash = 0;

};

#endif // !GAME_HPP

