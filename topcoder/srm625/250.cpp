#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
int c[55];
long double f[55];
class PalindromePermutations{
        public:
        double palindromeProbability(string word){
			int l=sz(word);
			f[0]=f[1]=1;
			for(int i=2;i<=l;++i)	f[i]=f[i-1]*i;
			for(int i=0;i<l;++i)	++c[word[i]-'a'];
			int odd=0,tot=0;
			for(int i=0;i<26;++i)	tot+=c[i];
			for(int i=0;i<26;++i)	if(c[i]%2==1)	odd++;
			if(odd>1)	return 0.0;
			long double B=f[tot];
			for(int i=0;i<26;++i)	B/=f[c[i]];
			tot=tot-(odd==1);
			tot/=2;
			long double A=f[tot];
			for(int i=0;i<26;++i)	A/=f[c[i]/2];
			return A/B;
        }
}
