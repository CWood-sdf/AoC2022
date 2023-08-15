
#include "day6.h"
#include <vector>
using std::string;
void Day6::init(bool test) {
	loadForDay(6, test);
}
template <typename T>
concept Integral = std::is_integral_v<T>;
template <Integral T> size_t countOnes(T number) {
	size_t count = 0;
	while (number) {
		count += number & 1;
		number >>= 1;
	}
	return count;
}
string Day6::runPart1() {
	for (size_t i = 0; i < input1.size(); i++) {
		int32_t number = 0;
		for (size_t j = i; j < i + 4; j++) {
			number ^= 1 << (input1[j] - 'a');
		}
		if (countOnes(number) == 4) {
			return std::to_string(i + 4);
		}
	}
	return "";
}
string Day6::runPart2() {
	for (size_t i = 0; i < input1.size(); i++) {
		int32_t number = 0;
		for (size_t j = i; j < i + 14; j++) {
			if (number & (1 << (input1[j] - 'a'))) {
				break;
			}
			number ^= 1 << (input1[j] - 'a');
		}
		if (countOnes(number) == 14) {
			return std::to_string(i + 14);
		}
	}
	return "";
}
