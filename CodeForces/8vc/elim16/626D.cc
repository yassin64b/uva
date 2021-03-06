#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        sort(begin(a), end(a));
        vector<long long> num(10'002, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                num[a[j] - a[i]] += 1;
            }
        }
        vector<long long> pre(num);
        for (int i = 10'000; i >= 0; --i) {
            pre[i] += pre[i + 1];
        }
        long long sum = 0;
        for (int d1 = 1; d1 <= 5'000; ++d1) {
            for (int d2 = 1; d2 <= 5'000; ++d2) {
                if (num[d1] && num[d2]) {
                    sum += 1LL * num[d1] * num[d2] * pre[d1 + d2 + 1];
                }
            }
        }
        long long ways = n * (n - 1) / 2;
        ways = ways * ways * ways;
        out.precision(17);
        out << fixed << sum / (double)ways << endl;
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
