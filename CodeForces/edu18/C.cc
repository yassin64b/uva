/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author yassin
 */

#include <fstream>

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <tuple>
#include <queue>
#include <functional>
#include <stack>
#include <numeric>
#include <cassert>

using namespace std;

class TaskC {
private:
    int sod(int x) {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res < 10 ? res : sod(res);
    }
public:
    void solve(istream& in, ostream& out) {
        string tmp;
        in >> tmp;
        int n = tmp.size();
        vector<int> v(n);
        vector<int> num_zeros(n, 0);
        bool seenOne = false;
        for (int i = 0; i < n; ++i) {
            v[i] = tmp[i] - '0';
            if (v[i] == 0) {
                num_zeros[i] = (i > 0 ? num_zeros[i-1] : 0) + 1;
                seenOne = true;
            }
        }
        
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(10, {0, 0}));
        dp[0][v[0]] = {v[0] != 0, v[0] != 0};
        for (int i = 1; i < n; ++i) {
            dp[i][v[i]] = {v[i] != 0, v[i] != 0};
            for (int j = 0; j < 10; ++j) {
                if (dp[i-1][j].first) {
                    if (dp[i-1][j].first > dp[i][j].first) {
                        dp[i][j].first = dp[i-1][j].first;
                        dp[i][j].second = 0;
                    }
                    
                    int val = sod(j+v[i]);
                    if (dp[i-1][j].first+1 > dp[i][val].first) {
                        dp[i][val].first = dp[i-1][j].first+1;
                        dp[i][val].second = 1;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                //cout << dp[i][j].first << "," << dp[i][j].second << " ";
            }
            //cout << endl;
        }
        int mx = max(max(dp[n-1][3].first, dp[n-1][6].first), max(dp[n-1][9].first, dp[n-1][0].first));
        if (mx) {
            //cout << mx << endl;
            string res;
            int i = n-1, cur = 0;
            if (dp[i][9].first == mx) {
                cur = 9;
            } else if (dp[i][3].first == mx) {
                cur = 3;
            } else if (dp[i][6].first == mx) {
                cur = 6;
            }
            while (i > 0) {
                //cout << i << " " << cur << endl;
                for (int j = 0; j < 10; ++j) {
                    if (sod(j+dp[i][cur].second*v[i]) == cur && dp[i-1][j].first+dp[i][cur].second == dp[i][cur].first) {
                        if (dp[i][cur].second) {
                            res += v[i] + '0';
                            //cout << "push " << res.back() << endl;
                        }
                        cur = j;
                        //cout << "found " << i << " -> " << cur << endl;
                        goto nxt;
                    }
                }
                //cout << "nothing found for << " << i << " " << cur << endl;
                
                nxt: --i;
                
            }
            if (dp[i][cur].first > 0 && dp[i][cur].second == 1) {
                res += v[i] + '0';
            }
            reverse(res.begin(), res.end());
            out << res << "\n";
        } else {
            if (seenOne) {
                out << "0\n";
            } else {
                out << -1 << "\n";
            }
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
