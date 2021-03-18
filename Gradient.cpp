#include "Gradient.h"

Gradient::Gradient(sf::Color color, int width, int height) {
	bool up = true, down = false;
	sf::VertexArray va = sf::VertexArray(sf::Points, 0);
	MyColors prevailingColor = Gradient::ColorRound(color);

	int cR = (int)sf::Uint8(color.r);
	int cG = (int)sf::Uint8(color.g);
	int cB = (int)sf::Uint8(color.b);

	float y_red_step   = (float)cR / height;
	float y_green_step = (float)cG / height;
	float y_blue_step =  (float)cB / height;

	int R, G, B;
	
	sf::Vertex vertex;

	for (int j = 0; j < height; j++) {

		R = cR - j * y_red_step   ;
		G = cG - j * y_green_step ;
		B = cB - j * y_blue_step  ;

		int rr = R, gg = G, bb = B;

		for (int i = 0; i < width; i++) {
			
			vertex.position.x = width - i;
			vertex.position.y = j;

			R = rr + i * (255 - j * 255 / height - rr) / width;
			G = gg + i * (255 - j * 255 / height - gg) / width;
			B = bb + i * (255 - j * 255 / height - bb) / width;

			vertex.color = sf::Color(R, G, B);
			va.append(vertex);
		}


		matrix.push_back(va);	
	}
}

int Gradient::max(int a, int b) {
	return a > b ? a : b;
}

MyColors Gradient::ColorRound(sf::Color &color) {
	int a = (int)sf::Uint8(color.r);
	int b = (int)sf::Uint8(color.g);
	int c = (int)sf::Uint8(color.b);

	int max = Gradient::max(Gradient::max(a, b), Gradient::max(a, b));


	if (max == a) {
		color = sf::Color(255, b, c);
		return MyColors::Red;
	}
	if (max == b) {
		color = sf::Color(a, 255, c);
		return MyColors::Green;
	}
	color = sf::Color(a, b, 255);
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