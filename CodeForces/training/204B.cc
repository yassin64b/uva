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

class B204 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<pair<int, int>> cards(n);
        for (int i = 0; i < n; ++i) {
            in >> cards[i].first >> cards[i].second;
        }
        
        map<int, pair<int, int>> m;
        for (int i = 0; i < n; ++i) {
            ++m[cards[i].first].first;
            if (cards[i].second != cards[i].first) {
                ++m[cards[i].second].second;
            }
        }
        
        int mn = 1000 * 1000 * 1000;
        for (const auto& pp : m) {
            const auto& p = pp.second;
            if (2 * (p.first + p.second) >= n) { //can make funny with pp.first
                mn = min(mn, max((n + 1 - 2 * p.first) / 2, 0));
                //cout << pp.first << " " << max(n - 2 * p.first, 0) << endl;
            }
        }
        if (mn != 1000 * 1000 * 1000) {
            out << mn << "\n";
        } else {
            out << -1 << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    B204 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
