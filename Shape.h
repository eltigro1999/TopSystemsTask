#pragma once

class Shape {
protected:
	int x = 0;
	int y = 0;
public:
	Shape();
	virtual void Draw()=0;
};