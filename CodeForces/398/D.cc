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
#include <unordered_map>

using namespace std;

constexpr int MAXN{1000*1000*10};

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n, m, k;
        in >> n >> m >> k;
        vector<int> f(MAXN+1, 0);
        //map<int,int> f;
        for (int i = 0; i < n; ++i) {
            int x;
            in >> x;
            ++f[x];
        }
        vector<vector<int>> sind(MAXN+1);
        //map<int,vector<int>> sind;
        for (int i = 0; i < m; ++i) {
            int x;
            in >> x;
            sind[x].push_back(i);
        }
        vector<int> after(MAXN+1);
        after[MAXN] = sind[MAXN].size();
        for (int i = MAXN-1; i >= 0; --i) {
            after[i] = sind[i].size();
            after[i] += after[i+1];
        }
        
        vector<int> free(MAXN+1);
        for (int i = 0; i <= MAXN; ++i) {
            free[i] = k - f[i];
        }
        for (int i = MAXN; i > 0; --i) {
            if (free[i] < 0) {
                free[i-1] += free[i];
            }
        }
        if (free[0] < 0) {
            out << "-1\n";
            return;
        }
        
        int subtract = 0;
        for (int i = MAXN; i >= 0; --i) {
            if (free[i] > 0 && after[i] - subtract > 0) {
                int tmp = min(free[i], after[i] - subtract);
                subtract += tmp;
            }
        }
        
        out << subtract << "\n";
        int ind = MAXN;
        while (subtract > 0) {
            for (int i = 0; subtract > 0 && i < (int)sind[ind].size(); ++i, --subtract) {
                out << sind[ind][i]+1 << " ";
            }
            --ind;
        }
        out << endl;
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
