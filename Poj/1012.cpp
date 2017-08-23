#include<iostream>
#include<cstdio> 
using namespace std;
int Joseph[14];
int main()
{
      int k;
      while(scanf("%d",&k)&&k)
      {
           if(Joseph[k])
           {
				printf("%d\n",Joseph[k]);
                 continue;
           }
           int n=2*k;  //总人数
           int ans[30]={0};  //第i轮杀掉对应当前轮的编号为ans[i]的人
           int m=1;    //所求的最少的报数
           for(int i=1;i<=k;i++)  //轮数
           {
                 ans[i]=(ans[i-1]+m-1)%(n-i+1);   //n-i为剩余的人
                 if(ans[i]<k)  //把好人杀掉了,m值不是所求
                 {
                      i=0;
                      m++;  //枚举m值
				 }
           }
           Joseph[k]=m;
           printf("%d\n",m);
      }
      //system("pause");
      return 0;
}

