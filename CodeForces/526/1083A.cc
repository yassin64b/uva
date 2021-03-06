#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class TaskA {
private:
    void dfs(int u, const vector<vector<pair<int, int>>> &g, vector<int> &vis,
                vector<pair<i64, i64>> &dp, const vector<int> &w)
    {
        vis[u] = 1;
        dp[u] = {w[u], w[u]};
        i64 mx1 = 0, mx2 = 0;
        for (auto [v, c] : g[u]) {
            if (!vis[v]) {
                dfs(v, g, vis, dp, w);
                dp[u].first = max(dp[u].first, dp[v].first - c + w[u]);
                if (dp[v].first - c > mx1) {
                    mx2 = mx1;
                    mx1 = dp[v].first - c;
                } else if (dp[v].first - c > mx2) {
                    mx2 = dp[v].first - c;
                }
            }
        }
        dp[u].second = max(dp[u].second, mx1 + mx2 + w[u]);
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> w(n);
        for (int i = 0; i < n; ++i) {
            in >> w[i];
        }
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v, c;
            in >> u >> v >> c;
            g[u - 1].emplace_back(v - 1, c);
            g[v - 1].emplace_back(u - 1, c);
        }
        vector<int> vis(n, 0);
        vector<pair<i64, i64>> dp(n, {0, 0});
        dfs(0, g, vis, dp, w);
        i64 res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, max(dp[i].first, dp[i].second));
        }
        out << res << "\n";
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
