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

class C350 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        int k = 0;
        string res;
        vector<pair<int, int>> xy(n);
        for (int i = 0; i < n; ++i) {
            in >> xy[i].first >> xy[i].second;
        }
        sort(xy.begin(), xy.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return abs(lhs.first) + abs(lhs.second) < abs(rhs.first) + abs(rhs.second);
        });
        
        for (int i = 0; i < n; ++i) {
            int x = xy[i].first, y = xy[i].second;
            if (x > 0) {
                ++k;
                res += "1 " + to_string(x-0) + " R\n";
            } else if (x < 0) {
                ++k;
                res += "1 " + to_string(0-x) + " L\n";
            }
            if (y > 0) {
                ++k;
                res += "1 " + to_string(y-0) + " U\n";
            } else if (y < 0) {
                ++k;
                res += "1 " + to_string(0-y) + " D\n";
            }
            ++k;
            res += "2\n";
            if (x > 0) {
                ++k;
                res += "1 " + to_string(x-0) + " L\n";
            } else if (x < 0) {
                ++k;
                res += "1 " + to_string(0-x) + " R\n";
            }
            if (y > 0) {
                ++k;
                res += "1 " + to_string(y-0) + " D\n";
            } else if (y < 0) {
                ++k;
                res += "1 " + to_string(0-y) + " U\n";
            }
            ++k;
            res += "3\n";
        }
        out << k << "\n" << res;
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    C350 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
