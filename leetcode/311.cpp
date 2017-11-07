class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(), m = A[0].size(), l = B[0].size();
        vector<vector<int> > c(n, vector<int>(l, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (A[i][j] == 0)   continue;
                for (int k = 0; k < l; ++k)
                    if (B[j][k] != 0) 
                        c[i][k] += A[i][j] * B[j][k];
            }
        return c;
    }
};