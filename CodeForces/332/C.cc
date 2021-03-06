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

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            in >> h[i];
        }
        vector<int> mn(n + 1);
        mn[n] = 1000 * 1000 * 1000 + 10;
        for (int i = n - 1; i >= 0; --i) {
            mn[i] = min(mn[i + 1], h[i]);
        }
        
        int mx = h[0], num = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, h[i]);
            if (mx <= mn[i + 1]) {
                ++num;
            }
        }
        out << num << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
