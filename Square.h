#pragma once
#include "Shape.h"
#include <vector>


class Square : public Shape {
private:
public:
	Square();
	Square(const int& Side);
	virtual void Draw() override;
};