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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int,int>> vii;

constexpr double PI = 3.14159265359;

class fbA {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        
        for (int t = 1; t <= T; ++t) {
            int P, X, Y;
            in >> P >> X >> Y;
            out << "Case #" << t << ": ";
            
            if (P == 0) {
                out << "white\n";
                continue;
            }
            if (X == 50 && Y == 50) {
                out << "black\n";
                continue;
            }
            
            double radius = 50.;
            double umfang = 2. * PI * radius;
            
            double angle = (P / 100.) * 360;
            
            double A = sqrt((X - 50) * (X - 50) + (Y - 100) * (Y - 100));
            double B = 50.;
            double C = sqrt((X - 50) * (X - 50) + (Y - 50) * (Y - 50));
            if (C > radius) {
                out << "white\n";
                continue;
            }
            
            //out << A << " " << B << " " << C << endl;
            
            //cosinussatz
            double res = acos((A*A - B*B - C*C) / (-2*B*C)) * 180 / PI;
            if (X < 50) {
                res = 360 - res;
            }
            
            //out << angle << " " << X << " " << Y << " -> " << A << " " << B << " " << C << " " << res << " < " << angle << "? ";
            if (res < angle) {
                out << "black\n";
            } else {
                out << "white\n";
            }
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    fbA solver;
    std::ifstream in("progress_pie.in");
    std::ofstream out("progress_pie.out");

    //std::istream& in(std::cin);
    //std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}

