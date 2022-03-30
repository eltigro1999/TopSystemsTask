#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() {}
Rectangle::Rectangle(const int& x, const int& y) {
	this->x = x;
	this->y = y;
}

void Rectangle::Draw() {
	HorizontalBorder.reserve(x);
	VerticalBorder.reserve(x);
	HorizontalBorder.resize(x, '-');
	VerticalBorder.resize(x, ' ');
	HorizontalBorder[0] = HorizontalBorder[x - 1] = '+';
	VerticalBorder[0] = VerticalBorder[x-1] = '|';
	DrawHorizontalBorder();
	int Height = y - 2;
	DrawVerticalBorder(Height);
	DrawHorizontalBorder();
}

void Rectangle::DrawHorizontalBorder(){
	for (const auto& BorderPart : HorizontalBorder) {
		std::cout << BorderPart;
	}
	std::cout << std::endl;
}

void Rectangle::DrawVerticalBorder(const int& Height) {
	for (int i = 0; i < Height; ++i) {
		for (const auto& BorderPart : VerticalBorder) {
			std::cout << BorderPart;
		}
		std::cout << std::endl;
	}
}