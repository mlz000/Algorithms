class Solution {  
public:  
    void wiggleSort(vector<int>& a) {
        int n = a.size();
        nth_element(a.begin(), a.begin() + n / 2, a.end());  
        int l = 0, r = n - 1, mid = a[n / 2], i = 0;  
        auto index = [=](int p){return (p * 2 + 1) % (n | 1);};
        for (int i = 0; i < n; ++i) printf("%d ", index(i));
        while(i <= r) {  
            if(a[index(i)] > mid)   swap(a[index(i++)], a[index(l++)]);  
            else if(a[index(i)] < mid)  swap(a[index(i)], a[index(r--)]);  
            else i++;  
        }  
    }  
};  