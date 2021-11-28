class Solution {
public:
    map<int,int> ans;
    int climbStairs(int n) {
        
        ans[1] = 1;
        ans[2] = 2;
        
        if(n==1)return 1;
        if(n==2)return 2;
        
        // if(ans[n] == 0){
            for(int i=3; i <= n; i++){
            // ans[n] = climbStairs(n-1) + climbStairs(n-2);  
             ans[i] = ans[i-1] + ans[i-2];  
        }
        return ans[n];
    }
};