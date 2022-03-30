#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"

int main() {

	Rectangle rect(8,6);
	rect.Draw();
	std::cout << std::endl;
	Square square;
	square.Draw();
	std::cout << std::endl;
	Circle circle(10);
	circle.Draw();
	return 0;
}
