class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() == 0)  return -1;
        if (s.size() == 1)  return 0;
        vector<int> cnt(26, 0);
        for (int i = 0; i < s.size(); ++i)  cnt[s[i] - 'a']++;
        for (int i = 0; i < s.size(); ++i) {
            if (cnt[s[i] - 'a'] == 1)   return i;
        }
        return -1;
    }
};