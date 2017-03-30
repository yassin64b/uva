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

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> w(n);
        for (int i = 0; i < n; ++i) {
            in >> w[i];
        }
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            int tmp = w[i] / k;
            if (w[i] % k) ++tmp;
            res += tmp;
        }
        out << res / 2 + (res % 2) << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
