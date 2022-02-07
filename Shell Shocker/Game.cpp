/// <summary>
/// @author James Murray
/// @date 04/02/22
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800U, 600U, 32U }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	makeCircle(); // load circle
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	//temp code: Start circle movement when game begins - assign the velocity to the position, not to the sprite itself

}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	if (countSplash == 0)
	{
		splashScreen();
		countSplash++;
	}

	m_window.clear(sf::Color::White);
	m_window.draw(m_shell);

	m_window.display(); // prints to screen what has been drawn
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	if (!m_splashScreenT.loadFromFile("ASSETS\\IMAGES\\splashScreen.png"))
	{
		//error message
		std::cout << "Problem loading splashScreen" << std::endl;
	}
	m_splashScreen.setTexture(m_splashScreenT);
	m_splashScreen.setPosition(0.0f, 0.0f);
}

void Game::makeCircle()
{
	m_shell.setFillColor(sf::Color::Green);
	m_shell.setPosition((screenWidth / 2) - 50, (screenHeight / 2) - 50);
}

void Game::splashScreen()
{
	short secEllapsed = 0;

	while (secEllapsed <= 3)
	{
		//timer
		secEllapsed = clock() / CLOCKS_PER_SEC;

		m_window.clear(sf::Color::White);
		m_window.draw(m_splashScreen);
		m_window.display();
	}

}

//temp version, for commit 3
void Game::circleMove()
{
	//set position

	//assign velocity to position

}