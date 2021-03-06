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

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        string s;
        in >> s;
    
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int x = 0, y = 0;
                for (int k = i; k <= j; ++k) {
                    if (s[k] == 'U') ++y;
                    else if (s[k] == 'R') ++x;
                    else if (s[k] == 'D') --y;
                    else if (s[k] == 'L') --x;
                }
                if (x == 0 && y == 0) ++res;
            }
        }
        out << res << endl;
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
