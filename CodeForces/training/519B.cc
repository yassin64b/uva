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

class B519 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n), b(n - 1), c(n - 2);
        for (int i = 0; i < n; ++i)
            in >> a[i];
        for (int i = 0; i < n - 1; ++i)
            in >> b[i];
        for (int i = 0; i < n - 2; ++i)
            in >> c[i];
        /*sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        for (int i = 0; i < n; ++i) {
            if (i == n - 1 || a[i] != b[i]) {
                out << a[i] << "\n";
                break;
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            if (i == n - 2 || b[i] != c[i]) {
                out << b[i] << "\n";
                break;
            }
        }*/
        long long sum_a = accumulate(a.begin(), a.end(), 0LL);
        long long sum_b = accumulate(b.begin(), b.end(), 0LL);
        long long sum_c = accumulate(c.begin(), c.end(), 0LL);
        out << sum_a - sum_b << "\n" << sum_b - sum_c << "\n";
        
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B519 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}