#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
class LargestSubsequence{
        public:
        string getLargest(string s){
            int l=sz(s);
			string tmp="";
			int p=0;
			for(int i=0;i<l;++i){
				int pos=p;
				bool f=false;
				for(int j=p;j<l;++j)
					if(s[j]>s[pos]){
						f=true;
						pos=j;
					}
				if(f||pos==p){
					tmp+=s[pos];
					p=pos+1;
				}
				if(p>=l)	break;
			}
			return tmp;
        }
};
