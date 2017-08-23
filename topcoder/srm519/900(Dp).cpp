#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
const int M=1000000009;
int a[2505],L,R;
bool div(int x){
	if(L>R)	return false;
	if(x==2 && a[R]%2!=0)	return false;
	if(x==5 && a[R]%5!=0)	return false;
	if(x!=2 && x!=5){	
		int t=0;
		for(int i=L;i<=R;++i)	t=(t*10+a[i])%x;
		if(t)	return false;
	}
	int t=0;
	for(int i=L;i<=R;++i)	t=t*10+a[i],a[i]=t/x,t%=x;
	while(!a[L] && L<=R)	L++;
	return true;
}
class VerySmoothDecompositions{
        public:
        int solve(vector <string> digits){
			int n=sz(digits);
			int tot=0;
			for(int i=0;i<n;++i)
				for(int j=0;j<sz(digits[i]);++j)
					a[tot++]=digits[i][j]-'0';
			L=0,R=tot-1;
			int c2=0;while(div(2))	c2++;
			int c3=0;while(div(3))	c3++;
			int c5=0;while(div(5))	c5++;;
			int c7=0;while(div(7))	c7++;
			int c11=0;while(div(11))	c11++;
			int c13=0;while(div(13))	c13++;
			if(R-L>=1)	return 0;
			int sum[20000];
			vector<vector<int> > c(c2+5,vector<int>(c3+5,0));
			c[0][0]=1;
			printf("%d %d %d %d %d %d\n",c2,c3,c5,c7,c11,c13);
			for(int i=2;i<=16;++i){
				int t=i,n2=0,n3=0;
				while(t%2==0)	t/=2,n2++;
				while(t%3==0)	t/=3,n3++;
				if(t>1)	continue;
				for(int i=n2;i<=c2;++i)
					for(int j=n3;j<=c3;++j)
						(c[i][j]+=c[i-n2][j-n3])%=M;
			}
			int ans=0;
			for(int c15=0;c15<=c5;++c15){
				int t=c3-c15;
				if(t<0)	break;
				for(int i=0;i<=c2;++i){
					if(i==0)	sum[i]=c[i][t];
					else sum[i]=(sum[i-1]+c[i][t])%M;
				}
				for(int c10=0;c10+c15<=c5;++c10){
					if(c2<c10)	break;
					int c14=c7;
					if(c2>=c14+c10)	(ans+=sum[c2-c10]-sum[c2-c10-c14-1])%=M;
					else (ans+=sum[c2-c10])%=M;
				}
			}
			return (ans+M)%M;
        }
};
