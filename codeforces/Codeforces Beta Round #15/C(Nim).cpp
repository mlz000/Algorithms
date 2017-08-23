#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
long long x,y;
int main(){
	scanf("%d",&n);
	long long ans=0;
	for(int i=1;i<=n;++i){
		scanf("%I64d%I64d",&x,&y);
		y+=x;
        ans^=(x&1)*(x-1)+(x&2)/2;
        ans^=(y&1)*(y-1)+(y&2)/2;
	}
	printf(ans?"tolik\n":"bolik\n");  	
	return 0;
}
			

