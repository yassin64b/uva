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

class A467 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int p, q;
            in >> p >> q;
            res += (p + 2 <= q);
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A467 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}