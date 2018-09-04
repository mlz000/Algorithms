class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> ans;
        stringstream ss(A + " " + B);
        unordered_map<string, int> mp;
        string s;
        while (ss >> s) ++mp[s];
        for (auto& pair: mp)
            if (pair.second == 1)
                ans.push_back(pair.first);
        return ans;
    }
};
