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
#include <sstream>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n, T;
        in >> n >> T;
        vector<int> a(n), t(n);
        map<int, vector<pair<int ,int>>> m;
        for (int i = 0; i < n; ++i) {
            in >> a[i] >> t[i];
            m[a[i]].push_back({t[i], i});
        }
        priority_queue<pair<int, int>> pq;
        int sum = 0, res = 0;
        for (int k = n; k >= 0; --k) {
            while ((int)pq.size() > k) {
                sum -= pq.top().first;
                pq.pop();
            }
            for (pair<int, int> p : m[k]) {
                int tt = p.first;
                if (sum + tt > T || (int)pq.size() == k) {
                    if (!pq.empty() && pq.top().first > tt) {
                        sum -= pq.top().first;
                        pq.pop();
                        sum += tt;
                        pq.push(p);
                    }
                } else {
                    sum += tt;
                    pq.push(p);
                }
            }
            res = max(res, (int)pq.size());
        }
        out << res << "\n" << res << "\n";
        
        pq = priority_queue<pair<int, int>>();
        sum = 0;
        for (int k = n; k >= 0; --k) {
            while ((int)pq.size() > k) {
                sum -= pq.top().first;
                pq.pop();
            }
            for (pair<int, int> p : m[k]) {
                int tt = p.first;
                if (sum + tt > T || (int)pq.size() == k) {
                    if (!pq.empty() && pq.top().first > tt) {
                        sum -= pq.top().first;
                        pq.pop();
                        sum += tt;
                        pq.push(p);
                    }
                } else {
                    sum += tt;
                    pq.push(p);
                }
            }
            if ((int)pq.size() == res) {
                vector<int> p;
                while (!pq.empty()) {
                    p.push_back(pq.top().second + 1);
                    pq.pop();
                }
                for (int x : p)
                    out << x << " ";
                out << "\n";
                return;
            }
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
