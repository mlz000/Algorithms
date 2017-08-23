#define pb push_back
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int L) {
        int n = words.size();
		vector<string> ans;
		for (int i = 0, j, l; i < n; i += j) {
			for (j = l = 0; i + j < n && l + words[i + j].size() + j <= L; ++j)	
				l += words[i + j].size();// i ~ i + j - 1
			string now = words[i];
			for (int k = 0; k < j - 1; ++k) {
				if (i + j == n)	now += " ";
				else {
					int t = (L - l) / (j - 1) +  (k < (L - l) % (j - 1));
					now += string(t, ' ');
				}
				now += words[i + k + 1];
			}
			now += string(L - now.size(), ' ');
			ans.push_back(now);
		}
		return ans;
    }
};
