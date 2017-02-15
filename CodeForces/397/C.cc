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

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int k, a, b;
        in >> k >> a >> b;
        
        int mx1 = a / k;
        int mx2 = b / k;
        
        a -= mx1 * k;
        b -= mx2 * k;
        
        if ((a > 0 && mx2 == 0) || (b > 0 && mx1 == 0)) {
            out << -1 << "\n";
            return;
        }
        
        out << mx1 + mx2 << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
