#include <bits/stdc++.h>

using namespace std;

class B376 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> a(m), b(m), c(m);
        //vector<vector<int>> f(n, vector<int>(n, 0));
        vector<int> bal(n, 0);
        for (int i = 0; i < m; ++i) {
            in >> a[i] >> b[i] >> c[i];
            --a[i];
            --b[i];
            //f[a[i]][b[i]] += c[i];
            bal[a[i]] -= c[i];
            bal[b[i]] += c[i];
        }
        /*for (int z = 0; z < n; ++z) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        int d = min(f[i][j], f[j][k]);
                        if (d > 0) {
                            f[i][j] -= d;
                            f[j][k] -= d;
                            f[i][k] += d;
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += accumulate(begin(f[i]), end(f[i]), 0);
        }*/
        int res2 = 0;
        for (int u = 0; u < n; ++u) {
            if (bal[u] > 0) {
                res2 += bal[u];
            }
        }
        out << res2 << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B376 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
