#include <bits/stdc++.h>

using namespace std;

void remove(int a, vector<int> &cnt, int &sum, const vector<int> &needx) {
    sum -= (cnt[a] == needx[a]);
    --cnt[a];
    sum += (cnt[a] == needx[a]);
}

void add(int a, vector<int> &cnt, int &sum, const vector<int> &needx) {
    sum -= (cnt[a] == needx[a]);
    ++cnt[a];
    sum += (cnt[a] == needx[a]);
}

void compress(vector<int> &a, vector<int> &needx) {
    vector<int> vals(a);
    sort(begin(vals), end(vals));
    map<int, int> new_val;
    int cur_val = 0;
    for (int v : vals) {
        if (new_val.count(v) == 0) {
            new_val[v] = cur_val++;
        }
    }

    for (int &x : a) {
        int y = new_val[x];
        needx[y] = x;
        x = y;
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> needx(n, 0);
    compress(a, needx);

    vector<tuple<int, int, int>> lr(m);
    for (int i = 0; i < m; ++i) {
        cin >> get<0>(lr[i]) >> get<1>(lr[i]);
        --get<0>(lr[i]);
        get<2>(lr[i]) = i;
    }
    const int BSZ = 300;
    sort(begin(lr), end(lr), [BSZ](const auto &lhs, const auto &rhs) {
        if (get<0>(lhs) / BSZ == get<0>(rhs) / BSZ) 
            return get<1>(lhs) < get<1>(rhs);
        return get<0>(lhs) < get<0>(rhs);
    });
    vector<int> res(m);
    vector<int> cnt(n, 0);
    int cur_sum = 0;
    for (int i = 0, lj = 0, rj = 0; i < m; ++i) { // keep answer for [lj, rj)
        const auto [l, r, ind] = lr[i]; // need answer for [l, r)
        while (lj > l) {
            --lj;
            add(a[lj], cnt, cur_sum, needx);
        }
        while (lj < l) {
            remove(a[lj], cnt, cur_sum, needx);
            ++lj;
        }
        while (rj > r) {
            --rj;
            remove(a[rj], cnt, cur_sum, needx);
        }
        while (rj < r) {
            add(a[rj], cnt, cur_sum, needx);
            ++rj;
        }
        res[ind] = cur_sum;
    }
    for (int x : res) {
        cout << x << "\n";
    }

    return 0;
}