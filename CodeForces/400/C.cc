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
#include <unordered_map>

using namespace std;

constexpr long long MAX{1000*1000*1000LL*1000*100};

class C776 {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        
        vector<long long> sum_a(n);
        sum_a[0] = a[0];
        for (int i = 1; i < n; ++i) {
            sum_a[i] = sum_a[i-1] + a[i];
        }
        
        set<long long> seen;
        long long cur = 1, res = 0;
        while (cur <= MAX && cur >= -MAX && seen.find(cur) == seen.end()) {
            seen.insert(cur);
            
            map<long long, int> avail;
            avail[0] = 1;
            //sum_a[r] - sum_a[l-1] == cur --> sum_a[l-1] == sum_a[r] - cur
            for (int i = 0; i < n; ++i) {
                if (avail.find(sum_a[i] - cur) != avail.end()) {
                    res += avail[sum_a[i] - cur];
                }
                ++avail[sum_a[i]];
            }
            
            cur *= k;
        }
        
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    C776 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}