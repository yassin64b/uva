/*
ID: yassin.2
PROG: ariprog
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
#include <unordered_set>

using namespace std;

class ariprog {
public:
    void solve(istream& in, ostream& out) {
        int N, M;
        in >> N >> M;
        
        int MX = M*M*2;
        vector<int> bisqlist;
        vector<bool> bisqs(MX+1, false);
        for (int p = 0; p <= M; ++p) {
            for (int q = 0; q <= M; ++q) {
                if (!bisqs[p*p + q*q]) {
                    bisqlist.push_back(p*p + q*q);
                }
                bisqs[p*p + q*q] = true;
            }
        }
        //sort(bisqlist.begin(), bisqlist.end());
        
        vector<pair<int,int>> res;
        for (int j = 0; j < (int)bisqlist.size(); ++j) {
            int a = bisqlist[j];
            for (int b = 1; b <= (MX-a)/(N-1); ++b) { //a + b*(N-1) <= MX
                bool flag = true;
                for (int i = 1; flag && i < N; ++i) {
                    if (!bisqs[a + i*b]) {
                        flag = false;
                    }
                }
                if (flag) {
                    res.push_back(make_pair(b, a));
                }
            }
        }
        /*for (int a = 0; a <= MX; ++a) {
            if (bisqs[a]) {
                
            }
        }*/
        
        if (res.size() == 0) {
            out << "NONE\n";
        } else {
            sort(res.begin(), res.end());
            for (pair<int,int> &p : res) {
                out << p.second << " " << p.first << "\n";
            }
        }
        
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    ariprog solver;
    std::ifstream in("ariprog.in");
    std::ofstream out("ariprog.out");
    solver.solve(in, out);
    return 0;
}
