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

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

class TaskA {
    int sign(long long x) {
        return (x >= 0 ? 1 : -1);
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 0; t < T; ++t) {
            int x, y, p, q;
            in >> x >> y >> p >> q;
            
            if ((p == q && x != y) || (p == 0 && x != 0)) {
                out << -1 << "\n";
                continue;
            }
            
            /*long long b = lcm(y, q);
            long long a = x * (b / y);
            long long d = b;
            long long c = p * (d / q);
            cout << a << "/" << b << " " << c << "/" << d << endl;
            out << a - x + b - (a - x) - y << "\n";*/
            
            long long low = 0, high = 1000 * 1000 * 1000, ans = high * high;
            while (low <= high) {
                long long mid = (low + high) / 2;
                long long a = p * mid, b = q * mid;
                long long diff1 = a - x, diff2 = b - y;
                if (diff1 <= diff2 && diff1 >= 0) {
                    //cout << a << "/" << b << endl;
                    ans = min(ans, diff2);
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            /*long long a = p, b = q;
            while (true) {
                long long diff1 = a - x, diff2 = b - y;
                if (diff1 <= diff2 && diff1 >= 0) {
                    //cout << a << "/" << b << endl;
                    out << abs(diff2) << "\n";
                    break;
                }
                a += p;
                b += q;
            }*/
            out << ans << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}