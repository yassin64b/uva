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

class C339 {
private:
    bool dfs(int balance, int last, int i, const vector<int>& b, vector<int> &res, const int m) {
        if (i == m) {
            return true;
        }
        for (int j = 0; j < (int)b.size(); ++j) {
            if (b[j] != last) {
                if (i % 2 == 0) {
                    if (balance + b[j] > 0) {
                        if (dfs(balance + b[j], b[j], i+1, b, res, m)) {
                            res.push_back(b[j]);
                            return true;
                        }
                    }
                } else {
                    if (balance - b[j] < 0) {
                        if (dfs(balance - b[j], b[j], i+1, b, res, m)) {
                            res.push_back(b[j]);
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
public:
    void solve(istream& in, ostream& out) {
        vector<int> a(10), b;
        for (int i = 0; i < 10; ++i) {
            char c;
            in >> c;
            a[i] = (c == '1');
            if (a[i]) {
                b.push_back(i+1);
            }
        }
        int m;
        in >> m;
        
        vector<int> res;
        bool ret = dfs(0, 0, 0, b, res, m);
        if (!ret) {
            out << "NO\n";
        } else {
            out << "YES\n";
            for (int i = (int)res.size()-1; i >= 0; --i) {
                out << res[i] << " ";
            }
            out << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    C339 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
