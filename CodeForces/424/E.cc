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

class FenwickTree {
private:
    vector<int> ft;
public:
    FenwickTree(int n) {
        ft.assign(n + 1, 0);
    }
    int rsq(int b) {
        int sum = 0;
        for (; b; b -= (b & (-b))) {
            sum += ft[b];
        }
        return sum;
    }
    int rsq(int a, int b) {
        if (a > b) return 0;
        return rsq(b) - rsq(a - 1);
    }
    void update(int a, int v) {
        for ( ; a < (int)ft.size(); a += (a & (-a))) {
            ft[a] += v;
        }
    }
    //NOTE: when using range update, rsq(x) is point query + don't use update(a, v)!!
    void update(int a, int b, int v) {
        update(a, v);
        update(b + 1, -v);
    }
};

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        map<int, set<int>> aa;
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            aa[a[i]].insert(i);
        }
        long long res = 0;
        int ind = 0;
        FenwickTree ft(n);
        for (int i = 1; i <= n; ++i) {
            ft.update(i, 1);
        }
        for (pair<const int, set<int>>& x : aa) {
            set<int>& s = x.second;
            while (!s.empty()) {
                auto it = s.lower_bound(ind);
                int nxt;
                if (it == s.end()) {
                    it = s.begin();
                    nxt = *it;
                    res += ft.rsq(ind + 1, n) + ft.rsq(1, nxt + 1);
                    //res += (n - ind);
                } else {
                    nxt = *it;
                    res += ft.rsq(ind + 1, nxt + 1);
                    //res += (nxt - ind);
                }
                ind = nxt + 1;
                s.erase(it);
                ft.update(nxt + 1, -1);
    
            }
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}