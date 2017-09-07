class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> cnt;
        for (auto& x : a)   ++cnt[x];
       vector<int> ans;
        for (auto& x : b)
            if (cnt[x]-- > 0)
                ans.push_back(x);
        return ans;
    }
};