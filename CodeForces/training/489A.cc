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

class A489 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        out << n << "\n";
        for (int i = 0; i < n; ++i) {
            int mn = a[i], ind = i;
            for (int j = i; j < n; ++j) {
                if (a[j] < mn) {
                    mn = a[j];
                    ind = j;
                }
            }
            a[ind] = a[i];
            a[i] = mn;
            out << i << " " << ind << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    A489 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
