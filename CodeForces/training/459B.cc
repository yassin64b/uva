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

struct Edge {
    int u, v, w;
};

bool operator<(const Edge &lhs, const Edge &rhs) {
    return lhs.w < rhs.w;
}

class E459 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        
        vector<Edge> edges(m);
        for (int i = 0; i < m; ++i) {
            in >> edges[i].u >> edges[i].v >> edges[i].w;
            --edges[i].u;
            --edges[i].v;
        }
        sort(edges.begin(), edges.end());
        
        vector<int> dp(n, 0), _dp(n, 0);
        for (int i = 0; i < m; ++i) {
            int j = i;
            while (j < m-1 && edges[j+1].w == edges[j].w) {
                ++j;
            }
            
            for (int k = i; k <= j; ++k) {
                _dp[edges[k].v] = 0;
            }
            for (int k = i; k <= j; ++k) {
                _dp[edges[k].v] = max(_dp[edges[k].v], dp[edges[k].u]+1);
            }
            for (int k = i; k <= j; ++k) {
                dp[edges[k].v] = max(dp[edges[k].v], _dp[edges[k].v]);
            }
            i = j;
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, dp[i]);
        }
        out << mx << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    E459 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
