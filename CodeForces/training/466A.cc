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

class A466 {
public:
    void solve(istream& in, ostream& out) {
        int n, m, a, b;
        in >> n >> m >> a >> b;
        
        vector<int> dp(n+m, 1000 * 1000 * 1000);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            dp[i + m] = min(dp[i + m], dp[i] + b);
            dp[i + 1] = min(dp[i + 1], dp[i] + a);
        }
        out << *min_element(dp.begin() + n, dp.end()) << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    A466 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
