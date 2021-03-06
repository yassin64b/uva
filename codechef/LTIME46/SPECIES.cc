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

constexpr int MOD = 1000*1000*1000+7;

vector<pair<int,int>> dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
class SPECIES {
private:
    int N;
    bool dfs(int i, int j, vector<string> &grid) {
        for (auto p : dir) {
            int ii = i + p.first, jj = j + p.second;
            if (ii == i && jj == j) continue;
            if (ii >= 0 && jj >= 0 && ii < N && jj < N) {
                if (grid[ii][jj] != '.') {
                    if (grid[i][j] == 'G') {
                        //cout << "conflict: " << ii << "," << jj << ":" << grid[ii][jj] << " " << i << "," << j << ":" << grid[i][j] << endl;
                        return false;
                    } else if (grid[ii][jj] != '?' && grid[ii][jj] != grid[i][j]) {
                        //cout << "conflict: " << ii << "," << jj << ":" << grid[ii][jj] << " " << i << "," << j << ":" << grid[i][j] << endl;
                        return false;
                    } else if (grid[ii][jj] == '?') {
                        grid[ii][jj] = grid[i][j];
                        if (!dfs(ii, jj, grid)) {
                            return false;
                        }
                    }
                }
                  
            }
        }
        
        return true;
    }
    
    int dfs2(int i, int j, vector<string> &grid) {
        int ret = 1;
        grid[i][j] = 1;
        for (auto p : dir) {
            int ii = i + p.first, jj = j + p.second;
            if (ii >= 0 && jj >= 0 && ii < N && jj < N && grid[ii][jj] == '?') {
                ret += dfs2(ii, jj, grid);
            }
        }
        return ret;
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            in >> N;
            vector<string> grid(N);
            for (int i = 0; i < N; ++i) {
                in >> grid[i];
            }
            
            bool flag = false;
            for (int i = 0; !flag && i < N; ++i) {
                for (int j = 0; !flag && j < N; ++j) {
                    if (grid[i][j] != '.' && grid[i][j] != '?') {
                        if (!dfs(i, j, grid)) {
                            out << "0\n";
                            flag = true;
                        }
                    }
                }
            }
            if (flag) {
                continue;
            }
            int cntall = 0, cntpb = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (grid[i][j] == '?') {
                        int tmp = dfs2(i, j, grid);
                        if (tmp == 1) {
                            ++cntall;
                        } else {
                            ++cntpb;
                        }
                    }
                }
            }
            
            long long res = 1;
            while (cntall) {
                res *= 3;
                res %= MOD;
                --cntall;
            }
            while (cntpb) {
                res *= 2;
                res %= MOD;
                --cntpb;
            }
            out << res << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    SPECIES solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
