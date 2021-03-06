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

class B318 {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        int n = s.size();
        /*vector<int> metal(n + 1, 0);
        for (int i = 0; i + 4 < n; ++i)
            metal[i] = (s.substr(i, 5) == "metal");
        for (int i = n - 1; i >= 0; --i)
            metal[i] += metal[i + 1];
        long long res = 0;
        for (int i = 0; i + 4 < n; ++i) {
            if (s.substr(i, 5) == "heavy") {
                res += metal[i + 5];
            }
        }*/
        long long res = 0;
        int num_heavy = 0;
        for (int i = 0; i + 4 < n; ++i) {
            if (s.substr(i, 5) == "heavy")
                ++num_heavy;
            else if (s.substr(i, 5) == "metal")
                res += num_heavy;
        }
        out << res << "\n";
        
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B318 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
