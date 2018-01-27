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

class B361 {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        if (k == n) {
            out << -1 << "\n";
            return;
        }
        vector<int> p(n);
        p[0] = n - k;
        for (int i = 1; i < n - k; ++i) {
            p[i] = i;
        }
        for (int i = n - k; i < n; ++i) {
            p[i] = i + 1;
        }
        for (int i = 0; i < n; ++i) {
            out << p[i] << " ";
        }
        out << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B361 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}