//http://wenku.baidu.com/view/e918218dcc22bcd126ff0cf1.html
//Nimm Game 
//��ÿ�����ĳ�2^n���ݵ���ʽ  ÿ���ĸ����;�Ϊż��ʱ(��ת��Ϊ������ͬ��)���ֱذ� 
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
      int i,j,n,a;
	  while(scanf("%d",&n)!=EOF)
	  {
		 int ans;
		 scanf("%d",&ans);	
         for(i=1;i<n;++i)
         {
			 scanf("%d",&a);
	         ans^=a;
		 }
		 if(ans!=0) printf("Yes\n");
		 else printf("No\n"); 
	  }       
          //system("pause");
		  return 0;    
} 
