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

class TaskD {
private:
    vector<int> tin, tout, sz;
    int t = 1;
    void dfs(int u, const vector<vector<int>>& g) {
        tin[u] = t++;
        sz[u] = 1;
        for (int v : g[u]) {
            dfs(v, g);
            sz[u] += sz[v];
        }
        tout[u] = t++;
    }
    
    bool in_subtree(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m, k, q;
        in >> n >> m >> k >> q;
        tin.assign(n, 0);
        tout.assign(n, 0);
        sz.assign(n, 0);
        vector<vector<int>> g(n);
        vector<int> heldby(m, -1);
        vector<int> root(n, 1);
        for (int i = 0; i < k; ++i) {
            int a, b;
            in >> a >> b;
            --a; --b;
            if (heldby[b] != -1) {
                g[heldby[b]].push_back(a);
                root[a] = 0;
            }
            heldby[b] = a;
        }
        
        for (int i = 0; i < n; ++i) {
            if (root[i]) {
                dfs(i, g);
            }
        }
        
        for (int i = 0; i < q; ++i) {
            int x, y;
            in >> x >> y;
            --x; --y;
            if (heldby[y] != -1 && in_subtree(x, heldby[y])) {
                out << sz[x] << "\n";
            } else {
                out << 0 << "\n";
            }
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
