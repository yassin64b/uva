#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    int i = 0, d = 0;
    while (i < n) {
        ++d;
        int upto = a[i];
        for (; i <= upto; ++i) {
            upto = max(upto, a[i]);
        }
    }
    cout << d << "\n";

    return 0;
}