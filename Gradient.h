#include <iostream>
#include <SFML/Graphics.hpp>

enum class MyColors
{
	Red,
	Green,
	Blue
};

class Gradient
{
private:
	MyColors ColorRound(sf::Color &color);
	int max(int a, int b);
public:
	std::vector<sf::VertexArray> matrix; //255 rows of n vertex
	Gradient(sf::Color color, int width, int heigh);
	void Display(sf::RenderWindow &window, int x, int y);

};

