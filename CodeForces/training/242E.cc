#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
    vector<int> _sum, _d;
    int _n;
    int lc(int node) {
        return 2 * node;
    }
    int rc(int node) {
        return 2 * node + 1;
    }
    int mid(int a, int b) {
        return (a + b) / 2;
    }
    int num(int a, int b) {
        return b - a + 1;
    }
    void build(int node, int l, int r, const vector<int> &a) {
        if (l == r) {
            _sum[node] = a[l];
        } else {
            build(lc(node), l, mid(l, r), a);
            build(rc(node), mid(l, r) + 1, r, a);
            update(node, l, r);
        }
    }
    void prop(int node) {
        _d[lc(node)] ^= _d[node];
        _d[rc(node)] ^= _d[node];
        _d[node] = 0;
    }
    void update(int node, int l, int r) {
        _sum[node] = 0;
        if (!_d[lc(node)]) {
            _sum[node] += _sum[lc(node)];
        } else {
            _sum[node] += num(l, mid(l, r)) - _sum[lc(node)];
        }
        if (!_d[rc(node)]) {
            _sum[node] += _sum[rc(node)];
        } else {
            _sum[node] += num(mid(l, r) + 1, r) - _sum[rc(node)];
        }
    }
    void update_range(int node, int l, int r, int i, int j, int val) {
        if (l > r || l > j || r < i) {
            return;
        } else if (i <= l && r <= j) {
            _d[node] ^= val;
            return;
        }
        prop(node);
        update_range(lc(node), l, mid(l, r), i, j, val);
        update_range(rc(node), mid(l, r) + 1, r, i, j, val);
        update(node, l, r);
    }
    int query_range(int node, int l, int r, int i, int j) {
        if (l > r || l > j || r < i) {
            return 0;
        } else if (i <= l && r <= j) {
            if (!_d[node]) {
                return _sum[node];
            } else {
                return num(l, r) - _sum[node];
            }
        }
        prop(node);
        int res = query_range(lc(node), l, mid(l, r), i, j);
        res += query_range(rc(node), mid(l, r) + 1, r, i, j);
        update(node, l, r);
        return res;
    }
public:
    SegmentTree(const vector<int> &a) : _n(a.size()) {
        _sum.assign(4 * _n + 1, 0);
        _d.assign(4 * _n + 1, 0);
        build(1, 0, _n - 1, a);
    }
    void update_range(int i, int j, int val) {
        update_range(1, 0, _n - 1, i, j, val);
    }
    int query_range(int i, int j) {
        return query_range(1, 0, _n - 1, i, j);
    }
};

class E242 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        vector<SegmentTree> st;
        for (int i = 0; i < 20; ++i) {
            vector<int> tmp(n);
            for (int j = 0; j < n; ++j) {
                tmp[j] = (a[j] & (1 << i)) >> i;
            }
            st.push_back(SegmentTree(tmp));
        }
        int m;
        in >> m;
        for (int j = 0; j < m; ++j) {
            int t;
            in >> t;
            if (t == 1) {
                int l, r;
                in >> l >> r;
                long long res = 0;
                for (int i = 0; i < 20; ++i) {
                    res += (1LL * st[i].query_range(l - 1, r - 1)) << i;
                }
                out << res << "\n";
            } else {
                int l, r, x;
                in >> l >> r >> x;
                for (int i = 0; i < 20; ++i) {
                    if (x & (1 << i)) {
                        st[i].update_range(l - 1, r - 1, 1);
                    }
                }
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    E242 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
