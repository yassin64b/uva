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

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0 && a[i] >= 0) {
                sum += a[i];
            }
        }
        
        vector<int> pos_odds, neg_odds;
        for (int i = 0; i < n; ++i) {
            if ((a[i] % 2 + 2) % 2 == 1) {
                if (a[i] < 0) {
                    neg_odds.push_back(a[i]);
                } else {
                    pos_odds.push_back(a[i]);
                }
            }
        }
        sort(pos_odds.begin(), pos_odds.end(), greater<int>());
        sort(neg_odds.begin(), neg_odds.end(), greater<int>());
        
        if (pos_odds.empty()) {
            sum += neg_odds[0];
        } else if (pos_odds.size() % 2 == 1) {
            sum += accumulate(pos_odds.begin(), pos_odds.end(), 0);
        } else {
            sum += accumulate(pos_odds.begin(), --pos_odds.end(), 0);
            if (!neg_odds.empty() && pos_odds.back() + neg_odds.front() > 0) {
                sum += pos_odds.back() + neg_odds.front();
            }
        }
        
        out << sum << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}