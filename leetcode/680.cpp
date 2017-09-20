class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size(), cnt = 0;
        int x = 0, y = n - 1;
        while (y > x) {
            if (s[x] == s[y])   ++x, --y;
            else break;
        }
        int xx = x + 1, yy = y;
        while (yy > xx) {
            if (s[xx] == s[yy]) ++xx, --yy;
            else break;
        }
        if (xx >= yy)   return 1;
        xx = x, yy = y - 1;
        while (yy > xx) {
            if (s[xx] == s[yy]) ++xx, --yy;
            else break;
        }
        return xx >= yy;
    }
};