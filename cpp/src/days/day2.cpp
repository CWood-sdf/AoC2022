#include "day2.h"
#include <fstream>
#include <iostream>

using std::string;
void Day2::init(bool test) {
	loadForDay(2, test);
}
std::string Day2::runPart1() {
	string line = "";
	int points = 0;
	for (char& c : input1) {
		if (c == '\n') {
			points += getPointsFromLine(line);
			line = "";
		} else {
			line += c;
		}
	}
	return std::to_string(points);
}
std::string Day2::runPart2() {
	string line = "";
	int points = 0;
	for (char& c : input1) {
		if (c == '\n') {
            int otherMove = letterToMove(line[0], 'A');
			points += getPointsFromPlay(otherMove, (otherMove + 2 + line[2] - 'X') % 3);
			line = "";
		} else {
			line += c;
		}
	}
	return std::to_string(points);
}
