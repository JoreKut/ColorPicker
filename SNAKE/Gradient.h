#include <iostream>
#include <SFML/Graphics.hpp>

enum MyColors
{
	Red,
	Green,
	Blue
};

class Gradient
{
private:
	MyColors PredominateColor(sf::Color color);
	int max(int a, int b);
public:
	std::vector<sf::VertexArray> matrix; //255 rows of n vertex
	int R = 0, G = 0, B = 0;
	Gradient(sf::Color color, int width, int heigh);
	void Display(sf::RenderWindow &window, int x, int y);

};

