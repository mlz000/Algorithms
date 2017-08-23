class NumMatrix {
public:
    NumMatrix(vector<vector<int>> a) {
       n = a.size();
       m = n > 0 ? a[0].size() : 0;
       sum.resize(n + 1, vector<int>(m + 1));
       for (int i = 1; i <= n; ++i) 
           for (int j = 1; j <= m; ++j)
               sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i - 1][j - 1];
    }
    
    int sumRegion(int x1, int y1, int x2, int y2) {
        ++x1, ++y1, ++x2, ++y2;
        return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1]; 
    }
private:
    int n, m;
    vector<vector<int> > sum;
};