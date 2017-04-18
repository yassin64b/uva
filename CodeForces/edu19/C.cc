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

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        string s, t, u;
        in >> s;
        int n = s.size();
        vector<char> suf_s(n);
        suf_s[n-1] = s[n-1];
        for (int i = n-2; i >= 0; --i) {
            suf_s[i] = min(suf_s[i+1], s[i]);
        }
        
        int j = -1;
        for (int i = 0; i < n; ) {
            if (j == -1) {
                //cout << "t += " << s[i] << endl;
                t += s[i];
                ++j;
                ++i;
            } else {
                if (suf_s[i] < t[j]) {
                    //cout << "t += " << s[i] << endl;
                    t += s[i];
                    ++j;
                    ++i;
                } else {
                    //cout << "u += " << t[j] << endl;
                    u += t[j];
                    --j;
                    t.pop_back();
                }
            }
        }
        while (j >= 0) {
            u += t[j];
            --j;
        }
        out << u << "\n";
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