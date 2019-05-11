#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    set<pair<double, double>> seen;
    map<double, int> cnt;
    set<double> hori, vert;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (x[i] != x[j] && y[i] != y[j]) {
                double slope = (y[j] - y[i]) / (double)(x[j] - x[i]);
                double b = y[i] - slope * x[i];
                if (seen.count(pair(slope, b))) continue;
                seen.insert(pair(slope, b));
                ++cnt[(slope)];
            } else if (x[i] == x[j]) {
                hori.insert(x[i]);
            } else {
                vert.insert(y[i]);
            }
        }
    }
    int m = seen.size();
    long long res = (long long)m * (m - 1) / 2;
    // each hori intersects with each vert
    res += (long long)hori.size() * vert.size();
    // each hori/vert intersects with each non hori/vert line
    res += (long long)(hori.size() + vert.size()) * m;
    for (auto [k, v] : cnt) {
        //cout << k << ": " << v << endl;
        res -= (long long)v * (v - 1) / 2;
    }
    cout << res << "\n";

    return 0;
}