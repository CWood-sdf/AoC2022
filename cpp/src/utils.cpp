#include "utils.h"
#include <cmath>

using std::pow;
using std::size_t;
using std::string;
int stringToInt(const std::string& str) {
	int num = 0;
	for (size_t i = 0; i < str.size(); ++i) {
		num += (str[i] - '0') * pow(10, str.size() - i - 1);
	}
	return num;
}
