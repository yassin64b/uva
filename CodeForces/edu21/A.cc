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
        string s(to_string(n));
        if (s[0] == '9') {
            s = "1" + s;
        } else {
            ++s[0];
        }
        for (int i = 1; i < (int)s.size(); ++i) {
            s[i] = '0';
        }
        assert(stoi(s) > n);
        out << stoi(s) - n << "\n";
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
