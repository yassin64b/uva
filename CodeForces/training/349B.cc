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

class B349 {
public:
    void solve(istream& in, ostream& out) {
        int v;
        in >> v;
        pair<int,int> a[9];
        for (int i = 1; i <= 9; ++i) {
            in >> a[i-1].first;
            a[i-1].second = i-1;
        }
        sort(a, a+9);
        
        int ind = 0;
        for (int i = 0; i < 9 && a[i].first == a[0].first; ++i) {
            ind = i;
        }
        vector<int> res(v / a[ind].first, a[ind].second+1);
        v %= a[ind].first;
        
        if (res.size() > 0) {
            int j = 0;
            while (ind+1 < 9 && v >= a[ind+1].first - a[ind].first) {
                int nxt = ind+1;
                for (int i = 0; i < 9; ++i) {
                    if (i == ind) continue;
                    if (a[i].first - a[ind].first <= v && a[i].second > a[nxt].second) {
                        nxt = i;
                    }
                }
                if (a[nxt].second+1 < a[ind].second+1) {
                    break;
                }
                res[j] = a[nxt].second+1;
                v -= a[nxt].first - a[ind].first;
                ++j;
            }
            
            for (int i = 0; i < (int)res.size(); ++i) {
                out << res[i];
            }
            out << "\n";
        } else {
            out << -1 << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    B349 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
