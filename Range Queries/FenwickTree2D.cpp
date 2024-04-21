struct FenwickTree2D {
    int n, m;
    vector<vector<int>> bit;

    FenwickTree2D(int n, int m) : n(n), m(m), bit(n + 1, vector<int>(m + 1)) {}

    void upd(int r, int c, int x) {
        for (++r; r <= n; r += r & -r) {
            for (int j = c + 1; j <= m; j += j & -j) {
                bit[r][j] += x;
            }
        }
    }

    int qry(int r, int c) {
        int res = 0;
        for (++r; r; r -= r & -r) {
            for (int j = c + 1; j; j -= j & -j) {
                res += bit[r][j];
            }
        }
        return res;
    }

    int qry(int r1, int c1, int r2, int c2) {
        return qry(r2, c2) - qry(r1 - 1, c2) - qry(r2, c1 - 1) + qry(r1 - 1, c1 - 1);
    }
};
