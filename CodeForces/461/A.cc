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

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int x, y;
        in >> x >> y;
        if (y == 0) {
            out << "No\n";
            return;
        }
        int num = y - 1;
        if (num > x || (num == 0 && x > 0)) {
            out << "No\n";
        } else {
            int diff = x - num;
            if (diff % 2 != 0) {
                out << "No\n";
            } else {
                out << "Yes\n";
            }
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
