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

class aoc3_2 {
private:
    bool calc(vector<vector<int>>& grid, int x, int y, const int n, ostream& out) {
        int res = 0;
        for (int dx = -1; dx <= 1; ++dx)
            for (int dy = -1; dy <= 1; ++dy)
                res += grid[x + dx][y + dy];
        
        if ((grid[x][y] = res) > n) {
            out << grid[x][y] << "\n";
            return true;
        }
        return false;
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<vector<int>> grid(1000, vector<int>(1000, 0));
        int x = 500, y = 500;
        grid[x][y] = 1;
        int len = 1;
        while (true) {
            len += 2;
            ++y;
            if (calc(grid, x, y, n, out)) return;
            
            while (x > 500 - len / 2) {
                --x;
                if (calc(grid, x, y, n, out)) return;
            }
            while (y > 500 - len / 2) {
                --y;
                if (calc(grid, x, y, n, out)) return;
            }
            while (x < 500 + len / 2) {
                ++x;
                if (calc(grid, x, y, n, out)) return;
            }
            while (y < 500 + len / 2) {
                ++y;
                if (calc(grid, x, y, n, out)) return;
            }
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    aoc3_2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
