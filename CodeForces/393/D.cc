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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int,int>> vii;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        
        vector<int> t(n+1);
        for (int i = 1; i <= n; ++i) {
            in >> t[i];
        }
        t[0] = t[1];
        
        vector<int> dp(n+1);

        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i-1] + 20;
            
            //find -90minutes +
            int time = t[i] - 90 + 1;
            vector<int>::iterator low = lower_bound(t.begin(), t.end(), time);
            int ind = low - t.begin();
            
            if ((ind > 0 ? dp[ind-1] : 0) + 50 < dp[i]) {
                dp[i] = (ind > 0 ? dp[ind-1] : 0) + 50;
            }
            
            //find -1440minutes +
            time = t[i] - 1440 + 1;
            low = lower_bound(t.begin(), t.end(), time);
            ind = low - t.begin();
    
            if ((ind > 0 ? dp[ind-1] : 0) + 120 < dp[i]) {
                dp[i] = (ind > 0 ? dp[ind-1] : 0) + 120;
            }
            
            out << dp[i] - dp[i-1] << "\n";
        }
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