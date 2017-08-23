#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int n=100005;
int x[n],y[n];
vector<int>a[n],b[n];
int find(int x,int y){
	return binary_search(a[x].begin(),a[x].end(),y);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%d",&x[i],&y[i]);
		a[x[i]].push_back(y[i]);
		b[y[i]].push_back(x[i]);
	}
	long long ans=0;
	for(int i=0;i<=100000;++i)	sort(a[i].begin(),a[i].end()),sort(b[i].begin(),b[i].end());
	for(int i=0;i<n;++i){
		vector<int> &c=a[x[i]],&d=b[y[i]];
		int j=upper_bound(c.begin(),c.end(),y[i])-c.begin();
		int k=upper_bound(d.begin(),d.end(),x[i])-d.begin();
		while(j<c.size() && k<d.size()){
			if(c[j]-y[i]<d[k]-x[i])	++j;
			else if(c[j]-y[i]>d[k]-x[i])	++k;
			else{
				ans+=find(d[k],c[j]);
				++j,++k;
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}

