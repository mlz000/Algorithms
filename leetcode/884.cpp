class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int n = S.size();
        int l = 0;
        string now = "";
        for (int i = 0; i < n; ++i) {
            if (S[i] >= '2' && S[i] <= '9') {
                int x = S[i] - '0';
                if ((long long)l * x >= K) {
                    return decodeAtIndex(S.substr(0, l), (K - 1) % l + 1);
                }
                l *= x;
            }
            else {
                ++l;
                now += S[i];
                if (l == K) return string("") + S[i];
            }
        }
    }
};
