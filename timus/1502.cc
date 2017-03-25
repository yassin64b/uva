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

class timus1502 {
public:
    void solve(istream& in, ostream& out) {
        long long res = 0;
        int N;
        in >> N;
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= i; ++j) {
                res += i + j;
            }
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    timus1502 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
