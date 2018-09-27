class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<pair<int, int> > s;
        for (int i = 0; i < B.size(); ++i)    s.insert(make_pair(B[i], i));
        vector<int> tmp, ans;
        ans.clear();
        for (auto x : A) {
            auto it = s.lower_bound(make_pair(x, 0));
            if (it == s.begin()) {
                auto t = *s.rbegin();
                tmp.push_back(t.second);
                s.erase(--s.end());
            }
            else {
                --it;
                tmp.push_back((*it).second);
                s.erase(it);
            }
        }
        ans.resize(A.size());
        for (int i = 0; i < A.size(); ++i)
            ans[tmp[i]] = A[i];
        return ans;
    }
};
