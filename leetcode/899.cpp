class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        else {
            string ans = S;
            for (int i = 1; i <= S.size(); ++i) {
                string now = S.substr(i) + S.substr(0, i);
                ans = min(ans, now);
            }
            return ans;
        }
    }
};
