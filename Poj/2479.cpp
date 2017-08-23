#include <iostream>   
using namespace std;   
int array[50001], num[50001];   
const int MIN = -999999999;   
int main()   
{   
    int tcase, n;   
    cin>>tcase;   
    int tmp, ans, i, sum;   
    while(tcase--){   
        scanf("%d", &n);   
        tmp = MIN;  sum = 0;   
        for(i = 1; i <= n; i++){   
            scanf("%d", &num[i]);   
            sum += num[i];   
            if(sum > tmp)   
                tmp = sum;   
            array[i] = tmp;   
            if(sum < 0)   
                sum = 0;   
        }   
        tmp = ans = MIN;   
        sum = 0;   
        for(i = n; i > 1; i--){   
            sum += num[i];   
            if(sum > tmp)   
                tmp = sum;   
            if(ans < (array[i-1]+tmp))   
                ans = array[i-1]+tmp;   
            if(sum < 0)   
                sum = 0;       
        }              
        cout<<ans<<endl;   
    }      
    return 0;   
}
