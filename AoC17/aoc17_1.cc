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

using namespace std;

class aoc17_1 {
public:
    void solve(istream& in, ostream& out) {
        constexpr int step = 370;
        vector<int> cur{0};
        int res = 0;
        for (int i = 1, pos = 0; i <= 2017; ++i) {
            pos = (pos + step) % cur.size() + 1;
            cur.insert(cur.begin() + pos, i);
            res = cur[(pos + 1) % cur.size()];
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    aoc17_1 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}