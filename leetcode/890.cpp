class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (auto s: words) {
            bool ok = true;
            unordered_map<char, char> mp;
            unordered_map<char, bool> vis;
            for (int i = 0; i < s.size(); ++i) {
                if (mp.find(s[i]) == mp.end()) {
                    if (!vis[pattern[i]])   mp[s[i]] = pattern[i]; 
                    else {
                        ok = false;
                        break;
                    }
                    vis[pattern[i]] = 1;
                }
                else {
                    if (mp[s[i]] != pattern[i]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) ans.push_back(s);
        }
        return ans;
    }
};
