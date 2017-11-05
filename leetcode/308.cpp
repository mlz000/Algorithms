#define pb push_back
class NumMatrix {
public:
    vector<vector<int> > c, a;
    int n, m;
    void add(int x, int y, int t) {
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= m; j += j & -j)
                c[i][j] += t;
    }
    
    int ask(int x, int y) {
        if (x == 0 || y == 0)   return 0;
        int t = 0;
        for (int i = x; i ; i -= i & -i)
            for (int j = y; j; j -= j & -j)
                t += c[i][j];
        return t;
    }
    
    NumMatrix(vector<vector<int>> matrix) {
        n = matrix.size();
        if (n == 0) m = 0;
        else m = matrix[0].size();
        this -> a = matrix;
        c.resize(n + 1);
        for (int i = 1; i <= n; ++i)    c[i] = vector<int> (m + 1, 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                add(i + 1, j + 1, matrix[i][j]);
    }
    
    void update(int row, int col, int val) {
        add(row + 1, col + 1, val - a[row][col]);
        a[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return ask(row2 + 1, col2 + 1) - ask(row2 + 1, col1) - ask(row1, col2 + 1) + ask(row1, col1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */