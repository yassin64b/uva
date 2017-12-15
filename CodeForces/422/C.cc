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

struct voucher {
    int l, r, cost;
    int dur;
};

bool smaller1(const voucher& lhs, const voucher& rhs) {
    return lhs.l < rhs.l;
}
bool smaller2(const voucher& lhs, const voucher& rhs) {
    return lhs.r < rhs.r;
}

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, x;
        in >> n >> x;
        vector<voucher> vl(n);
        for (int i = 0; i < n; ++i) {
            in >> vl[i].l >> vl[i].r >> vl[i].cost;
            vl[i].dur = vl[i].r - vl[i].l + 1;
        }
        vector<voucher> vr(vl);
        sort(vl.begin(), vl.end(), smaller1);
        sort(vr.begin(), vr.end(), smaller2);
        vector<int> best(200000 + 1, -1);
        int res = -1;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && vr[j].r < vl[i].l) {
                if (best[vr[j].dur] == -1)
                    best[vr[j].dur] = vr[j].cost;
                best[vr[j].dur] = min(best[vr[j].dur], vr[j].cost);
                ++j;
            }
            int need = x - vl[i].dur;
            if (need >= 0 && need <= 200000 && best[need] != -1) {
                if (res == -1)
                    res = vl[i].cost + best[need];
                res = min(res, vl[i].cost + best[need]);
            }
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}