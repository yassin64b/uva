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

constexpr int INF = 1000 * 1000 * 1000;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n, K, m;
        in >> n >> K >> m;
        vector<vector<pair<int, int>>> g(n+1);
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            in >> u >> v >> c;
            g[u].emplace_back(v, c);
        }

        vector<vector<vector<pair<int, int>>>> dp(n+2, vector<vector<pair<int, int>>>(n+2, vector<pair<int, int>>(K+1, {INF, INF})));
        //dp[i][j][k] = min. cost visiting k offices, all between (i, j) unvisited
        //first -> at i; second -> at j currently
        for (int i = 1; i <= n; ++i) {
            dp[i][n+1][1].first = 0;
            dp[0][i][1].second = 0;
        }
        
        for (int x = 0; x <= n+3; ++x) {
            for (int i = 0; i <= n+1; ++i) {
                for (int j = i; j <= n+1; ++j) {
                    for (int k = 1; k < K; ++k) {
                        if (dp[i][j][k].first != INF) {
                            assert(i > 0);
                            for (const pair<int, int>& p : g[i]) {
                                if (p.first > i && p.first < j) {
                                    dp[i][p.first][k+1].second = min(dp[i][p.first][k+1].second, dp[i][j][k].first + p.second);
                                    dp[p.first][j][k+1].first = min(dp[p.first][j][k+1].first, dp[i][j][k].first + p.second);
                                }
                            }
                        }
                        if (dp[i][j][k].second != INF) {
                            assert(j <= n);
                            for (const pair<int, int>& p : g[j]) {
                                if (p.first > i && p.first < j) {
                                    dp[p.first][j][k+1].first = min(dp[p.first][j][k+1].first, dp[i][j][k].second + p.second);
                                    dp[i][p.first][k+1].second = min(dp[i][p.first][k+1].second, dp[i][j][k].second + p.second);
                                }
                            }
                        }
                    }
                }
            }
        }
        
        
        int mn = INF;
        for (int i = 0; i <= n+1; ++i) {
            for (int j = i; j <= n+1; ++j) {
                mn = min(mn, min(dp[i][j][K].first, dp[i][j][K].second));
            }
        }
        if (mn == INF) {
            out << -1 << "\n";
        } else {
            out << mn << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
