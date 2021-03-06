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

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        
        set<int> st;
        int res = 0, top = 0, un = -1;
        for (int i = 0; i < 2*n; ++i) {
            string s;
            in >> s;
            if (s == "add") {
                int x;
                in >> x;
                if (!st.empty() && x > *st.begin()) {
                    un = *st.begin();
                }
                st.insert(x);
                top = x;
            } else {
                if (top != *st.begin() || top == un) {
                    ++res;
                    //cout << i << " " << top << " " << *st.begin() << endl;
                }
                st.erase(st.begin());
                top = *st.begin();
            }
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
