#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }
    vector<vector<int>> off(n);
    for (int i = 0; i < m; ++i) {
        int d, t;
        cin >> d >> t;
        --d;
        --t;
        off[t].push_back(d);
    }
    for (auto &v : off) {
        sort(begin(v), end(v));
    }
    constexpr int INF = 400'001;
    int low = 0, high = INF, ans = INF;
    while (low <= high) {
        int mid = (low + high) / 2;
        vector<pair<int, int>> cur_off;
        for (int i = 0; i < n; ++i) {
            // get last offer that's in [0, mid] for each type
            auto it = upper_bound(begin(off[i]), end(off[i]), mid);
            if (it != begin(off[i])) {
                cur_off.emplace_back(*--it, i);
            }
        }
        sort(begin(cur_off), end(cur_off));
        vector<int> cur_k(k);
        int cur_money = 1, cur_d = 0;
        for (const auto &[d, t] : cur_off) {
            // try to use last offers in order of days
            cur_money += (d - cur_d);
            cur_d = d;
            int cnt = min(cur_k[t], cur_money);
            cur_k[t] -= cnt;
            cur_money -= cnt;
        }
        cur_money += (mid - cur_d);
        for (int i = 0; i < n; ++i) {
            // buy types unsatisfied by offers on the last day (mid)
            cur_money -= cur_k[i] * 2;
        }
        if (cur_money >= 0) {
            high = mid - 1;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << ans + 1 << "\n";

    return 0;
}