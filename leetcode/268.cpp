class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(auto& x : nums) sum += x;
        return (1 + n) * n / 2 - sum;
    }
};