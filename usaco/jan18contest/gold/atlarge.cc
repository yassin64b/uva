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

class atlarge {
public:
    void solve(istream& in, ostream& out) {
        int N, K;
        in >> N >> K;
        --K;
        vector<vector<int>> g(N);
        vector<int> deg(N, 0);
        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            in >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
            ++deg[u - 1];
            ++deg[v - 1];
        }
        if (deg[K] == 1) {
            out << 1 << "\n";
            return;
        }
        queue<pair<int, int>> q;
        q.emplace(K, 0);
        vector<int> vis(N, -1), expl(N, -1);
        for (int u = 0, cop_id = 0; u < N; ++u) {
            if (deg[u] == 1) {
                q.emplace(u, ++cop_id);
                vis[u] = expl[u] = cop_id;
            }
        }
        set<int> cops;
        while (!q.empty()) {
            int u = q.front().first, id = q.front().second;
            q.pop();
            cout << id << " " << u + 1 << endl;
            if (id == 0) {
                if (vis[u] > 0) {
                    assert(false);
                } else if (expl[u] > 0) { //cop can catch me
                    continue;
                } else if (deg[u] == 1) { //found exit
                    break;
                }
            }
            vis[u] = id;
            for (int v : g[u]) {
                if (vis[v] == -1) {
                    if (id == 0 && expl[v] > 0) { //cop can catch me
                        cops.insert(expl[v]);
                    } else if (id != 0 && expl[v] == 0) { //I can catch robber
                        expl[v] = id;
                        q.emplace(v, id);
                        cops.insert(id);
                    } else if (expl[v] == -1) {
                        expl[v] = id;
                        q.emplace(v, id);
                    }
                } else if (id == 0 && vis[v] > 0) { //I can't go there, cop was here before
                    cops.insert(vis[v]);
                }
            }
        }
        out << cops.size() << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    atlarge solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
