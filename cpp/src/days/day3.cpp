#include "day3.h"
#include <cstdint>
#include <iostream>
using std::string;
void Day3::init(bool test) {
	loadForDay(3, test);
}
int getShiftFromChar(char c) {
	int ret = 0;
	if (c >= 'A' && c <= 'Z') {
		ret = c - 'A' + 26;
	} else {
		ret = c - 'a';
	}
	if (ret < 0 || ret > 51) {
		std::cout << "ERROR: " << c << " " << ret << std::endl;
	}
	return ret;
}
int getShiftFromMasks(uint64_t oldMask, uint64_t mask) {
	uint64_t maskVal = oldMask ^ mask;
	int shift = 1;
	while (maskVal != 1) {
		maskVal >>= 1;
		shift++;
	}
	return shift;
}
std::string Day3::runPart1() {
	string line = "";
	int prioritySum = 0;
	for (char& c : input1) {
		if (c == '\n') {
			int halfLen = line.size() / 2;
			if (line.size() % 2 == 1) {
				return "ERROR: Odd length";
			}
			uint64_t mask = 0;
			uint64_t maskLeft = 0;
			uint64_t maskRight = 0;
			for (int i = 0; i < halfLen; i++) {
				char left = line[i];
				char right = line[i + halfLen];
				uint64_t oldMask = mask;
				uint64_t addLeft = static_cast<uint64_t>(1)
				                   << getShiftFromChar(left);
				// basically if this char hasnt been seen yet, add it to the
				// mask
				if ((maskLeft & addLeft) == 0) {
					maskLeft += addLeft;
					mask ^= addLeft;
				}
				if (mask < oldMask) {
					prioritySum += getShiftFromMasks(oldMask, mask);
					break;
				}
				oldMask = mask;
				uint64_t addRight = static_cast<uint64_t>(1)
				                    << getShiftFromChar(right);
				if ((maskRight & addRight) == 0) {
					maskRight += addRight;
					mask ^= addRight;
				}
				if (mask < oldMask) {
					prioritySum += getShiftFromMasks(oldMask, mask);
					break;
				}
			}
			line = "";
		} else {
			line += c;
		}
	}
	return std::to_string(prioritySum);
}
std::string Day3::runPart2() {
	string lineBuffer[3] = {"", "", ""};
	int i = 0;
	string line = "";
	int prioritySum = 0;
	for (char& c : input1) {
		if (c == '\n') {
			uint64_t mask1 = 0;
			uint64_t mask2 = 0;
			uint64_t masks[3] = {0, 0, 0};
			lineBuffer[i % 3] = line;
			line = "";

			if (i % 3 == 2) {
				bool found = false;
				for (int i = 0; i < 3; i++) {
					for (char& c2 : lineBuffer[i]) {
						uint64_t add = static_cast<uint64_t>(1)
						               << getShiftFromChar(c2);
						if ((masks[i] & add) == 0) {
							masks[i] += add;
							mask2 += mask1 & add;
							mask1 ^= add;
						}
						if ((mask1 & mask2) != 0) {
							prioritySum += getShiftFromMasks(add, 0);
							found = true;
							break;
						}
					}
					if (found) {
						break;
					}
				}
			}
            i++;
		} else {
			line += c;
		}
	}
	return std::to_string(prioritySum);
}
