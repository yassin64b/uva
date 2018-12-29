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

class aoc6_2 {
public:
    void solve(istream& in, ostream& out) {
        int x;
        vector<int> v;
        while (in >> x)
            v.push_back(x);
        int n = v.size();
        int res = 0;
        map<vector<int>, int> m;
        while (m.find(v) == m.end()) {
            m[v] = ++res;
            int ind = max_element(v.begin(), v.end()) - v.begin();
            int num = v[ind];
            int chunk = v[ind] / n + (v[ind] % n ? 1 : 0);
            v[ind] = 0;
            for (int i = ind + 1; i < n; ++i) {
                if (num >= chunk)
                    v[i] += chunk, num -= chunk;
                else
                    v[i] += num, num = 0;
            }
            for (int i = 0; i <= ind; ++i) {
                if (num >= chunk)
                    v[i] += chunk, num -= chunk;
                else
                    v[i] += num, num = 0;
            }
        }
        out << res - m[v] + 1 << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    aoc6_2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}