class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        std::vector<long long> sum(travel.size() + 2);
        std::unordered_map<char, int> last_pos;
        for (int i = 0; i < travel.size(); ++i) {
            sum[i + 1] = sum[i] + travel[i];
        }
        for (int i = garbage.size() - 1; i >= 0; --i)
            for (auto c : garbage[i]) {
                if (!last_pos[c]) {
                    last_pos[c] = i;
                }
                ++ans;
            }
        std::cout << last_pos['M'] << " " << last_pos['P'] << " " << last_pos['G'] << std::endl;
        ans += sum[last_pos['M']] + sum[last_pos['P']] + sum[last_pos['G']];
        return ans;
    }
};
