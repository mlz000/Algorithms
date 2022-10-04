#define eb emplace_back
class Solution {
public:
	bool check(int b, int x) {
		vector<int> a;
		while (x) {
            a.eb(x % b);
            x /= b;
        }
		vector<int> tmp = vector(a.rbegin(), a.rend()); 
        return tmp == a;
	}
    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i <= n - 2; i++)
        	if (!check(i, n)) return 0;
        return 1;
    }
};
