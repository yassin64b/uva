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

class kickA {
private:
    int modPow(int a, int b, int c){
        long long x = 1, y = a;
        while (b > 0){
            if (b%2 == 1){
                x = (x*y) % c;
            }
            y = (y*y) % c;
            b /= 2;
        }
        return x % c;
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int A, N, P;
            in >> A >> N >> P;
            for (int i = 1; i <= N; ++i) {
                A = modPow(A, i, P);
            }
            out << "Case #" << t << ": " << A << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    kickA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
