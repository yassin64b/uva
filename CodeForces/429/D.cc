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
#include <sstream>

using namespace std;

class TaskD {
private:
    bool dfs(int u, const vector<vector<pair<int, int>>> &g, vector<int> &d,
             vector<int> &res, vector<int> &vis)
    {
        vis[u] = 1;
        for (const auto &p : g[u]) {
            int v = p.first, ind = p.second;
            if (!vis[v]) {
                if (dfs(v, g, d, res, vis)) {
                    res.push_back(ind);
                    ++d[u];
                }
            }
        }
        return d[u] % 2;
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            in >> d[i];
        }
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            in >> u >> v;
            g[u - 1].emplace_back(v - 1, i + 1);
            g[v - 1].emplace_back(u - 1, i + 1);
        }
        int sum = count(d.begin(), d.end(), 1);
        for (int i = 0; i < n; ++i) {
            if (d[i] == -1) {
                if (sum % 2) {
                    d[i] = 1;
                    ++sum;
                } else {
                    d[i] = 0;
                }
            }
        }
        if (sum % 2) {
            out << -1 << "\n";
            return;
        }
        vector<int> vis(n, 0), res;
        dfs(0, g, d, res, vis);
        out << res.size() << "\n";
        for (int x : res) {
            out << x << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
