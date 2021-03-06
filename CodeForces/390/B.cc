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

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        vector<string> field(4);
        for (int i = 0; i < 4; ++i) {
            in >> field[i];
        }
        
        int numx = 0, numo = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (field[i][j] == 'x') {
                    ++numx;
                } else if (field[i][j] == 'o') {
                    ++numo;
                }
            }
        }
        
        char c;
        if (numx == numo) {
            //got x
            c = 'x';
        } else {
            //got o
            c = 'o';
        }
        
        
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 2; ++j) {
                int cnt1 = (field[i][j+0] == c) + (field[i][j+1] == c) + (field[i][j+2] == c);
                int cnt2 = (field[i][j+0] == '.') + (field[i][j+1] == '.') + (field[i][j+2] == '.');
                if (cnt1 == 2 && cnt2 == 1) {
                    out << "YES" << endl;
                    return;
                }
            }
        }
        
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 2; ++i) {
                int cnt1 = (field[i+0][j] == c) + (field[i+1][j] == c) + (field[i+2][j] == c);
                int cnt2 = (field[i+0][j] == '.') + (field[i+1][j] == '.') + (field[i+2][j] == '.');
                if (cnt1 == 2 && cnt2 == 1) {
                    out << "YES" << endl;
                    return;
                }
            }
        }
        
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                int cnt1 = (field[i][j] == c) + (field[i+1][j+1] == c) + (field[i+2][j+2] == c);
                int cnt2 = (field[i][j] == '.') + (field[i+1][j+1] == '.') + (field[i+2][j+2] == '.');
                //out << "check: " << i << " " << j << " to " << i+2 << " " << j+2 << endl;
                if (cnt1 == 2 && cnt2 == 1) {
                    out << "YES" << endl;
                    return;
                }
                cnt1 = (field[3-i][j] == c) + (field[3-(i+1)][j+1] == c) + (field[3-(i+2)][j+2] == c);
                cnt2 = (field[3-i][j] == '.') + (field[3-(i+1)][j+1] == '.') + (field[3-(i+2)][j+2] == '.');
                //out << "check: " << 3-i << " " << 1-j << " to " << 3-(i+2) << " " << 1-j+2 << endl;
                if (cnt1 == 2 && cnt2 == 1) {
                    out << "YES" << endl;
                    return;
                }
            }
        }
        out << "NO" << endl;
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
