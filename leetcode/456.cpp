class Solution {
public:
    bool find132pattern(vector<int>& a) {
         multiset<int> S;
         int n = a.size();
         if (!n)    return 0;
         int mn = a[0];
         for (auto x : a)   S.insert(x);
         S.erase(S.find(a[0]));
         for (int i = 1; i < n; ++i) {
            S.erase(S.find(a[i]));
            if (mn < a[i]) {
                auto it = S.lower_bound(mn + 1);
                if (it != S.end() && *it < a[i])    return 1;
            }
            mn = min(mn, a[i]);
         }
         return 0;
    }
};