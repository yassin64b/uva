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

class I101170 {
private:
    void bfs(const vector<vector<int>> &g, const vector<int>& start, vector<int>& dist) {
        queue<int> q;
        for (int x : start) {
            q.push(x);
            dist[x] = 0;
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m, k;
        in >> n >> m >> k;
        vector<int> o(m), c(k);
        for (int i = 0; i < m; ++i) {
            in >> o[i];
            --o[i];
        }
        for (int i = 0; i < k; ++i) {
            in >> c[i];
            --c[i];
        }
        vector<vector<int>> g(n), t_g(n);
        for (int i = 0; i < n; ++i) {
            int a;
            in >> a;
            for (int j = 0; j < a; ++j) {
                int b;
                in >> b;
                g[i].push_back(b - 1);
                t_g[b - 1].push_back(i);
            }
        }
        
        vector<int> dist1(n, -1), dist2(n, -1), dist3(n, -1);
        bfs(g, {0}, dist1);
        bfs(t_g, o, dist2);
        bfs(t_g, c, dist3);
        int res = -1;
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != -1 && dist2[i] != -1 && dist3[i] != -1) {
                if (res == -1) {
                    res = dist1[i] + dist2[i] + dist3[i];
                }
                res = min(res, dist1[i] + dist2[i] + dist3[i]);
            }
        }
        if (res == -1) {
            out << "impossible\n";
        } else {
            out << res << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    I101170 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}