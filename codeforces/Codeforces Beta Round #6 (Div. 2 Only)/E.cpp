#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include <vector>
#include <utility>
using namespace std;
int a[100005];
int main()
{
	int n,k;
	multiset<int> s;
	vector<pair<int,int> >ans;
	scanf("%d%d",&n,&k);
	int p=0,best=-1;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		s.insert(a[i]);
		while(*s.rbegin()-*s.begin()>k)	s.erase(s.find(a[p++]));
		if(best<i-p)
		{
			best=i-p;
			ans.clear();
		}
		if(best==i-p)	ans.push_back(make_pair(p,i));
	}
	printf("%d %d\n",best+1,ans.size());
	for(int i=0;i<ans.size();++i)	printf("%d %d\n",ans[i].first+1,ans[i].second+1);

	return 0;
}
