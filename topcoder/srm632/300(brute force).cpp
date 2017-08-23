#include<bits/stdc++.h>//Ã¶¾Ù
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
class PotentialArithmeticSequence{
        public:
        int numberOfSubsequences(vector <int> d){
            int n=sz(d);
			int ans=0;	
			for(int i=0;i<n;++i)
				for(int j=i;j<n;++j){
					int pos=i;
					for(int k=i+1;k<=j;++k)	pos=d[k]>d[pos]?k:pos;
					int cnt=0;
					for(int k=i;k<=j;++k)	if(d[k]==d[pos])	cnt++;
					bool flag=1;
					if(cnt>1)	flag=0;
					for(int k=pos+1;k<=j;++k)	if(__builtin_ctz(k-pos)!=d[k])	flag=0;
					for(int k=pos-1;k>=i;--k)	if(__builtin_ctz(pos-k)!=d[k])	flag=0;
					if(flag)	++ans;
				}
			return ans;
        }
};
