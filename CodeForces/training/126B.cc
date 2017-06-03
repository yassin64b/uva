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

class B126 {
private:
    vector<int> b;
    string s;
    int n;
    
    void kmp_preprocess() {
        int i = 0, j = -1;
        b[0] = -1;
        while (i < n) {
            while (j >= 0 && s[i] != s[j]) {
                j = b[j];
            }
            ++i; ++j;
            b[i] = j;
        }
    }
public:
    void solve(istream& in, ostream& out) {
        in >> s;
        n = s.size();
        b.resize(n + 1);
        
        kmp_preprocess();
        
        
        if (b[n] == 0) {
            out << "Just a legend\n";
            return;
        } else {
            for (int i = 0; i < n; ++i) {
                if (b[i] == b[n]) {
                    out << s.substr(n - b[i]) << "\n";
                    return;
                }
            }
            if (b[b[n]] == 0) {
                out << "Just a legend\n";
            } else {
                out << s.substr(n - b[b[n]]) << "\n";
            }
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    B126 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}