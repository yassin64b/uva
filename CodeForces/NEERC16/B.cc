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

class B730 {
private:
    bool askSmaller(int a, int b) {
        cout << "? " << a << " " << b << endl;
        char ans;
        cin >> ans;
        return (ans == '<');
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        cin >> T;
        
        for (int t = 1; t <= T; ++t) {
            int n;
            cin >> n;
            
            int mn = 1, mx = 1, ind = 2;
            if (n % 2 == 0) {
                if (askSmaller(1, 2)) {
                    mx = 2;
                } else {
                    mn = 2;
                }
                ++ind;
            }
            for (; ind < n; ind += 2) {
                if (askSmaller(ind, ind+1)) {
                    if (askSmaller(ind, mn)) {
                        mn = ind;
                    }
                    if (askSmaller(mx, ind+1)) {
                        mx = ind+1;
                    }
                } else {
                    if (askSmaller(ind+1, mn)) {
                        mn = ind+1;
                    }
                    if (askSmaller(mx, ind)) {
                        mx = ind;
                    }
                }
            }
            
            cout << "! " << mn << " " << mx << endl;
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    B730 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
