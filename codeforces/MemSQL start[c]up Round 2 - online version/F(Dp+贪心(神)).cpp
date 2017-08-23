#include<bits/stdc++.h>
using namespace std;
const int N=500005;
map<int,int>mp;
priority_queue<int,vector<int>,greater<int> >q;
void update(int price,int Y,int S){
	int X=q.size();
	Y=min(Y,S);
	int cy=Y,cx=(S-Y)/2;
	vector<int> removed;
	while(q.size()>cx){
		int tmp=q.top();
		removed.push_back(tmp);
		q.pop();
	}
	reverse(removed.begin(),removed.end());
	int x=cx,y=0;
	while(x+y<cx+cy){
		if(y==0 && x<X && removed[x-cx]>price){
			q.push(removed[x-cx]);
			x++;
		}
		else if(y<Y && 2*x+y<S){
			q.push(price);
			y++;
		}
		else{
			if(2*price>removed[x-cx-1])	q.push(2*price-removed[x-cx-1]);
			else q.push(0);
			x--;
			y+=2;
		}
	}
}
int main(){
	int n,x;
	int sum=0;
	long long ans=0ll;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		mp[-x]++;
		ans+=x;
	}
	map<int,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		update(-(it->first),it->second,sum);
		sum+=it->second;
	}
	while(q.size()){
		x=q.top();
		q.pop();
		ans-=x;
	}
	printf("%I64d\n",ans);
	return 0;
}
