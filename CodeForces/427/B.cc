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

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int k;
        string n;
        in >> k >> n;
        int sod = 0;
        int cnt[10]{0};
        for (int i = 0; i < (int)n.size(); ++i) {
            sod += n[i] - '0';
            ++cnt[n[i] - '0'];
        }
        int res = 0;
        for (int i = 0; i < 10; ++i) {
            while (sod < k && cnt[i] > 0) {
                sod += 9 - i;
                --cnt[i];
                ++res;
            }
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}