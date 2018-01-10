class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, queue<int> > q;
        for (int i = 0; i < B.size(); ++i) {
            q[B[i]].push(i);
        }
        vector<int> ans;
        for (auto x : A) {
            ans.push_back(q[x].front());
            q[x].pop();
        }
        return ans;
    }
};