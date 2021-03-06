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

class B479 {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        
        vector<pair<int, int>> res;
        for (int m = 1; m <= k; ++m) {
            auto mx = max_element(a.begin(), a.end());
            auto mn = min_element(a.begin(), a.end());
            if (*mn + 1 < *mx) {
                *mx -= 1;
                *mn += 1;
                res.emplace_back(mx - a.begin(), mn - a.begin());
            } else {
                break;
            }
        }
        out << *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
        out << " " << res.size() << "\n";
        for (auto& p : res) {
            out << p.first + 1 << " " << p.second + 1 << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    B479 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
