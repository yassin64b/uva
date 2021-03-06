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

class A107 {
private:
    static constexpr int INF = 2'000'000'000;
    void dfs(int u, int src, int mn_d, const vector<vector<pair<int, int>>>& g,
             vector<tuple<int, int ,int>>& t) {
        if (g[u].empty() && u != src) {
            t.emplace_back(src, u, mn_d);
            return;
        }
        for (const pair<int, int>& p : g[u]) {
            dfs(p.first, src, min(mn_d, p.second), g, t);
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n, p;
        in >> n >> p;
        vector<vector<pair<int, int>>> g(n);
        vector<int> num_in(n, 0);
        for (int i = 0; i < p; ++i) {
            int a, b, d;
            in >> a >> b >> d;
            g[a - 1].emplace_back(b - 1, d);
            ++num_in[b - 1];
        }
        vector<tuple<int, int, int>> res;
        for (int i = 0; i < n; ++i) {
            if (num_in[i] == 0) {
                dfs(i, i, INF, g, res);
            }
        }
        out << res.size() << "\n";
        for (const auto& t : res) {
            int tank, tap, diam;
            tie (tank, tap, diam) = t;
            out << tank + 1 << " " << tap + 1 << " " << diam << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A107 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
