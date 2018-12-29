#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 calc_sum(const vector<deque<int>> &q) {
    int m = q.size();
    i64 sum = 0;
    for (int i = 0; i < m; ++i) {
        if (!q[i].empty()) {
            sum += q[i].front();
        }
    }
    return sum;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> droid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> droid[i][j];
        }
    }

    int mx_len = 0, start_ind = 0, end_ind = 0;
    vector<deque<int>> mx(m);
    for (int i = 0, j = 0; j < n; ++i) {
        i64 sum = calc_sum(mx);
        while (j < n && sum <= k) {
            for (int a = 0; a < m; ++a) {
                while (!mx[a].empty() && mx[a].back() < droid[j][a]) {
                    mx[a].pop_back();
                }
                mx[a].push_back(droid[j][a]);
            }
            sum = calc_sum(mx);
            ++j;
        }
        int cur_start_ind = i, cur_end_ind = j - (sum > k);
        int cur_len = cur_end_ind - cur_start_ind;
        if (cur_len > mx_len) {
            mx_len = cur_len;
            start_ind = cur_start_ind;
            end_ind = cur_end_ind;
        }
        for (int a = 0; a < m; ++a) {
            if (mx[a].front() == droid[i][a]) {
                mx[a].pop_front();
            }
        }
    }
    vector<int> res(m, 0);
    for (int i = start_ind; i < end_ind; ++i) {
        for (int j = 0; j < m; ++j) {
            res[j] = max(res[j], droid[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}