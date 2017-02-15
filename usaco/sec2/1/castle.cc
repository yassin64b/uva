/*
ID: yassin.2
PROG: castle
LANG: C++11
*/
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

class castle {
private:
    int dfs(int x, int y, const vector<vector<vector<pair<int,int>>>> &g, vector<vector<int>> &vis) {
        vis[x][y] = 1;
        
        int res = 1;
        for (const pair<int,int> &p : g[x][y]) {
            if (!vis[p.first][p.second]) {
                res += dfs(p.first, p.second, g, vis);
            }
        }
        
        return res;
    }
public:
    void solve(istream& in, ostream& out) {
        int M, N;
        in >> M >> N;
        
        vector<vector<vector<pair<int,int>>>> remove(N, vector<vector<pair<int,int>>>(M));
        vector<vector<vector<pair<int,int>>>> g(N, vector<vector<pair<int,int>>>(M));
        vector<vector<int>> grid(N, vector<int>(M));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                in >> grid[i][j];
                
                int x = grid[i][j];
                if (x >= 8) {
                    x -= 8;
                    if (i < N-1) remove[i][j].push_back(make_pair(i+1, j));
                } else {
                    g[i][j].push_back(make_pair(i+1, j));
                }
                if (x >= 4) {
                    x -= 4;
                    if (j < M-1) remove[i][j].push_back(make_pair(i, j+1));
                } else {
                    g[i][j].push_back(make_pair(i, j+1));
                }
                if (x >= 2) {
                    x -= 2;
                    if (i > 0) remove[i][j].push_back(make_pair(i-1, j));
                } else {
                    g[i][j].push_back(make_pair(i-1, j));
                }
                if (x >= 1) {
                    x -= 1;
                    if (j > 0) remove[i][j].push_back(make_pair(i, j-1));
                } else {
                    g[i][j].push_back(make_pair(i, j-1));
                }
                
            }
        }
        
        int num_comp = 0, mx = -1;
        vector<vector<int>> vis(N, vector<int>(M, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (!vis[i][j]) {
                    //cout << i << " " << j << endl;
                    ++num_comp;
                    mx = max(mx, dfs(i, j, g, vis));
                }
            }
        }
        out << num_comp << "\n" << mx << "\n";
        
        mx = -1;
        int xborder = -1, yborder = -1;
        char dir = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                for (const pair<int,int> &p : remove[i][j]) {
                    g[i][j].push_back(p);
                    g[p.first][p.second].push_back(make_pair(i, j));
                    vector<vector<int>> vis(N, vector<int>(M));
                    int t = dfs(i, j, g, vis);
                    
                    int tmp_xborder, tmp_yborder;
                    char tmp_dir;
                    if (j != p.second) {
                        tmp_xborder = i;
                        tmp_yborder = min(j, p.second);
                        tmp_dir = 'E';
                    } else if (i != p.first) {
                        tmp_xborder = max(i, p.first);
                        tmp_yborder = j;
                        tmp_dir = 'N';
                    } else {
                        assert(false);
                        g[i][j].pop_back();
                        g[p.first][p.second].pop_back();
                        continue;
                    }
                    //cout << "remove " << tmp_xborder+1 << " " << tmp_yborder+1 << " " << tmp_dir << " -> " << t << endl;
                    if (t > mx || (t >= mx && (tmp_yborder < yborder ||
                            (tmp_yborder == yborder && tmp_xborder > xborder)))) {
                        mx = t;
                        xborder = tmp_xborder;
                        yborder = tmp_yborder;
                        dir = tmp_dir;
                    }
                    
                    g[i][j].pop_back();
                    g[p.first][p.second].pop_back();
                }
            }
        }
        
        out << mx << "\n" << xborder+1 << " " << yborder+1 << " " << dir << endl;
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    castle solver;
    std::ifstream in("castle.in");
    std::ofstream out("castle.out");
    solver.solve(in, out);
    return 0;
}
