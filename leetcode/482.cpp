class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        for (int i = (int)S.size() - 1; i >= 0; --i) {
            if (S[i] != '-') {
                ((res.size() % (K + 1) - K) ? res : res += '-') += toupper(S[i]);
            }
        }
        return string(res.rbegin(), res.rend());
    }
};