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

class arc87D {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        int n = s.size();
        int x, y;
        in >> x >> y;
        vector<int> dirx, diry;
        int start = 1, curx = 0, cury = 0;
        int startx = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'T') {
                if (start) start = 0, cury = 1, diry.push_back(0);
                else if (curx) curx = 0, cury = 1, diry.push_back(0);
                else if (cury) curx = 1, cury = 0, dirx.push_back(0);
                else assert(false);
            } else {
                if (start)
                    ++startx;
                else if (curx)
                    ++dirx.back();
                else
                    ++diry.back();
            }
        }
        vector<int> dpx(16001, 0);
        dpx[startx + 8000] = 1;
        for (int i = 0; i < (int)dirx.size(); ++i) {
            vector<int> nxtx(16001, 0);
            for (int j = dirx[i]; j <= 16000; ++j)
                if (dpx[j]) nxtx[j - dirx[i]] = 1;
            for (int j = 0; j + dirx[i] <= 16000; ++j)
                if (dpx[j]) nxtx[j + dirx[i]] = 1;
            dpx = nxtx;
        }
        vector<int> dpy(16001, 0);
        dpy[0 + 8000] = 1;
        for (int i = 0; i < (int)diry.size(); ++i) {
            vector<int> nxty(16001, 0);
            for (int j = diry[i]; j <= 16000; ++j)
                if (dpy[j]) nxty[j - diry[i]] = 1;
            for (int j = 0; j + diry[i] <= 16000; ++j)
                if (dpy[j]) nxty[j + diry[i]] = 1;
            dpy = nxty;
        }
        if (dpx[x + 8000] && dpy[y + 8000])
            out << "Yes\n";
        else
            out << "No\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    arc87D solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
