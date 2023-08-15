#include "days.h"
#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>
using std::size_t;
using std::string;
int main() {
	std::cout << (int)('v' - 'a') << std::endl;
	AoCSolution* solution = new Day7();
	solution->init(false);
	auto start = std::chrono::high_resolution_clock::now();
	string part1 = solution->runPart1();
	auto end = std::chrono::high_resolution_clock::now();
	auto duration =
		std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Part 1: " << part1 << std::endl;
	std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
	start = std::chrono::high_resolution_clock::now();
	string part2 = solution->runPart2();
	end = std::chrono::high_resolution_clock::now();
	duration =
		std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Part 2: " << part2 << std::endl;
	std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
	delete solution;
	return 0;
}
