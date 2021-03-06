#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            in >> c[i];
        }
        long long cur_cost_per_min = 0, res = 0;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; ++i) {
            pq.emplace(c[i], i);
            cur_cost_per_min += c[i];
            res += cur_cost_per_min;
        }
        vector<int> t(n, -1);
        for (int i = k; i < k + n; ++i) {
            if (i < n) {
                pq.emplace(c[i], i);
                cur_cost_per_min += c[i];
            }
            res += cur_cost_per_min;
            auto [cost, j] = pq.top();
            pq.pop();
            res -= cost;
            cur_cost_per_min -= cost;
            t[j] = i + 1;
        }
        out << res << "\n";
        for (int i = 0; i < n; ++i) {
            out << t[i] << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
