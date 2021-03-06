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
        int n;
        in >> n;
        int ans = -1'000'000;
        for (int i = 0; i < n; ++i) {
            int a;
            in >> a;
            if (a < 0) {
                ans = max(ans, a);
            } else {
                int b = sqrt(a);
                if (b * b == a || (b - 1) * (b - 1) == a || (b + 1) * (b + 1) == a) {
                
                } else {
                    ans = max(ans, a);
                }
            }
        }
        out << ans << "\n";
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
