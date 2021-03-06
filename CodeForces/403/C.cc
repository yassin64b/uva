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

class TaskC {
private:
    
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n-1; ++i) {
            int x, y;
            in >> x >> y;
            g[x-1].push_back(y-1);
            g[y-1].push_back(x-1);
        }
        
        int maxdeg = 0;
        for (int i = 0; i < n; ++i) {
            maxdeg = max(maxdeg, (int)g[i].size()+1);
        }
        
        vector<int> tmp(n);
        for (int i = 0; i < n; ++i) {
            tmp[i] = i+1;
        }
        vector<int> col(n, 0), par(n, 0);
        col[0] = 1;
        
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
        
            int nxtcol = 1;
            for (int i = 0; i < (int)g[u].size(); ++i) {
                while (nxtcol == col[u] || nxtcol == col[par[u]]) {
                    ++nxtcol;
                }
                
                int v = g[u][i];
        
                if (col[v] == 0) {
                    col[v] = nxtcol++;
                    
                    par[v] = u;
                    q.push(v);
                }
            }
        }
        
        out << max(3, maxdeg) << endl;
        for (int i = 0; i < n; ++i) {
            out << col[i] << " ";
        }
        out << endl;
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
