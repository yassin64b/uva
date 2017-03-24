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

vector<int> t;
int n;

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = t[2*i] & t[2*i+1];
}

int query(int l, int r) {  // and on interval [l, r)
    int res = (1 << 30) - 1;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) res &= t[l++];
        if (r & 1) res &= t[--r];
    }
    return res;
}

struct limit {
    int l, r, q;
};

class B482 {
public:
    void solve(istream& in, ostream& out) {
        int m;
        in >> n >> m;
        vector<limit> v(m);
        for (int i = 0; i < m; ++i) {
            in >> v[i].l >> v[i].r >> v[i].q;
            --v[i].l; --v[i].r;
        }
        vector<int> res(n, 0);
        for (int shift = 0; shift < 30; ++shift) {
            vector<int> cur(n+1, 0);
            for (int j = 0; j < m; ++j) {
                if ((v[j].q >> shift) & 1) {
                    cur[v[j].l] += 1;
                    cur[v[j].r+1] += -1;
                }
            }
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += cur[i];
                if (sum > 0) {
                    res[i] |= (1 << shift);
                }
            }
        }
        
        t.assign(2*n, 0);
        for (int i = 0; i < n; ++i) {
            t[i+n] = res[i];
        }
        build();

        for (int i = 0; i < m; ++i) {
            if (query(v[i].l, v[i].r+1) != v[i].q) {
                out << "NO\n";
                return;
            }
        }
        out << "YES\n";
        for (int i = 0; i < n; ++i) {
            out << res[i] << " ";
        }
        out << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    B482 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
