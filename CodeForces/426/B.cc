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
        int n, k;
        in >> n >> k;
        string s;
        in >> s;
        vector<pair<int, int>> ent(26, {-1, -1});
        for (int i = 0; i < n; ++i) {
            int ind = s[i] - 'A';
            if (ent[ind].first == -1)
                ent[ind].first = i;
            ent[ind].first = min(ent[ind].first, i);
            if (ent[ind].second == -1)
                ent[ind].second = i;
            ent[ind].second = max(ent[ind].second, i);
        }
        vector<int> bal(2 * n, 0);
        for (int i = 0; i < 26; ++i) {
            if (ent[i].first == -1 || ent[i].second == -1)
                continue;
            ++bal[2 * ent[i].first];
            --bal[2 * ent[i].second + 1];
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += bal[2 * i];
            if (sum > k) {
                out << "YES\n";
                return;
            }
            sum += bal[2 * i + 1];
        }
        out << "NO\n";
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