/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author yassin
 */

#include <fstream>

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <tuple>
#include <queue>
#include <functional>
#include <stack>
#include <numeric>
#include <cassert>
#include <sstream>

using namespace std;

class aoc25_1 {
private:
    static constexpr int NUM_IT = 12134527;
public:
    void solve(istream& in, ostream& out) {
        vector<int> tape(2 * NUM_IT + 1, 0);
        char state = 'A';
        
        for (int i = 0, j = NUM_IT; i < NUM_IT; ++i) {
            if (state == 'A') {
                if (tape[j] == 0) {
                    tape[j++] = 1;
                    state = 'B';
                } else {
                    tape[j--] = 0;
                    state = 'C';
                }
            } else if (state == 'B') {
                if (tape[j] == 0) {
                    tape[j--] = 1;
                    state = 'A';
                } else {
                    tape[j++] = 1;
                    state = 'C';
                }
            } else if (state == 'C') {
                if (tape[j] == 0) {
                    tape[j++] = 1;
                    state = 'A';
                } else {
                    tape[j--] = 0;
                    state = 'D';
                }
            } else if (state == 'D') {
                if (tape[j] == 0) {
                    tape[j--] = 1;
                    state = 'E';
                } else {
                    tape[j--] = 1;
                    state = 'C';
                }
            } else if (state == 'E') {
                if (tape[j] == 0) {
                    tape[j++] = 1;
                    state = 'F';
                } else {
                    tape[j++] = 1;
                    state = 'A';
                }
            } else if (state == 'F') {
                if (tape[j] == 0) {
                    tape[j++] = 1;
                    state = 'A';
                } else {
                    tape[j++] = 1;
                    state = 'E';
                }
            } else {
                assert(false);
            }
        }
        
        out << accumulate(tape.begin(), tape.end(), 0) << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    aoc25_1 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
