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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        vector<int> p;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2) {
                p.push_back(i);
            }
        }
        vector<pair<int, int>> dp(n + 1);
        dp[0].first = 1;
        for (int i = 0; i < (int)p.size(); ++i) {
            for (int j = i; j < (int)p.size(); ++j) {
                int len = p[j] - p[i] + 1;
                if (len % 2) {
                    if (dp[p[i]].first) {
                        dp[p[j] + 1].second = 1;
                    }
                    if (dp[p[i]].second) {
                        dp[p[j] + 1].first = 1;
                    }
                }
            }
        }
        out << (dp[n].second == 1 ? "Yes\n" : "No\n");
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
