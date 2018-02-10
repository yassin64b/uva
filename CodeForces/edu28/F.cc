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
#include <sstream>

using namespace std;

class TaskF {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        constexpr int MXV = 1'000'000;
        vector<int> f(MXV + 1, -1); //last occurence of i
        long long int res = 0;
        for (int i = 0; i < n; ++i) { // cnt subarrays where first occurence of a_i at i
            // l must be in (f[a[i]], i]
            int num_ways_l = i - f[a[i]];
            // r must be in [i, n)
            int num_ways_r = n - i;
            // two ways for all l != r (l > r and swap, or l < r), subtract one for l = r
            res += 1LL * num_ways_l * num_ways_r * 2 - 1;
            f[a[i]] = i;
        }
        out.precision(17);
        out << fixed << (double)res / (1LL * n * n) << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskF solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}