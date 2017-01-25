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
#include <cassert>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        vector<bool> prime(50001, true);
        for (int p=2; p*p<=50001; p++)
        {
            // If prime[p] is not changed, then it is a prime
            if (prime[p] == true)
            {
                // Update all multiples of p
                for (int i=p*2; i<=50001; i += p)
                    prime[i] = false;
            }
        }
        vector<int> primes;
        for (int i = 2; i < 50001; ++i) {
            if (prime[i]) primes.push_back(i);
        }
        //cout << primes.size() << endl;
    
    
        int n;
        in >> n;
        
        vector<int> s(n);
        for (int i = 0; i < n; ++i) {
            in >> s[i];
        }

        int res = 1;
        for (size_t i = 0; i < primes.size(); ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (s[j] % primes[i] == 0) {
                    ++cnt;
                }
            }
            res = max(res, cnt);
        }
        
        
        map<int,int> cnt;
        for (int i = 0; i < n; ++i) {
            cnt[s[i]]++;
            if (s[i] != 1) res = max(res, cnt[s[i]]);
        }
        out << res << endl;
    }
};



int main() {
    std::ios::sync_with_stdio(false);

    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}