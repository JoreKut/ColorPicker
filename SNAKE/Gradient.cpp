#include "Gradient.h"

Gradient::Gradient(sf::Color color, int width, int height) {
	bool up = true, down = false;
	sf::VertexArray va = sf::VertexArray(sf::Points, 0);
	MyColors prevailingColor = Gradient::PredominateColor(color);

	float x_red_step   = (int)sf::Uint8(color.r);
	float x_green_step = (int)sf::Uint8(color.g);
	float x_blue_step  = (int)sf::Uint8(color.b);

	float y_red_step   = (int)sf::Uint8(color.r);
	float y_green_step = (int)sf::Uint8(color.g);
	float y_blue_step  = (int)sf::Uint8(color.b);

	
	sf::Vertex vertex;

	for (int j = 0; j < height; j++) {

		for (int i = 0; i < width; i++) {
			
			vertex.position.x = i;
			vertex.position.y = j;
			switch (prevailingColor)
			{
			case Red:
				vertex.color = sf::Color(255 - j * y_red_step, 255 - i * x_green_step - j * y_green_step, 255 - i * x_blue_step - j * y_blue_step);
				break;
			case Green:
				vertex.color = sf::Color(255 - i * x_red_step - j * y_red_step, 255 - j * y_green_step, 255 - i * x_blue_step - j * y_blue_step);
				break;
			case Blue:
				vertex.color = sf::Color(255 - i * x_red_step - j * y_red_step, 255 - i * x_green_step - j * y_green_step, 255 - j * y_blue_step);
				break;
			default:
				break;
			}
			va.append(vertex);
		}


		matrix.push_back(va);	
	}
}

int Gradient::max(int a, int b) {
	return a > b ? a : b;
}

MyColors Gradient::PredominateColor(sf::Color color) {
	int a = (int)sf::Uint8(color.r);
	int b = (int)sf::Uint8(color.g);
	int c = (int)sf::Uint8(color.b);

	int max = Gradient::max(Gradient::max(a, b), Gradient::max(a, b));

	if (max == a) return MyColors::Red;
	if (max == b) return MyColors::Green;
	
	return MyColors::Blue;
	
}

void Gradient::Display(sf::RenderWindow &window, int x, int y) {
	for (sf::VertexArray va : matrix) {
		for (int i = 0; i < va.getVertexCount(); i++) {
			va[i].position.x += x;
			va[i].position.y += y;
		}
		window.draw(va);
	}
}