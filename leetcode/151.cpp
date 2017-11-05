void work(string &s, int i, int j) {
    while (i < j) {
        swap(s[i], s[j]);
        ++i, --j;
    }
}
class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        int i = 0, l = -1, cnt = 0;
        while (i < n) {
            while (i < n && s[i] == ' ') ++i;
            if (i == n) break;
            if (cnt)    s[++l] = ' ';
            int j = l;
            while (i < n && s[i] != ' ') s[++l] = s[i++];
            ++cnt;
            work(s, j + 1, l);
        }
        s.resize(l + 1);
        work(s, 0, l);
    }
};