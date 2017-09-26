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

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            in >> b[i];
        }
        vector<int> p(n, 0);
        int ind1 = -1, ind2 = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i]) {
                p[i] = a[i];
            } else {
                if (ind1 == -1) {
                    ind1 = i;
                } else {
                    assert(ind2 == -1);
                    ind2 = i;
                }
            }
        }
        assert(ind1 != -1);
        if (ind2 == -1) {
            for (int miss = 1; miss <= n; ++miss) {
                if (find(p.begin(), p.end(), miss) == p.end()) {
                    p[ind1] = miss;
                }
            }
        } else {
            for (int miss = 1; miss <= n; ++miss) {
                if (find(p.begin(), p.end(), miss) == p.end()) {
                    if (!p[ind1] && (a[ind1] == miss || b[ind1] == miss)) {
                        p[ind1] = miss;
                    } else if (!p[ind2] && (a[ind2] == miss || b[ind2] == miss)){
                        p[ind2] = miss;
                    } else if (a[ind1] == miss || b[ind1] == miss) {
                        p[ind2] = p[ind1];
                        p[ind1] = miss;
                    } else {
                        p[ind1] = p[ind2];
                        p[ind2] = miss;
                    }
                }
            }
        }
        
        for (int x : p) {
            out << x << " ";
        }
        out << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}