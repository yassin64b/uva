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

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            in >> a[i];
        set<int> sqrs;
        for (int i = 0; 1LL * i * i <= 2LL * 1000 * 1000 * 1000; ++i)
            sqrs.insert(i * i);
        
        vector<int> cost1(n), cost2(n);
        for (int i = 0; i < n; ++i) {
            auto it = sqrs.lower_bound(a[i]);
            cost1[i] = *it - a[i];
            if (it != sqrs.begin()) {
                auto it2 = it;
                --it2;
                cost1[i] = min(cost1[i], a[i] - *it2);
            }
        
            auto it2 = it;
            cost2[i] = 0;
            while (*it2 == a[i] + cost2[i]) {
                ++cost2[i];
                ++it2;
            }
            int tmp = 0;
            it2 = it;
            while (*it2 == a[i] - tmp && it2 != sqrs.begin()) {
                ++tmp;
                ++it2;
            }
            if (*it2 != a[i] - tmp)
                cost2[i] = min(cost2[i], tmp);
            
            //cout << a[i] << ": " << cost1[i] << " " << cost2[i] << endl;
        }
        vector<pair<int, int>> diff(n);
        for (int i = 0; i < n; ++i)
            diff[i] = {cost1[i], cost2[i]};
        sort(diff.begin(), diff.end(), [](const auto& lhs, const auto& rhs) {
            return abs(lhs.first - lhs.second) < abs(rhs.first - rhs.second);
        });
        reverse(diff.begin(), diff.end());
        long long res = 0;
        int numa = n / 2, numb = n / 2;
        for (int i = 0; i < n; ++i) {
            if (numa && numb) {
                if (diff[i].first < diff[i].second)
                    res += diff[i].first, --numa;
                else
                    res += diff[i].second, --numb;
            } else if (numa)
                res += diff[i].first, --numa;
            else if (numb)
                res += diff[i].second, --numb;
            //else
                //assert(false);
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}