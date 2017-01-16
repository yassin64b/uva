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
#include <cassert>

using namespace std;

constexpr int MOD = 1e9 + 7;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        
        vector<vector<int>> v(m);
        for (int i = 0; i < n; ++i) {
            int len;
            in >> len;
            for (int j = 0; j < len; ++j) {
                int tmp;
                in >> tmp;
                v[tmp-1].push_back(i);
            }
        }
        for (int i = 0; i < m; ++i) {
            sort(v[i].begin(), v[i].end());
        }
        sort(v.begin(), v.end());
        /*for (int i = 0; i < m; ++i) {
            for (auto &x : v[i]) {
                out << x+1 << " ";
            }
            out << endl;
        }
        out << endl;*/
        
        vector<int64_t> fact(m+1);
        fact[0] = fact[1] = 1;
        for (int i = 2; i < m+1; ++i) {
            fact[i] = i * fact[i-1] % MOD;
        }
        int cnt = 1;
        int64_t res = 1;
        for (int i = 0; i < m; ++i) {
            if (v[i] == v[i+1]) {
                ++cnt;
            } else {
                res = res * fact[cnt] % MOD;
                cnt = 1;
            }
        }
        out << res << endl;
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
