#include <bits/stdc++.h>

using namespace std;

class TaskE {
private:
    long long b(long long n) {
        if (n == 0) {
            return 0;
        }
        return 2 * b(n / 2) + (n + 1) / 2;
    }
public:
    void solve(istream& in, ostream& out) {
        long long n;
        in >> n;
        long long res = b(n - 1);
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
