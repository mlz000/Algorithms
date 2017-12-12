class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        unordered_map<char, int> G;
        for (auto c : letters)  ++G[c];
        for (char c = target + 1; c <= 'z'; ++c)    
            if (G[c])   return c;
        for (char c = 'a'; c < target; ++c)
            if (G[c])   return c;
    }
};