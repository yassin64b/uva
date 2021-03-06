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

class D448 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        long long k;
        in >> n >> m >> k;
        
        long long ans = 1;
        long long low = 1, high = (long long)n*m;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long num = 0;
            for (int i = 0; i < n; ++i) {
                num += min((long long)m, (mid - 1) / (i+1));
            }
            if (num < k) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        out << ans << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    D448 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
