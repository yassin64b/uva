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
        int l, r, x, y, k;
        in >> l >> r >> x >> y >> k;
        for (int a = l; a <= r; ++a) {
            if (a % k == 0 && a / k >= x && a / k <= y) {
                out << "YES\n";
                return;
            }
        }
        out << "NO\n";
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
