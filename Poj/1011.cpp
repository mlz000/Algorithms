#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int a[65],len,n;
bool used[65];//usedΪfalseʱ��ʾ��ľ��δ�ù� 
bool dfs(int i,int l,int t)//��i����ŵ�ľ�� ʣ��l����ƴ��һ��ľ�� t��ʼΪ�ܳ��� 
{
      if(l==0)
      {
         t=t-len;
         if(t==0) return true;
         for(i=1;used[i];++i);
         used[i]=true;//��ǰ���ֵ��ȻҪȡ 
         if(dfs(i+1,len-a[i],t)) return true; 
         used[i]=false;
         t=t+len;
      }
      else
      {
            int j;
           for(j=i;j<=n;++j)
          {
             if(j>=2&&a[j]==a[j-1]&&(!used[j-1]))//2����һ����ǰһ��û�ù���һ��Ҳ������ 
             continue;
             if( (!used[j])&&l>=a[j])//δ���ʹ�����ʣ�೤�ȴ��ڴ�ľ���� 
             {
                l=l-a[j];
                used[j]=true; 
                if(dfs(j,l,t)) return true;
                used[j]=false;
                l=l+a[j];
                if(a[j]==l) break;  //�����ѱ�Ȼʧ�ܣ�������һ�� 
             }
          }
      }
      return false;
}
bool cmp(const int &b,const int &c)
{
      return b>c;
}
int main()
{
       while(scanf("%d",&n)&&n)
 {
        int i;
       int sum=0;
       for(i=1;i<=n;++i)
       {
         scanf("%d",&a[i]);
         sum+=a[i];
       }
       sort(&a[1],&a[n+1],cmp);
       bool flag=false;  
       for(len=a[1];len<=sum/2;++len)
       {
           if(sum%len==0)
           {
            if(dfs(1,len,sum)) {flag=true;printf("%d\n",len);break;}
           }
       }
        if(!flag) printf("%d\n",sum);
        memset(used,false,sizeof(used)); 
 } 
     system("pause");
     return 0; 
}
