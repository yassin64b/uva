#include <bits/stdc++.h>

using namespace std;

vector<int> kmp_preprocess(const string &s) {
    int n = s.size();
    vector<int> b(n + 1);
    int i = 0, j = -1;
    b[0] = -1;
    while (i < n) {
        while (j >= 0 && s[i] != s[j]) {
            j = b[j];
        }
        ++i; ++j;
        b[i] = j;
    }
    return b;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    constexpr int MOD = 1'000'000'007;

    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    t += "#" + s;
    vector<int> b = kmp_preprocess(t);
    b = vector<int>(begin(b) + m + 2, end(b));
    vector<int> dp(n + 1, 0), dp_sum(n + 1, 0), dp_sum_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        if (b[i] == m) {
            int start_ind = i - m + 1;
            dp[i + 1] = (dp_sum_sum[start_ind] + start_ind + 1) % MOD;
        } else {
            dp[i + 1] = dp[i];
        }
        dp_sum[i + 1] = (dp_sum[i] + dp[i + 1]) % MOD;
        dp_sum_sum[i + 1] = (dp_sum_sum[i] + dp_sum[i + 1]) % MOD;
    }

    cout << dp_sum[n] << "\n";


    return 0;
}