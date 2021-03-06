#include <bits/stdc++.h>

using namespace std;

class B478 {
private:
    inline long long num_friends(long long team_sz) {
        return team_sz * (team_sz - 1) / 2;
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        int largest_team = n - m + 1;
        long long kmax = num_friends(largest_team);
        int mid_team_a = n / m, mid_team_b = (n + m - 1) / m;
        int num_b = n % m, num_a = m - num_b;
        long long kmin = num_a * num_friends(mid_team_a) + num_b * num_friends(mid_team_b);
        out << kmin << " " << kmax << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    B478 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
