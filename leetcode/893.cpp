class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<pair<string, string> > S;
        for (auto s: A) {
            pair<string, string> t;
            for (int i = 0; i < s.size(); i += 2)
                t.first += s[i];
            for (int i = 1; i < s.size(); i += 2)
                t.second += s[i];
            sort(t.first.begin(), t.first.end());
            sort(t.second.begin(), t.second.end());
            S.insert(t);
        }
        return S.size();
    }
};
