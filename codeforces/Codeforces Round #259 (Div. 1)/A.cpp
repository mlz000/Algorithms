#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	double ans=0.0;
	double x=0.0,y=0.0;
	for(int i=1;i<=m;++i){
		x=pow((double)i/m,n);
		ans+=(x-y)*i;
		y=x;
	}
	printf("%.6lf\n",ans);
	return 0;
}
