#include <iostream>
#include <vector>

using namespace std;

class BowlingGame {
    vector<int> rolls;

public:
    void roll(int pins) {
        rolls.push_back(pins);
    }

    int score() {
        int totalScore = 0;
        int rollIndex = 0;

        for (int frame = 0; frame < 10; ++frame) {
            if (rolls[rollIndex] == 10) {
                totalScore += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
                rollIndex += 1;
            } else if (rolls[rollIndex] + rolls[rollIndex + 1] == 10) {
                totalScore += 10 + rolls[rollIndex + 2];
                rollIndex += 2;
            } else {
                totalScore += rolls[rollIndex] + rolls[rollIndex + 1];
                rollIndex += 2;
            }
        }

        return totalScore;
    }
};

int main() {
    BowlingGame game;
    vector<int> inputs = {5, 4, 5, 5, 10, 6, 1, 9, 1, 10, 10, 10, 2, 6, 6, 2};

    for (int pins : inputs) {
        game.roll(pins);
    }

    cout << game.score() << endl;

    return 0;
}
