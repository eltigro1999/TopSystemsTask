#pragma once
#include "Shape.h"
#include <map>
#include <vector>
#include <algorithm>

class Circle: public Shape{
	//algortithm to make a circle
	std::map<int, std::vector<int>> BresenhamAlgorithm();

	std::map<int, std::vector<int>> circle;
	void multiply(std::vector<std::pair<int, int>>& vec, const int& xMultiplyer, const int& yMultiplyer);
	void fillCircle(std::map<int, std::vector<int>>& circle, const std::vector<std::pair<int, int>>& quarter);
	int radius;
public:
	Circle();
	Circle(const int& radius);
	void Draw() override;
};
