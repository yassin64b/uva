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

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        
        vector<string> p1(n), p2(m);
        for (int i = 0; i < n; ++i) {
            in >> p1[i];
        }
        map<string,int> vis;
        for (int i = 0; i < m; ++i) {
            in >> p2[i];
            vis[p2[i]]++;
        }
        
        int both = 0;
        for (int i = 0; i < n; ++i) {
            if (vis.find(p1[i]) != vis.end()) {
                ++both;
            }
        }
        
        if (both % 2 == 1) {
            --m;
        }
        out << (n > m ? "YES" : "NO") << endl;
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}