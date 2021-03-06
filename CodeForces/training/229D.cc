#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    constexpr i64 INF = 1'000'000'000'000'000;
    vector<vector<i64>> dp(n + 1, vector<i64>(n + 1, INF));
    // dp[i][k] = minimum last element having made at least k intervals upto index i
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        int k = 0;
        i64 sum = 0;
        for (int j = i; j < n; ++j) {
            sum += h[j];
            while (dp[i][k + 1] <= sum) {
                ++k;
            }
            if (dp[i][k] <= sum) {
                dp[j + 1][k + 1] = min(dp[j + 1][k + 1], sum);
            }
        }
        for (k = n - 1; k >= 0; --k) {
            dp[i + 1][k] = min(dp[i + 1][k], dp[i + 1][k + 1]);
        }
    }

    for (int k = n; k >= 1; --k) {
        if (dp[n][k] != INF) {
            cout << n - k << "\n";
            return 0;
        }
     }   

    return 0;
}