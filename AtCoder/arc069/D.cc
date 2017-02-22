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


class atD {
private:
    int N;
    inline char opp(char c) {
        return c == 'W' ? 'S' : 'W';
    }
    bool check(string &res, const string &s) {
        for (int i = 1; i < N-1; ++i) {
            if (s[i] == 'o') {
                if (res[i] == 'W') {
                    res[i+1] = opp(res[i-1]);
                } else if (res[i] == 'S') {
                    res[i+1] = res[i-1];
                }
            } else if (s[i] == 'x') {
                if (res[i] == 'W') {
                    res[i+1] = res[i-1];
                } else if (res[i] == 'S') {
                    res[i+1] = opp(res[i-1]);
                }
            }
        }
        
        bool flag = true;
        if (s[0] == 'o') {
            if (res[0] == 'W') {
                flag = res[N-1] == opp(res[1]);
            } else if (res[0] == 'S') {
                flag = res[N-1] == res[1];
            }
        } else if (s[0] == 'x') {
            if (res[0] == 'W') {
                flag = res[N-1] == res[1];
            } else if (res[0] == 'S') {
                flag = res[N-1] == opp(res[1]);
            }
        }
        if (s[N-1] == 'o') {
            if (res[N-1] == 'W') {
                return flag && res[N-2] == opp(res[0]);
            } else if (res[N-1] == 'S') {
                return flag && res[N-2] == res[0];
            }
        } else if (s[N-1] == 'x') {
            if (res[N-1] == 'W') {
                return flag && res[N-2] == res[0];
            } else if (res[N-1] == 'S') {
                return flag && res[N-2] == opp(res[0]);
            }
        }
        assert(true);
        return true;
    }
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> N >> s;
        
        string res(N, ' ');
        res[0] = 'S'; res[1] = 'S';
        if (check(res, s)) {
            out << res << "\n";
            return;
        }
        
        res.assign(N, ' ');
        res[0] = 'S'; res[1] = 'W';
        if (check(res, s)) {
            out << res << "\n";
            return;
        }
        
        res.assign(N, ' ');
        res[0] = 'W'; res[1] = 'S';
        if (check(res, s)) {
            out << res << "\n";
            return;
        }
        
        res.assign(N, ' ');
        res[0] = 'W'; res[1] = 'W';
        if (check(res, s)) {
            out << res << "\n";
            return;
        }
        
        out << "-1\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    atD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
