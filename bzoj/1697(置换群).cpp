/*
��һ���������û��е�ÿ��Ԫ�غ��û��е���СԪ�ؽ�����
�ڶ����Ȱ��û��е���СԪ�غ����е���СԪ�ؽ�����Ȼ�����ظ�һ��Ȼ���ٰ����ǽ�������
*/
#include<cstdio> 
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
vector<pair<int,int> >a;
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;++i)   
    {
        int x;scanf("%d",&x);
        a.push_back(make_pair(x,i));
    }
    sort(a.begin(),a.end());
    int ans=0;int w=a[0].first;
    for(i=0;i<n;++i)
    {
        if(a[i].second==-1) continue;
        int num=a[i].first;
        j=a[i].second;
        a[i].second=-1;k=1;
        while(j!=i)
        {
            ans+=a[j].first;
            int t=a[j].second;
            a[j].second=-1;
            j=t;
            k++;
        }
        ans+=min((k-1)*num,(k+1)*w+2*num);
    }
    printf("%d",ans);
    return 0;
}
