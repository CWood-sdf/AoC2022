#include <fstream>
#include <string>
class AoCSolution {
protected:
	std::string input1;
	std::string input2;
	void loadForDay(int day) {
		input1 = loadFile(day, 1);
		input2 = loadFile(day, 2);
	}
	std::string loadFile(int day, int part) {
		std::string filename = "../input" + std::to_string(day) + "." +
		                       std::to_string(part) + ".txt";
		std::ifstream file(filename);
		std::string input;
		if (file.is_open()) {
			std::string line;
			while (getline(file, line)) {
				input += line + "\n";
			}
			file.close();
		}
		return input;
	}

public:
    virtual ~AoCSolution() = default;
	virtual void init() = 0;
	virtual std::string runPart1() = 0;
	virtual std::string runPart2() = 0;
};
