#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
map<int,int>m;
void any()
{
    int flag=0;
    map<int,int>::reverse_iterator rit;
    for(rit=m.rbegin();rit!=m.rend();rit++)
        if((*rit).second==1)
        {
            flag=1;
            break;
            }
    if(flag==1)
      printf("T\n");
    else
      printf("F\n");
}
void count()
{
    int sum=0;
    map<int,int>::reverse_iterator rit;
    for(rit=m.rbegin();rit!=m.rend();rit++)
    if((*rit).second==1)
    sum++;
    printf("%d\n",sum);
}
void filp(int x)
{
    if(m.find(x)==m.end())
        m[x]=1;
        else
        m.erase(x);
}
void find(int x)
{
     if(m.find(x)==m.end())
         printf("F\n");
     else
     printf("T\n");
}
int main()
{
    int n,m,i;
    char a[10];
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        getchar();
        scanf("%s",a);
        if(a[2]=='u')
        count();
        else if(a[2]=='y')
           any();
           else if(a[2]=='l')
           {
                int z;
                scanf("%d",&z);
                filp(z);
        }
        else
        {
            int z;
            scanf("%d",&z);
            find(z);
        }
    }
    //system("pause");
    return 0;
}
