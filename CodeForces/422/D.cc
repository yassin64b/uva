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

constexpr int MOD = 1000 * 1000 * 1000 + 7;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int t, l, r;
        in >> t >> l >> r;
        
        vector<int> mn_prime_div(r + 1);
        for (int i = 2; i <= r; ++i)
            mn_prime_div[i] = i;
        for (int i = 2; i * i <= r; ++i) {
            if (mn_prime_div[i] == i) {
                for (int j = i * i; j <= r; j += i)
                    mn_prime_div[j] = min(mn_prime_div[j], i);
            }
        }
        
        vector<long long> f(r + 1);
        f[1] = 0;
        for (int i = 2; i <= r; ++i) {
            f[i] = 2e18;
            for (int x = i; x != 1; x /= mn_prime_div[x]) {
                int num_groups = i / mn_prime_div[x];
                int group_size = mn_prime_div[x];
                //num_groups * group_size * (group_size - 1) / 2
                //== i * (group_size - 1) / 2
                f[i] = min(f[i], f[num_groups] + 1LL * i * (group_size - 1) / 2);
            }
        }
        for (int i = 0; i <= r; ++i)
            f[i] %= MOD;
        
        int res = 0, curt = 1;
        for (; l <= r; ++l) {
            res += (long long)curt * f[l] % MOD;
            res %= MOD;
            curt = (long long)curt * t % MOD;
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
