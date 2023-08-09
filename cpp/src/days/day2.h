#include "../Day.h"

class Day2 : public AoCSolution {
	int letterToMove(char letter, char base) {
		return letter - base;
	}

	int points[3] = {1, 2, 3};

	int getPointsFromPlay(int other, int you) {
        //basically getting points from winning looks like this:
        // you win if your number is 1 greater than the other number (on the mod 3 circle)
        // you lose if your number is 1 less than the other number (on the mod 3 circle)
        // we need you to get 0 points if you lose, 3 if tie, 6 if win
        // so what im adding 3 bc i dont want negative mod, and the add 1 makes sense if u think abt it
		return points[you] + ((you + 1 - other + 3) % 3) * 3;
	}
    int getPointsFromLine(std::string line) {
        if(line.size() < 3) {
            return 0;
        }
        return getPointsFromPlay(letterToMove(line[0], 'A'), letterToMove(line[2], 'X'));
    }

public:
	~Day2() = default;
	void init(bool test = false);
	std::string runPart1();
	std::string runPart2();
};
