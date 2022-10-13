class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long sum = 0;
        int mx = 0, mx_cost;
        for (auto pair: transactions) {
            if (pair[0] > pair[1]) {
                sum += pair[0] - pair[1];
                mx = max(mx, pair[1]);
            } else {
                mx_cost = max(mx_cost, pair[0]);
            }
        }
        return sum + max(mx, mx_cost);
    }
};
