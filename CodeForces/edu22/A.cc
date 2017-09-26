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

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            sum += a[i];
        }
        int m;
        in >> m;
        vector<pair<int, int>> lr(m);
        for (int i = 0; i < m; ++i) {
            in >> lr[i].first >> lr[i].second;
        }
    
        int time = 1000 * 1000;
        for (int i = 0; i < m; ++i) {
            if (lr[i].second >= sum) {
                time = min(time, max(lr[i].first, sum));
            }
        }
        if (time == 1000 * 1000) {
            time = -1;
        }
        out << time << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}