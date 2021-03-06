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

class C466 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        
        long long sum = 0;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            sum += a[i];
        }
        if (sum % 3 != 0) {
            out << 0 << endl;
            return;
        }
        long long target = sum / 3;
        
        vector<long long> suffix(n, 0);
        long long cur = 0;
        for (int i = n-1; i >= 0; --i) {
            cur += a[i];
            if (cur == target) {
                suffix[i] = 1;
            }
        }
        for (int i = n-2; i >= 0; --i) {
            suffix[i] += suffix[i+1];
        }
        /*for (int i = 0; i < n; ++i) {
            cout << suffix[i] << " ";
        }*/
        
        long long res = 0;
        cur = 0;
        for (int i = 0; i+2 < n; ++i) {
            cur += a[i];
            if (cur == target) {
                res += suffix[i+2];
            }
        }
        
        out << res << endl;
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    C466 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
