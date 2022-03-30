#include "Square.h"
#include "Rectangle.h"

Square::Square() {}
Square::Square(const int& Size) {
	x = y = Size;
}

void Square::Draw(){
	Rectangle rect(x, x);
	rect.Draw();
}