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
        int n, k;
        in >> n >> k;
        
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; k && i < n; ++i) {
            for (int j = 0; k && j < n; ++j) {
                if (!res[i][j]) {
                    if (i == j) { //on diagonal
                        if (k % 2 == 1 || i + 1 < n) {
                            res[i][j] = 1;
                            --k;
                        }
                    } else {
                        if (k >= 2) {
                            res[i][j] = 1;
                            res[j][i] = 1;
                            k -= 2;
                        }
                    }
                }
                
            }
        }
        if (k != 0) {
            out << -1 << "\n";
        } else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    out << res[i][j] << " ";
                }
                out << "\n";
            }
        }
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
