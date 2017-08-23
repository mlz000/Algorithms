#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
class MissingParentheses{
        public:
        int countCorrections(string s){
            int l=sz(s);
			int now=0,ans=0;
			for(int i=0;i<l;++i){
				if(s[i]=='(')	now++;
				else now--;
				if(now<0)	now++,ans++;
			}
			return ans+abs(now);
        }
};
