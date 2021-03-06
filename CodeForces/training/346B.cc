#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string s1, s2, virus;
    cin >> s1 >> s2 >> virus;
    int n1 = s1.size(), n2 = s2.size(), m = virus.size();

    // nxt[i][j] = precompute the next common substring length
    // when adding character j to prefix of len i of virus
    vector<vector<int>> nxt_len(m, vector<int>(26, 0));
    for (int i = 0; i < m; ++i) {
        for (char c = 'A'; c <= 'Z'; ++c) {
            string cur = virus.substr(0, i) + c;
            int l = cur.size();
            for (int j = 1; j <= l; ++j) {
                if (cur.substr(l - j) == virus.substr(0, j)) {
                    nxt_len[i][c - 'A'] = max(nxt_len[i][c - 'A'], j);
                }
            }
        }
    }

    //dp[i][j][k] = like standard LCS dp 
    // with cur common substring of length k with virus
    vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, 
                                        vector<int>(m+1, 0)));
    for (int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {
            for (int k = 0; k < m; ++k) {
                if (i < n1 && j < n2 && s1[i] == s2[j]) {
                    int new_k = nxt_len[k][s1[i] - 'A'];
                    dp[i+1][j+1][new_k] = max(dp[i+1][j+1][new_k],
                                            dp[i][j][k] + 1);
                }
                if (i < n1) 
                    dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                if (j < n2)
                    dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);
            }
        }
    }


    int i = 0, j = 0, k = 0;
    for (int ci = 0; ci <= n1; ++ci) { // get maximum length
        for (int cj = 0; cj <= n2; ++cj) {
            for (int ck = 0; ck < m; ++ck) {
                if (dp[ci][cj][ck] > dp[i][j][k]) {
                    i = ci;
                    j = cj;
                    k = ck;
                }
            }
        }
    }
    string res;
    while (i > 0 || j > 0) {  // reconstruct string
        if (i > 0 && dp[i-1][j][k] == dp[i][j][k]) {
            --i;
            continue;
        } else if (j > 0 && dp[i][j-1][k] == dp[i][j][k]) {
            --j;
            continue;
        }
        assert(i > 0 && j > 0);
        assert(s1[i-1] == s2[j-1]);
        res += s1[i-1];
        for (int x = 0; x < m; ++x) {
            if (dp[i-1][j-1][x] + 1 == dp[i][j][k] 
                && nxt_len[x][s1[i-1] - 'A'] == k) {
                --i;
                --j;
                k = x;
                break;
            }
        }
    }

    reverse(begin(res), end(res));
    cout << (res.empty() ? "0" : res) << "\n";

    return 0;
}