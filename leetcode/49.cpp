class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > G;
        vector<vector<string> > ans;
        for (auto s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            G[t].push_back(s);
        }
        for (auto& it : G) {
            ans.push_back(it.second);
        }
        return ans;
    }
};