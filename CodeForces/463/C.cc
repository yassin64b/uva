#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int N, A, B;
        in >> N >> A >> B;
        for (int num_a = 0; num_a * A <= N; ++num_a) {
            if ((N - num_a * A) % B == 0) {
                int num_b = (N - num_a * A) / B;
                vector<int> perm(N, 0);
                int ind = 0;
                for (int i = 0; i < num_a; ++i) {
                    perm[i * A + A - 1] = ++ind;
                    for (int j = i * A; j + 1 < i * A + A; ++j) {
                        perm[j] = ++ind;
                    }
                }
                for (int i = 0; i < num_b; ++i) {
                    perm[num_a * A + i * B + B - 1] = ++ind;
                    for (int j = num_a * A + i * B; j + 1 < num_a * A + i * B + B; ++j) {
                        perm[j] = ++ind;
                    }
                }
                for (int x : perm) {
                    out << x << " ";
                }
                out << "\n";
                
                return;
            }
        }
        out << -1 << "\n";
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
