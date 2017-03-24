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

class uva11264 {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int n;
            in >> n;
            vector<int> C(n);
            for (int i = 0; i < n; ++i) {
                in >> C[i];
            }
            
            int res = 0, cnt = 0;
            long long sum = 0;
            
            for (int i = 0; i < n; ++i) {
                if (C[i] > sum) {
                    //cout << "take " << C[i] << endl;
                    sum += C[i];
                    ++cnt;
                    res = max(res, cnt);
                } else {
                    int j = i-1;
                    while (sum >= C[i]) {
                        //cout << "remove " << C[j] << endl;
                        sum -= C[j];
                        --j;
                        --cnt;
                    }
                    //cout << "take- " << C[i] << endl;
                    sum += C[i];
                    ++cnt;
                    res = max(res, cnt);
                }
            }
            
            out << res << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    uva11264 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}