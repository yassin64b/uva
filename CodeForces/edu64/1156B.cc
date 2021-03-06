#include <bits/stdc++.h>

using namespace std;

bool good(string res) {
    int n = res.size();
    bool ok = true;
    for (int i = 0; i + 1 < n; ++i) {
        if (abs(res[i] - res[i + 1]) == 1) {
            ok = false;
        }
    }
    return ok;
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) {
            ++cnt[c - 'a'];
        }
        string res1;
        for (int i = 0; i < 26; i += 2) {
            res1 += string(cnt[i], i + 'a');
        }
        for (int i = 1; i < 26; i += 2) {
            res1 += string(cnt[i], i + 'a');
        }
        if (good(res1)) {
            cout << res1 << "\n";
            continue;
        }
        string res2;
        for (int i = 1; i < 26; i += 2) {
            res2 += string(cnt[i], i + 'a');
        }
        for (int i = 0; i < 26; i += 2) {
            res2 += string(cnt[i], i + 'a');
        }
        cout << (good(res2) ? res2 : "No answer") << "\n";
    }
    return 0;
}