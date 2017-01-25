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

class timus1723 {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        
        map<char,int> cnt;
        for (size_t i = 0; i < s.size(); ++i) {
            cnt[s[i]]++;
        }
        int mx = 0;
        char res = 0;
        for (pair<const char, int> &p : cnt) {
            if (p.second > mx) {
                res = p.first;
                mx = p.second;
            }
        }
        out << res << endl;
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    timus1723 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}