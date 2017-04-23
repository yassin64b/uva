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

class gcj_17_1B_B {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N, R, O, Y, G, B, V;
            in >> N >> R >> O >> Y >> G >> B >> V;
            if ((O && (B < O || (B == O && B + O != N))) || (G && (R < G || (R == G && R + G != N))) 
                || (V && (Y < V || (Y == V && Y + V != N)))) {
                out << "Case #" << t << ": IMPOSSIBLE\n";
                continue;
            }
            B -= O;
            R -= G;
            Y -= V;

            vector<pair<int, char>> v{{R, 'R'}, {Y, 'Y'}, {B, 'B'}};

            string res;
            for (int i = 0; i < N - 2*O - 2*G - 2*V; ) {
                sort(v.begin(), v.end(), greater<pair<int, char>>());
                if (v[0].first > max(v[1].first, v[2].first)) {
                    res += v[0].second;
                    res += v[1].second;
                    --v[0].first;
                    --v[1].first;
                    i += 2;
                } else {
                    for (int k = 2; k >= 0; --k) {
                        if (v[k].first) {
                            for (int j = 0; j <= k; ++j) {
                                res += v[j].second;
                                --v[j].first;
                            }
                            i += k + 1;
                            break;
                        }
                    }
                }
            }
            //cout << res << endl;
            out << "Case #" << t << ": ";
            for (int i = 0; i < (int)res.size(); ++i) {
                if (res[i] == res[(i+1)%((int)res.size())]) {
                    goto next_test;
                }
            }
            goto passed;
            next_test:;
            swap(res[(int)res.size()-1], res[(int)res.size()-2]);
            //cout << res << endl;
            for (int i = 0; i < (int)res.size(); ++i) {
                if (res[i] == res[(i+1)%((int)res.size())]) {
                    out << "IMPOSSIBLE\n";
                    goto next_case;
                }
            }
            passed:;
            for (int i = 0; i < (int)v.size(); ++i) {
                if (v[i].first != 0) {
                    out << "IMPOSSIBLE\n";
                    goto next_case;
                }
            }
            for (int i = 0; i < (int)res.size(); ++i) {
                if (res[i] == 'B') {
                    string tmp;
                    for (int j = 0; j < O; ++j) {
                        tmp += "OB";
                    }
                    O = 0;
                    res.insert(i+1, tmp);
                }
                if (res[i] == 'R') {
                    string tmp;
                    for (int j = 0; j < G; ++j) {
                        tmp += "GR";
                    }
                    G = 0;
                    res.insert(i+1, tmp);
                }
                if (res[i] == 'Y') {
                    string tmp;
                    for (int j = 0; j < V; ++j) {
                        tmp += "VY";
                    }
                    V = 0;
                    res.insert(i+1, tmp);
                }
            }
            for (int j = 0; j < O; ++j) {
                res += "OB";
            }
            for (int j = 0; j < G; ++j) {
                res += "GR";
            }
            for (int j = 0; j < V; ++j) {
                res += "VY";
            }

            out << res << "\n";
            next_case:;
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    gcj_17_1B_B solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
