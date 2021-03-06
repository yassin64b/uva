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
        int n;
        in >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        
        if (n == 1) {
            out << "NO\n";
            return;
        }
        
        vector<long long> sum(n);
        sum[0] = a[0];
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i-1] + a[i];
        }
        
        multiset<long long> s1, s2(a.begin(), a.end());
        
        for (int i = -1; i < n; ++i) {
            if (i >= 0) {
                s1.insert(a[i]);
                s2.erase(s2.find(a[i]));
            }
            long long sum1 = (i >= 0 ? sum[i] : 0);
            long long sum2 = sum[n-1] - sum1;
            if (i >= 0 && i < n-1 && sum1 == sum2) {
                out << "YES\n";
                return;
            } else {
                long long diff = abs(sum1 - sum2);
                if (diff % 2 == 0 && ((sum1 < sum2 && s2.find(diff / 2) != s2.end()) ||
                        (sum1 > sum2 && s1.find(diff / 2) != s1.end()))) {
                    //cout << sum[i] << " " << sum[n-1] << " " << diff/2 << endl;
                    out << "YES\n";
                    return;
                }
            }
        }
        out << "NO\n";
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
