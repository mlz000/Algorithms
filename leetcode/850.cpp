typedef long long LL;
const int M = 1e9 + 7;
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rec) {
        vector<int> x; 
        for (auto a : rec) {
            x.push_back(a[0]);
            x.push_back(a[2]);
        }
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        unordered_map<int, int> pos;
        for (int i = 0; i < x.size(); ++i)  pos[x[i]] = i;
        vector<int> c(x.size(), 0);
        vector<vector<int> > op;
        for (auto a : rec) {
            int x1 = a[0], y1 = a[1], x2 = a[2], y2 = a[3];
            op.push_back({y1, x1, x2, 1});
            op.push_back({y2, x1, x2, -1});
        }
        sort(op.begin(), op.end());
        int lasty = 0, totx = 0;
        int ans = 0;
        for (auto q : op) {
            int y = q[0], x1 = q[1], x2 = q[2];
            (ans += (LL)(y - lasty) * totx % M) %= M;  
            lasty = y;
            for (int i = pos[x1]; i < pos[x2]; ++i)
                c[i] += q[3];
            totx = 0;
            for (int i = 0; i < x.size(); ++i)
                if (c[i] > 0) {
                    (totx += x[i + 1] - x[i]) %= M;
                }
        }
        return ans;
    }
};