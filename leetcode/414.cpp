typedef long long LL;
class Solution {
public:
    vector<LL>a;
    int thirdMax(vector<int>& b) {
        for (auto x : b)    a.push_back(x);
		LL mx1, mx2, mx3;
		mx1 = mx2 = mx3 = -3e9;
		for (auto x : a) {
		    if (x == mx1 || x == mx2 || x == mx3)   continue;
			if (x > mx1) {
				mx3 = mx2;
				mx2 = mx1;
				mx1 = x;
			}
			else if (x > mx2) {
				mx3 = mx2;
				mx2 = x;
			}
			else if (x > mx3)	mx3 = x;
		}
		return mx3 != -3e9 ? (int)mx3 : (int)mx1;
    }
};