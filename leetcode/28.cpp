class Solution {
public:
    int strStr(string a, string b) {
        if (b.size() == 0)  return 0;
        vector<int> nxt(b.size() + 1, 0);
        nxt[0] = -1;
        int j = -1;
        for (int i = 1; i < b.size(); ++i) {
            while (j >= 0 && b[j + 1] != b[i])  j = nxt[j];
            if (b[j + 1] == b[i])   ++j;
            nxt[i] = j;
        }
        j = -1;
        for (int i = 0; i < a.size(); ++i){
            while (j >= 0 && a[i] != b[j + 1])    j = nxt[j];
            if (a[i] == b[j + 1])   ++j;  
            if (j == b.size() - 1)  return i - b.size() + 1;
        }
        return -1;
    }
};