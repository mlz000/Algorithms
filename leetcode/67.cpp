class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.size() - 1, lb = b.size() - 1, c = 0;
        string ans = "";
        while (la >= 0 || lb >= 0 || c) {
            int now = (la >= 0 ? a[la--] -'0' : 0) + (lb >= 0 ? b[lb--] - '0' : 0) + c;
            ans += (now % 2) + '0';
            c = now / 2;
            cout << ans << endl;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};