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

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int k;
        in >> k;
        string s;
        in.ignore();
        getline(in, s);
        int n = s.size();
        
        int low = 1, high = n, ans = n;
        while (low <= high) {
            int len = (low + high) / 2;
            //cout << len << endl;
            
            int cnt = 0;
            for (int i = 0; i < n; ) {
                if (i + len >= n) {
                    ++cnt;
                    break;
                }
                int last_split = -1;
                for (int j = i; j < i + len; ++j) {
                    if (s[j] == '-' || s[j] == ' ') {
                        last_split = j;
                    }
                }
                if (last_split == -1) {
                    //cout << "goto " << i << endl;
                    goto unsucc;
                }
                //cout << '\t' << i << " " << last_split << endl;
                i = last_split + 1;
                ++cnt;
            }
            //cout << cnt << endl;
            
            if (cnt > k) {
                unsucc:
                low = len + 1;
            } else {
                high = len - 1;
                //cout << "poss" << endl;
                ans = len;
            }
        }
        out << ans << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
