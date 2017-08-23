#include<bits/stdc++.h>//·Ö¿é
using namespace std;
const int N=50005;
vector<int>b[300];
int T,n,m,s,a[N];
int calc(int x,int y,int k){
	int fx=(x-1)/s+1,fy=(y-1)/s+1;
	int tmp=0;
	if(fx==fy)	for(int i=x;i<=y;++i)	tmp+=a[i]<k;
	else{
		for(int i=x;i<=fx*s;++i)	tmp+=a[i]<k;
		for(int i=y;i>(fy-1)*s;--i)	tmp+=a[i]<k;
		for(int i=fx+1;i<fy;++i)	tmp+=lower_bound(b[i].begin(),b[i].end(),k)-b[i].begin();
	}
	return tmp;
}
int query(int x,int y,int k){
	int l=0,r=1000000001;
	while(l+1<r){
		int mid=(l+r)>>1;
		int cnt=calc(x,y,mid);
		if(cnt>=k)	r=mid;
		else l=mid;
	}
	return l;
}
void modify(int x,int y){
    int pos=0;  
    int fx=(x-1)/s+1;  
    int sz=b[fx].size();  
    while(b[fx][pos]<a[x]) pos++;  
    b[fx][pos]=y;  
    if(y>a[x]){  
        while(pos<sz-1 && b[fx][pos]>b[fx][pos+1]){  
            swap(b[fx][pos],b[fx][pos+1]);  
            pos++;  
        }  
    }  
    else{  
        while(pos>0 && b[fx][pos]<b[fx][pos-1]){  
            swap(b[fx][pos],b[fx][pos-1]);  
            pos--;  
        }  
    } 
	a[x]=y;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		s=sqrt(n+0.5);
		int tot=(n-1)/s+1;
		for(int i=1;i<=tot;++i)	b[i].clear();
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			b[(i-1)/s+1].push_back(a[i]);
		}
		for(int i=1;i<=tot;++i)	sort(b[i].begin(),b[i].end());
		int x,y,k;
		char ss[5];
		while(m--){
			scanf("%s",ss);
			if(ss[0]=='Q'){
				scanf("%d%d%d",&x,&y,&k);
				printf("%d\n",query(x,y,k));
			}
			else{
				scanf("%d%d",&x,&y);
				if(a[x]!=y)	modify(x,y);
			}
		}
	}
	return 0;
}
