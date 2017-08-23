#define ll long long
//O(N^3/4)
//http://blog.csdn.net/u013167299/article/details/52604274
int f[340000], g[340000];
void init(int n){
    int m;
    for(m = 1; m * m <= n; ++m) f[m] = n / m - 1;
    for(int i = 1; i <= m; ++i) g[i] = i - 1;
    for(int i = 2; i <= m; ++i){ 
        if(g[i] == g[i - 1])    continue;
        for(int j = 1; j <= min(m - 1, n / i / i); ++j){
            if((ll)i * j < (ll)m)   f[j] -= f[i * j] - g[i - 1];
            else f[j] -= g[n / i / j] - g[i - 1];
        }
        for(int j = m; (ll)j >= (ll)i * i; --j) g[j] -= g[j / i] - g[i - 1];
    }
}
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        init(n - 1);
        return f[1];
    }
};
