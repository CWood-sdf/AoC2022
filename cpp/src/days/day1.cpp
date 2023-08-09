#include "day1.h"
#include "../utils.h"
#include <iostream>
#include <vector>
using std::string;
void Day1::init(bool test) {
	loadForDay(1, test);
}
string Day1::runPart1() {
	int currentMax = 0;
	string temp = "";
	int currentValue = 0;
	for (char& c : input1) {
		if (c == '\n') {
			if (temp != "") {
				currentValue += stringToInt(temp);
				temp = "";
			} else {
				if (currentValue > currentMax) {
					currentMax = currentValue;
				}
				currentValue = 0;
			}

		} else {
			temp += c;
		}
	}
	return std::to_string(currentMax);
}
string Day1::runPart2() {
	static const size_t maxValsSize = 3;
	int maxVals[maxValsSize] = {0, 1, 2};
    maxVals[0] = 0;
    maxVals[1] = 1;
    maxVals[2] = 2;
	string temp = "";
	int currentValue = 0;
	for (char& c : input1) {
		if (c == '\n') {
			if (temp != "") {
				currentValue += stringToInt(temp);
				temp = "";
			} else {
				for (int i = maxValsSize - 1; i >= 0; i--) {
					if (currentValue > maxVals[i]) {
						for (int j = 0; j < i; j++) {
							maxVals[j] = maxVals[j + 1];
						}
						maxVals[i] = currentValue;
						break;
					}
				}
				currentValue = 0;
			}

		} else {
			temp += c;
		}
	}
	int currentMax = 0;
	for (size_t i = 0; i < maxValsSize; i++) {
		currentMax += maxVals[i];
	}
	return std::to_string(currentMax);
}
