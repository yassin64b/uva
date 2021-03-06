/*
ID: yassin.2
PROG: skidesign
LANG: C++11
*/
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

class skidesign {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> hills(N);
        for (int i = 0; i < N; ++i) {
            in >> hills[i];
        }
        
        int mn{100*100*1000};
        for (int elev = 0; elev+17 <= 100; ++elev) {
            int cur = 0;
            for (int i = 0; i < N; ++i) {
                if (hills[i] < elev) {
                    cur += (elev - hills[i]) * (elev - hills[i]);
                } else if (hills[i] > elev+17) {
                    cur += (hills[i] - elev - 17) * (hills[i] - elev - 17);
                }
            }
            //out << elev << " " << cur << endl;
            mn = min(mn, cur);
        }
        
        out << mn << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    skidesign solver;
    std::ifstream in("skidesign.in");
    std::ofstream out("skidesign.out");
    solver.solve(in, out);
    return 0;
}
