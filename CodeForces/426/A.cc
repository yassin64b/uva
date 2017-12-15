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

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        char start, end;
        int n;
        in >> start >> end >> n;
        n %= 4;
        char spin[4]{'v', '<', '^', '>'};
        int pos_start = find(spin, spin + 4, start) - spin;
        int pos_end = find(spin, spin + 4, end) - spin;
        if (n == 0 || n == 2) {
            out << "undefined\n";
        } else {
            if ((pos_end - pos_start + 4) % 4 == n) {
                out << "cw\n";
            } else {
                out << "ccw\n";
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