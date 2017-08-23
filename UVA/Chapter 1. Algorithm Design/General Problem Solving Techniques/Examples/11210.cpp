#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=20;
char s[N];
int mj[N],c[N*2];
char ss[][N]=
{
      "1T","2T","3T","4T","5T","6T","7T","8T","9T",
      "1S","2S","3S","4S","5S","6S","7S","8S","9S",
      "1W","2W","3W","4W","5W","6W","7W","8W","9W",
      "DONG","NAN","XI","BEI","ZHONG","FA","BAI"
};
int init(char t[])
{
    for(int i=0;i<34;++i)
      if(strcmp(ss[i],t)==0) return i;
    return -1;  
}
bool find(int dep)
{
     if(dep>3) return true; 
     for(int i=0;i<34;++i)
     {
        if(c[i]>=1)
        {
          if(c[i]>=3) 
          {
            c[i]-=3;
            if(find(dep+1)) return true;
            c[i]+=3; 
          } 
          if(i<=24 && i%9<=6 && c[i+1]!=0 && c[i+2]!=0) 
          {
             c[i]--;c[i+1]--;c[i+2]--;
             if(find(dep+1)) return true;
             c[i]++;c[i+1]++;c[i+2]++; 
          } 
        }   
     } 
     return false; 
} 
bool check()
{
     for(int i=0;i<34;++i) 
     {
         if(c[i]>=2) 
         {
            c[i]-=2;//做将牌 
            if(find(0)) return true;
            c[i]+=2; 
         } 
     } 
     return false; 
} 
int main()
{
      int i,j,T=0;
      while(scanf("%s",s))
      {
        if(s[0]=='0') break;
        T++;
        printf("Case %d:",T);
        mj[0]=init(s);
        for(i=1;i<13;++i)
        {
            scanf("%s",s);
            mj[i]=init(s);
        }
        bool flag=false;
        for(i=0;i<34;++i)
        {
           memset(c,0,sizeof(c));
           for(j=0;j<13;++j)  c[mj[j]]++;
           if(c[i]>=4) continue;
           c[i]++;//假设第14张牌是这张
           if(check()) 
           {
                  flag=true;
                  printf(" %s",ss[i]);
           } 
           c[i]--;   
        }  
        if(!flag) printf(" Not ready"); 
        printf("\n"); 
      }
      //system("pause");
      return 0;
}
