#include "day4.h"
#include <cstdint>
#include <iostream>
using std::string;
void Day4::init(bool test) {
	loadForDay(4, test);
}
std::string Day4::runPart1() {
	int count = 0;
	string line = "";
	for (char& c : input1) {
		if (c == '\n') {
			int leftMin = 0;
			int leftMax = 0;
			int rightMin = 0;
			int rightMax = 0;
			int last = 0;
			int current = line.find('-');
			leftMin = atoi(line.substr(last, current - last).c_str());
			last = current + 1;
			current = line.find(',', last);
			leftMax = atoi(line.substr(last, current - last).c_str());
			last = current + 1;
			current = line.find('-', last);
			rightMin = atoi(line.substr(last, current - last).c_str());
			last = current + 1;
			current = line.size();
			rightMax = atoi(line.substr(last, current - last).c_str());
			if ((leftMin <= rightMin && rightMax <= leftMax) ||
				(leftMin >= rightMin && rightMax >= leftMax)) {
				count++;
			}
			line = "";
		} else {
			line += c;
		}
	}
	return std::to_string(count);
}
std::string Day4::runPart2() {
	int count = 0;
	string line = "";
	for (char& c : input1) {
		if (c == '\n') {
			int leftMin = 0;
			int leftMax = 0;
			int rightMin = 0;
			int rightMax = 0;
			int last = 0;
			int current = line.find('-');
			leftMin = atoi(line.substr(last, current - last).c_str());
			last = current + 1;
			current = line.find(',', last);
			leftMax = atoi(line.substr(last, current - last).c_str());
			last = current + 1;
			current = line.find('-', last);
			rightMin = atoi(line.substr(last, current - last).c_str());
			last = current + 1;
			current = line.size();
			rightMax = atoi(line.substr(last, current - last).c_str());
            if((leftMin >= rightMin && leftMin <= rightMax) || (leftMax >= rightMin && leftMax <= rightMax) ||
               (rightMin >= leftMin && rightMin <= leftMax) || (rightMax >= leftMin && rightMax <= leftMax)) {
                count++;
            }
			line = "";
		} else {
			line += c;
		}
	}
	return std::to_string(count);
}
