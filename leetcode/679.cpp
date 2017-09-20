/*
You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.
*/
class Solution {
public:
    bool ok = 0;
    void dfs(vector<double> a) {
        if (a.size() == 1) {
            ok |= (fabs(a[0] - 24) < 1e-8);
            return;
        }

        for (int i = 0; i < a.size(); ++i)
            for (int j = 0; j < a.size(); ++j) {
                if (i == j) continue;
                vector<double> b;                
                for (int k = 0; k < a.size(); ++k)
                    if (i != k && k != j) 
                        b.push_back(a[k]);
                b.push_back(a[i] + a[j]);
                dfs(b);
                b[b.size() - 1] =  a[i] - a[j];
                dfs(b);
                b[b.size() - 1] = a[i] * a[j];
                dfs(b);
                if (fabs(a[j]) > 1e-8) {
                    b[b.size() - 1] = a[i] / a[j];
                    dfs(b);
                }
            }
        
    }
    
    bool judgePoint24(vector<int>& a) {
        vector<double> b;
        for (auto& x : a) b.push_back(x);
        dfs(b);
        return ok;
    }
};