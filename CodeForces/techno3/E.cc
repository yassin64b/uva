/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author yassin64b
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
#include <queue>

using namespace std;

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        
        int sz = 1e7 + 1;
        vector<int64_t> parts(sz, 0);
        vector<int> a(n);
        int64_t cnt = 0;
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            parts[a[i]]++;
            cnt += a[i];
        }
        
        if (cnt < k) {
            out << -1 << endl;
            return;
        }
        
        int sm = 0, big = sz - 1;
        
        while (sm < big) {
            while (sm < big && !parts[sm]) {
                ++sm;
            }
            while (big >= sm && !parts[big]) {
                --big;
            }
            while (n > k) {
                int64_t save = parts[sm], diff = n - k;
                parts[sm] = max(save - diff, 0LL);
                n -= (save - parts[sm]);
                while (sm < sz && !parts[sm]) {
                    ++sm;
                }
            }
            
            
            if (big <= 1) {
                break;
            }
            
            int v1 = big / 2, v2 = big / 2 + (big % 2);
            if (n < k) {
                parts[v1] += parts[big];
                parts[v2] += parts[big];
                n += parts[big];
                sm = min(sm, v1);
                parts[big] = 0;
                --big;
            } else if (v2 > sm) {
                parts[v1] += parts[big];
                parts[v2] += parts[big];
                n += parts[big];
                parts[big] = 0;
                --big;
            } else {
                break;
            }
        }
        
        out << sm << endl;
        
    }
};

int main() {
    std::ios::sync_with_stdio(false);

    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
