typedef pair<long long, int> pli;
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long sum = 0ll;
        for (auto &x : nums) {
            if (x > 0)  sum += x;
            x = abs(x);
        }
        if (k-- == 1) return sum;
        sort(nums.begin(), nums.end());
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push(make_pair(nums[0], 0));
        // pair(a, b) The last select element is nums[b], current sum = a
        // each time we have two choices, select b + 1, meantime select/not select b
        // we can use induction to prove it will enumerate all the cases
        long long now;
        while (k--) {   
            auto pair = pq.top();
            pq.pop();
            now = pair.first;
            int index = pair.second;
            std::cout << now << " " << index << std::endl;
            if (index + 1 < nums.size()) {
                pq.push(make_pair(now + nums[index + 1] - nums[index], index + 1));
                pq.push(make_pair(now + nums[index + 1], index + 1));
            }
        }
        return sum - now;
    }
};
