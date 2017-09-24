set<int> S;
class Solution {
public:
    int kEmptySlots(vector<int>& a, int k) {
        int n = a.size(); 
        if (n < 2)  return -1;
        S.clear();
        S.insert(a[0]), S.insert(a[1]);
        if (max(a[1], a[0]) - min(a[1], a[0]) - 1 == k) return 2;
        for (int i = 2; i < n; ++i) {
            S.insert(a[i]);
            auto it = S.lower_bound(a[i]);
            auto it2 = --it;
            auto it3 = S.lower_bound(a[i] + 1);
            if (it2 != S.begin() && a[i] - (*it2) - 1 == k) return i + 1;
            if (it3 != S.end() && (*it3) - a[i] - 1 == k)   return i + 1;
        }
        return -1;
    }
};