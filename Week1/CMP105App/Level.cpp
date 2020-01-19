#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	sf::Vector2u pos = window->getSize();

	// initialise game objects
	rect1.setSize(sf::Vector2f(125, 125));
	rect1.setPosition(100, 100);
	rect1.setFillColor(sf::Color::Red);

	rect2.setSize(sf::Vector2f(75, 75));
	rect2.setPosition(125, 125);
	rect2.setFillColor(sf::Color::Green);

	rect3.setSize(sf::Vector2f(25, 25));
	rect3.setPosition(150, 150);
	rect3.setFillColor(sf::Color::Blue);

	rect4.setSize(sf::Vector2f(100, 100));
	rect4.setPosition(pos.x - 150, pos.y - 150);
	rect4.setFillColor(sf::Color::Green);

	circle.setRadius(50);
	circle.setPosition(pos.x / 2, pos.y / 2);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(5.f);

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	text.setFont(font);
	text.setString("Hello World");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(pos.x / 2, 0);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u pos = window->getSize();

	rect4.setPosition(pos.x - 150, pos.y - 150);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circle);
	window->draw(rect1);
	window->draw(rect2);
	window->draw(rect3);
	window->draw(text);
	window->draw(rect4);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}