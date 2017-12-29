class Solution {
public:
    vector<pair<int, int> > a;
    int dominantIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            a.push_back(make_pair(-nums[i], i));
        }
        sort(a.begin(), a.end());
        int n = unique(a.begin(), a.end()) - a.begin();
        if (n <= 1 || a[0].first > a[1].first * 2)  return -1;
        return a[0].second;
    }
};