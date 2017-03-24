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
#include <cassert>

using namespace std;

constexpr int MOD = 1000 * 1000 * 1000 + 7;

class C431 {
public:
    void solve(istream &in, ostream &out) {
        int n, k, d;
        in >> n >> k >> d;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (i+j <= n) {
                    if (j < d) {
                        dp[i+j][0] += dp[i][0];
                        dp[i+j][0] %= MOD;
                    } else {
                        dp[i+j][1] += dp[i][0];
                        dp[i+j][1] %= MOD;
                    }
                    dp[i+j][1] += dp[i][1];
                    dp[i+j][1] %= MOD;
                }
            }
        }
        
        out << dp[n][1] << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    C431 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}