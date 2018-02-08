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

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int k;
        in >> k;
        string res("a");
        int cur_cnt = 1;
        char cur_char = 'a';
        while (k) {
            if (k < cur_cnt) {
                ++cur_char;
                cur_cnt = 0;
            }
            res += cur_char;
            k -= cur_cnt;
            ++cur_cnt;
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
