#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        long long n, x, y;
        in >> n >> x >> y;
        if (max(x - 1, y - 1) <= max(n - x, n - y)) {
            out << "White\n";
        } else {
            out << "Black\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
