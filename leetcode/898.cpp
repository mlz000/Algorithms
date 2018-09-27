class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> last, cur, ans;
        for (auto x: A) {
            cur = {x};
            for (auto y: last)  cur.insert(y | x);
            for (auto y: cur)   ans.insert(y);
            last = cur;
        }
        return ans.size();
    }
};
