#include "Shape.h"
#include <vector>


class Rectangle: public Shape {
private:
	std::vector<char> HorizontalBorder;
	std::vector<char> VerticalBorder;
	void DrawHorizontalBorder();
	void DrawVerticalBorder(const int& Height);
public:
	Rectangle();
	Rectangle(const int& x,const int& y);
	virtual void Draw() override;
};