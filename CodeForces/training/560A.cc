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

class A560 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        bool one = false;
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            one = (one || a[i] == 1);
        }
        out << (one ? -1 : 1) << "\n";
        /*constexpr int MXV = 2'000'000;
        vector<int> dp(MXV + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j + a[i] <= MXV; ++j) {
                if (dp[j]) {
                    dp[j + a[i]] = 1;
                }
            }
        }
        for (int i = 0; i <= MXV; ++i) {
            if (!dp[i]) {
                out << i << "\n";
                return;
            }
        }
        out << -1 << "\n";*/
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A560 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}