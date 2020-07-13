class Solution {
public:
    int arrangeCoins(int n) {
       unsigned long long int k, curr;
     // return (-1+sqrt(1+4*2*k))/2;
        // return n-((m*(m+1))/2);
       // return m;
        int left = 0, right = n;
    while(left <= right){
        k = left + (right-left)/2;
        curr = k * (k+1) / 2;
        if(curr == n){
            return k;
        }
        else if( curr < n){
            left = k + 1;
        }
        else{
            right = k -1;
        }
    }
        return right;
    }
};