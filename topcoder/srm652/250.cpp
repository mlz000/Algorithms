#include <bits/stdc++.h>
using namespace std;
#define sz(x)	x.size() 
const int M = (int)1e9 + 7;
int tot;
long long p[100005];
bool check[100005];
void init(){
	for(int i = 2;i <= 100000;++i){
		if(!check[i])	p[++tot] = i;
		for(int j = 1; j <= tot; ++j){
			if(p[j] * i > 100000)	break;
			check[p[j]*i] = true;
			if(i%p[j]==0){
				break;
			}
		}
	}
}
struct ThePermutationGame {
	int findMin(int n) {
		init();
		long long ans = 1ll;
		for (int i = 2; i <= n; ++i) {
			if (!check[i]) {
				long long j = i;
				while (1) {
					if (j > n)	break;
					j *= i;
				}
				j /= i;
				ans = ans * j % M;
			}
		}
		return ans;
	}
};	
