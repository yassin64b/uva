#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;
    cout << max(0, A - 2 * B) << "\n";
    
    return 0;
}