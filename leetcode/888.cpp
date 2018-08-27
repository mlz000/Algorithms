class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        unordered_map<int, bool> ma, mb;
        for (auto x: A) ma[x] = 1;
        for (auto x: B) mb[x] = 1;
        int suma =  accumulate(A.begin(), A.end(), 0);
        int sumb = accumulate(B.begin(), B.end(), 0);
        int sum = (suma + sumb) / 2;
        for (auto x: A) {
            int y = sum - (suma - x);
            if (mb.find(y) != mb.end()) {
                ans.push_back(x);
                ans.push_back(y);
                break;
            }
        }
        return ans;
    }
};
