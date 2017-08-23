#include<bits/stdc++.h>//AC×Ô¶¯»ú+dp
using namespace std;
typedef long long ll;
const int M=1000000009;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
int ch[400][26],p[400],w[400],dp[55][400][1<<6];
class RequiredSubstrings{
	public:
        int solve(vector <string> words, int C, int L){
            int n=sz(words),sz=0;
			for(int i=0;i<n;++i){
				string s=words[i];
				int l=sz(s);
				int u=0;
				for(int j=0;j<l;++j){
					int c=s[j]-'a';
					if(!ch[u][c])	ch[u][c]=++sz;
					u=ch[u][c];
				}
				w[u]=1<<i;
			}
			queue<int>q;
			q.push(0);
			while(q.size()){
				int u=q.front();
				q.pop();
				for(int c=0;c<26;++c){
					int v=ch[u][c];
					if(!v)	ch[u][c]=ch[p[u]][c];
					else{
						p[v]=u?ch[p[u]][c]:0;
						q.push(v);
						w[v]|=w[p[v]];
					}
				}
			}
			dp[0][0][0]=1;
			for(int i=0;i<L;++i)
				for(int j=0;j<=sz;++j)
					for(int k=0;k<1<<n;++k)
						for(int p=0;p<26;++p)
							(dp[i+1][ch[j][p]][k|w[ch[j][p]]]+=dp[i][j][k])%=M;
			int ans=0;
			for(int i=0;i<=sz;++i)
				for(int j=0;j<1<<n;++j)
					if(__builtin_popcount(j)==C)	(ans+=dp[L][i][j])%=M;
			return ans;
		}
};
