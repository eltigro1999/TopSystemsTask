
#include <map>
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Circle.h"
using namespace std;

void multiply(std::vector<std::pair<int, int>>& vec, const int& xMultiplyer, const int& yMultiplyer);

void fillCircle(std::map<int, std::vector<int>>& circle, const std::vector<std::pair<int, int>>& quarter);

void DrawCircle(const std::map<int, std::vector<int>>& Circle);

int radius;

int main()
{
	std::vector<std::pair<int, int>> firstQuarter;
	radius = 10;
	int x = 0;
	int y = radius;
	int d = 3 - 2 * radius;
	firstQuarter.push_back(std::pair<int, int>(x, y));
	while (x <= y) {
		if (d <= 0) {
			x += 1;
			d = d + 4 * x + 6;
		}
		else {
			y -= 1;
			x += 1;
			d =d+ 4 * (x-y)+10;
		}
		firstQuarter.push_back(std::pair<int, int>(x, y));
	}
	std::vector<std::pair<int, int>> firstQuarterEnding(firstQuarter.rbegin(), firstQuarter.rend());
	for (int i = 0; i < firstQuarterEnding.size(); ++i) {
		std::swap(firstQuarterEnding[i].first, firstQuarterEnding[i].second);
	}
	firstQuarterEnding.erase(firstQuarterEnding.begin());
	firstQuarter.insert(firstQuarter.end(), firstQuarterEnding.begin(), firstQuarterEnding.end());
	std::vector<std::pair<int, int>> secondQuarter = firstQuarter;
	std::vector<std::pair<int, int>> thirdQuarter = firstQuarter;
	std::vector<std::pair<int, int>> fourthQuarter = firstQuarter;
	multiply(secondQuarter, 1, -1);
	multiply(thirdQuarter, -1, -1);
	multiply(fourthQuarter, -1, 1);
	std::map<int, std::vector<int>> circle;
	fillCircle(circle, firstQuarter);
	fillCircle(circle, secondQuarter);
	fillCircle(circle, thirdQuarter);
	fillCircle(circle, fourthQuarter);
	for (auto& yArguments : circle) {
		std::sort(yArguments.second.begin(), yArguments.second.end());
	}
	DrawCircle(circle);

}

void multiply(std::vector<std::pair<int, int>>& vec, const int& xMultiplyer, const int& yMultiplyer) {
	for (auto& coords : vec) {
		coords.first *= xMultiplyer;
		coords.second *= yMultiplyer;
	}
}

void fillCircle(std::map<int, std::vector<int>>& circle, const std::vector<std::pair<int, int>>& quarter) { 
	for (const auto& coords : quarter) {
		circle[coords.second].push_back(coords.first);
	}
}

void DrawCircle(const std::map<int, std::vector<int>>& Circle) {
	int CircleSize = Circle.size();
	for (const auto& y : Circle) {
		//CircleSize/2=radius
		for (int x = -radius; x < CircleSize; ++x) {
			if (std::find(y.second.begin(), y.second.end(), x) != y.second.end()) {
				std::cout << "+";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}