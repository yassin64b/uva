#include <bits/stdc++.h>

using namespace std;

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<tuple<int, int, int>> xy(n);
        vector<int> x(n), y(n);
        for (int i = 0; i < n; ++i) {
            in >> x[i] >> y[i];
            xy[i] = {x[i], y[i], i};
        }
        vector<vector<int>> g(n);
        vector<int> u(m), v(m);
        for (int i = 0; i < m; ++i) {
            in >> u[i] >> v[i];
            g[u[i] - 1].push_back(v[i] - 1);
            g[v[i] - 1].push_back(u[i] - 1);
        }
        long long xsum = accumulate(begin(x), end(x), 0LL);
        long long ysum = accumulate(begin(y), end(y), 0LL);
        sort(begin(xy), end(xy), [](const auto &lhs, const auto &rhs) {
            auto [a, b, c] = lhs;
            auto [d, e, f] = rhs;
            return abs(a - b) > abs(d - e);
        });
        int num = n;
        long long add = 0;
        vector<int> done(n, 0);
        long long xcnt = 0, ycnt = 0;
        vector<long long> res(n, 0);
        for (auto [a, b, c] : xy) {
            xsum -= a;
            ysum -= b;
            --num;
            res[c] += xcnt * b + ycnt * a;
            if (a < b || (a == b && ysum < xsum)) {
                ++xcnt;
                res[c] += 1LL * num * a + ysum + add;
                add += a;
                for (int v : g[c]) {
                    if (!done[v]) {
                        res[v] -= a + y[v]; // because I will add add and xcnt * b later to v
                        res[c] -= a + y[v]; // because I added too much to c
                    }
                }
            } else {
                ++ycnt;
                res[c] += 1LL * num * b + xsum + add;
                add += b;
                for (int v : g[c]) {
                    if (!done[v]) {
                        res[v] -= b + x[v];
                        res[c] -= b + x[v];
                    }
                }
            }
            done[c] = 1;
        }
        for (long long x : res) {
            out << x << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
