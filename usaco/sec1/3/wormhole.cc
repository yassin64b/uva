/*
ID: yassin.2
PROG: wormhole
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

class wormhole {
private:
    int backtrack(int i, vector<pair<int,int>> &v, vector<int> &m,
                  map<int,vector<int>> &row) {
        if (i >= (int)v.size()) {
            //check solution
            /*cout << "check: ";
            for (int i = 0; i < (int)m.size(); ++i) {
                cout << "(" << i << "," << m[i] << ") ";
            }
            cout << "\n";*/
            for (int j = 0; j < (int)v.size(); ++j) {
                vector<int> vis(v.size(), 0);
                int ind = m[j];
                bool flag2 = true;
                while (!vis[ind]) {
                    vis[ind] = 1;
                    bool flag = false;
                    for (int &nextind : row[v[ind].second]) {
                        if (v[nextind].first > v[ind].first) {
                            ind = m[nextind];
                            flag = true;
                            break;
                        }
                    }
                    if (!flag) {
                        flag2 = false;
                        break;
                    }
                }
                if (flag2) {
                    //cout << j << " successfull\n";
                    return 1;
                }
            }
            return 0;
        }
        if (m[i] != -1) {
            return backtrack(i+1, v, m, row);
        }
        int res = 0;
        for (int j = 0; j < (int)v.size(); ++j) {
            if (m[j] == -1 && i != j) {
                m[i] = j;
                m[j] = i;
                res += backtrack(i+1, v, m, row);
                m[i] = -1;
                m[j] = -1;
            }
        }
        return res;
    }
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        
        map<int,vector<int>> row;
        vector<pair<int,int>> v;
        for (int i = 0; i < N; ++i) {
            int x, y;
            in >> x >> y;
            v.push_back(make_pair(x, y));
            row[y].push_back(i);
            sort(row[y].begin(), row[y].end(), [&](const int &lhs, const int &rhs) {
                return v[lhs].first < v[rhs].first;
            });
        }
        
        vector<int> m(N, -1);
        out << backtrack(0, v, m, row) << endl;
        
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    wormhole solver;
    std::ifstream in("wormhole.in");
    std::ofstream out("wormhole.out");
    solver.solve(in, out);
    return 0;
}
