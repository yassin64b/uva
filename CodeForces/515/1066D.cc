#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n, m, k;
        in >> n >> m >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        int low = 0, high = n - 1, ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            int cur = 0, num = 0;
            for (int i = mid; i < n; ++i) {
                if (cur + a[i] > k) {
                    cur = a[i];
                    ++num;
                } else {
                    cur += a[i];
                }
            }
            num += (cur > 0);
            if (num <= m) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        out << n - ans << "\n";
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
