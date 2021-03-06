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

class A464 {
private:
    bool tolerable(const string &s) {
        for (int i = 0; i < (int) s.size() - 1; ++i) {
            if (s[i] == s[i + 1]) {
                return false;
            }
        }
        for (int i = 0; i < (int) s.size() - 2; ++i) {
            if (s[i] == s[i + 2]) {
                return false;
            }
        }
        return true;
    }

public:
    void solve(istream &in, ostream &out) {
        int n, p;
        string s;
        in >> n >> p >> s;
        if (p == 1 || (p == 2 && n > 2)) {
            out << "NO\n";
            return;
        }
        
        bool finished = false;
        char mx_char = 'a' + p - 1;
        for (int i = n-1; !finished && i >= 0; --i) {
            for (s[i] += 1; s[i] <= mx_char; ++s[i]) {
                if ((i-1 < 0 || s[i] != s[i-1]) && (i-2 < 0 || s[i] != s[i-2])) {
                    for (int j = i+1; j < n; ++j) {
                        for (s[j] = 'a'; s[j] <= mx_char; ++s[j]) {
                            if (s[j] != s[j-1] && (j-2 < 0 || s[j] != s[j-2])) {
                                break;
                            }
                        }
                    }
                    finished = true;
                    break;
                }
            }
        }
            
        if (finished) {
            out << s << "\n";
        } else {
            out << "NO\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    A464 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
