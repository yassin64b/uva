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
        int n;
        in >> n;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            string s;
            in >> s;
            if (s == "Tetrahedron") {
                res += 4;
            } else if (s == "Cube") {
                res += 6;
            } else if (s == "Octahedron") {
                res += 8;
            } else if (s == "Dodecahedron") {
                res += 12;
            } else if (s == "Icosahedron") {
                res += 20;
            }
        }
        out << res << "\n";
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
