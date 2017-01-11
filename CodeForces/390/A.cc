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

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        
        vector<int> a(n);
        bool flag = false;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            flag = flag || a[i];
            sum += a[i];
        }
        
        if (!flag) {
            out << "NO" << endl;
            return;
        }
        
        out << "YES" << endl;
        
        if (sum == 0) {
            out << 2 << endl;
            int i = 0;
            while (a[i] == 0) {
                ++i;
            }
            out << 1 << " " << i+1 << endl;
            out << i+2 << " " << n << endl;
        } else {
            out << 1 << endl;
            out << 1 << " " << n << endl;
        }
        
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
