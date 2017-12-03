class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int count = 0, n = A.size();
        for(int i = 1; i < n; i++){
            if(A[i] == A[i - 1]) count++;
            else A[i - count] = A[i];
        }
        return n - count;
    }
};