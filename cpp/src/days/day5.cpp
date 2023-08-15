#include "day5.h"
#include <vector>
using std::string;
using std::vector;
void Day5::init(bool test) {
	loadForDay(5, test);
}
string Day5::runPart1() {
	std::vector<string> lines = {};
	string line = "";
	size_t neededSize = 0;
	size_t currentStringIndex = 0;
	for (char& c : input1) {
		if (c == '\n') {
			lines.push_back(line);
			if ((line.size() + 1) / 4 > neededSize) {
				neededSize = (line.size() + 1) / 4;
			}
			line = "";
		} else {
			line += c;
			if (line.size() == 2 && line[1] == '1') {
				break;
			}
		}
		currentStringIndex++;
	}
	vector<vector<char>> spots = {};
	for (size_t i = 0; i < neededSize; i++) {
		spots.push_back({});
	}
	for (int i = lines.size() - 1; i >= 0; i--) {
		for (size_t j = 1; j < lines[i].size(); j += 4) {
			if (lines[i][j] == ' ') {
				continue;
			}
			spots[j / 4].push_back(lines[i][j]);
		}
	}
	// now load moves
	while (input1[currentStringIndex] != '\n') {
		currentStringIndex++;
	}
	currentStringIndex += 2;
	line = "";
	while (currentStringIndex < input1.size()) {
		char c = input1[currentStringIndex];
		if (c == '\n') {
			int count = 0;
			int start = 0;
			int end = 0;
			size_t i = 0;
			while (line[i] != ' ') {
				i++;
			}
			i++;
			size_t oldI = i;
			while (line[i] != ' ') {
				i++;
			}
			i++;
			count = std::stoi(line.substr(oldI, i - oldI - 1));
			while (line[i] != ' ') {
				i++;
			}
			i++;
			oldI = i;
			while (line[i] != ' ') {
				i++;
			}
			i++;
			start = std::stoi(line.substr(oldI, i - oldI - 1)) - 1;
			while (line[i] != ' ') {
				i++;
			}
			i++;
			oldI = i;
			while (i < line.size()) {
				i++;
			}
			end = std::stoi(line.substr(oldI, i - oldI)) - 1;
			while (count > 0) {
				char c = spots[start].back();
				spots[start].pop_back();
				spots[end].push_back(c);
				count--;
			}

			line = "";
		} else {
			line += c;
		}
		currentStringIndex++;
	}
	string ret = "";
	for (size_t i = 0; i < spots.size(); i++) {
		ret += spots[i].back();
	}
	return ret;
}
string Day5::runPart2() {
	std::vector<string> lines = {};
	string line = "";
	size_t neededSize = 0;
	size_t currentStringIndex = 0;
	for (char& c : input1) {
		if (c == '\n') {
			lines.push_back(line);
			if ((line.size() + 1) / 4 > neededSize) {
				neededSize = (line.size() + 1) / 4;
			}
			line = "";
		} else {
			line += c;
			if (line.size() == 2 && line[1] == '1') {
				break;
			}
		}
		currentStringIndex++;
	}
	vector<vector<char>> spots = {};
	for (size_t i = 0; i < neededSize; i++) {
		spots.push_back({});
	}
	for (int i = lines.size() - 1; i >= 0; i--) {
		for (size_t j = 1; j < lines[i].size(); j += 4) {
			if (lines[i][j] == ' ') {
				continue;
			}
			spots[j / 4].push_back(lines[i][j]);
		}
	}
	// now load moves
	while (input1[currentStringIndex] != '\n') {
		currentStringIndex++;
	}
	currentStringIndex += 2;
	line = "";
	while (currentStringIndex < input1.size()) {
		char c = input1[currentStringIndex];
		if (c == '\n') {
			int count = 0;
			int start = 0;
			int end = 0;
			size_t i = 0;
			while (line[i] != ' ') {
				i++;
			}
			i++;
			size_t oldI = i;
			while (line[i] != ' ') {
				i++;
			}
			i++;
			count = std::stoi(line.substr(oldI, i - oldI - 1));
			while (line[i] != ' ') {
				i++;
			}
			i++;
			oldI = i;
			while (line[i] != ' ') {
				i++;
			}
			i++;
			start = std::stoi(line.substr(oldI, i - oldI - 1)) - 1;
			while (line[i] != ' ') {
				i++;
			}
			i++;
			oldI = i;
			while (i < line.size()) {
				i++;
			}
			end = std::stoi(line.substr(oldI, i - oldI)) - 1;
			while (count > 0) {
				char c = spots[start][spots[start].size() - count];
				spots[end].push_back(c);
				spots[start][spots[start].size() - count] = ' ';
				count--;
			}
			while (spots[start].size() > 0 && spots[start].back() == ' ') {
				spots[start].pop_back();
			}

			line = "";
		} else {
			line += c;
		}
		currentStringIndex++;
	}
	string ret = "";
	for (size_t i = 0; i < spots.size(); i++) {
		ret += spots[i].back();
	}
	return ret;
}
