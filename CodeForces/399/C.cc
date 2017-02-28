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

constexpr int MAX = 1024;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, k, x;
        in >> n >> k >> x;
        
        vector<int> cnt(MAX, 0);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            ++cnt[a[i]];
        }
    
        vector<int> copy_cnt(MAX);
        for (int i = 0; i < k; ++i) {
            copy_cnt = cnt;
            int curcnt = 0;
            for (int j = 0; j < MAX; ++j) {
                if (curcnt % 2 == 0) {
                    int tmp = (cnt[j] + 1) / 2;
                    copy_cnt[j] -= tmp;
                    copy_cnt[j ^ x] += tmp;
                    curcnt += cnt[j];
                } else {
                    int tmp = cnt[j] / 2;
                    copy_cnt[j] -= tmp;
                    copy_cnt[j ^ x] += tmp;
                    curcnt += cnt[j];
                }
            }
            cnt = copy_cnt;
        }
        
        int mn = MAX, mx = -1;
        for (int i = 0; i < MAX; ++i) {
            if (cnt[i] > 0) {
                mn = min(mn, i);
                mx = max(mx, i);
            }
        }
        out << mx << " " << mn << endl;
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
