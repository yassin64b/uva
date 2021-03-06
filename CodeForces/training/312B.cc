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

class B312 {
public:
    void solve(istream &in, ostream &out) {
        int a, b, c, d;
        in >> a >> b >> c >> d;
        double p1 = a / (double) b, p2 = c / (double) d;
        double ans = 0, cur = 1;
        while (cur >= 0.00000000001) {
            ans += cur * p1;
            cur *= (1 - p1);
            cur *= (1 - p2);
        }
        out.precision(17);
        out << fixed << ans << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    B312 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
