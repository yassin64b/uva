#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n;
        string s;
        in >> n >> s;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        constexpr long long INF = 100'000'000'000'000;
        map<char, int> ind{{'h', 1}, {'a', 2}, {'r', 3}, {'d', 4}};
        vector<vector<long long>> dp(n + 1, vector<long long>(5, INF));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            int j = -1;
            if (ind.count(s[i])) {
                j = ind[s[i]];
                dp[i + 1][j] = min(dp[i][j], dp[i][j - 1]);
                dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j - 1] + a[i]);
            }
            for (int k = 0; k < 5; ++k) {
                if (k != j && k != j - 1) {
                    dp[i + 1][k] = min(dp[i + 1][k], dp[i][k]);
                }
            }
        }
        out << min(dp[n][0], min(dp[n][1], min(dp[n][2], dp[n][3]))) << "\n";
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
