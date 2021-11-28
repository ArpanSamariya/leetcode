class Solution {
public:
    int cnt = 0;
    map<int,int> mp;
    vector<int> arr;
    int rob(vector<int>& nums) {
         arr = nums;
        return dp(nums.size()-1);
    }
    
    int dp(int n){

        if(n == 0) return arr[0];
        if(n == 1) return max(arr[0],arr[1]);
        
        if(mp.find(n) == mp.end()){
            mp[n] = max(dp(n-1), dp(n-2) + arr[n]);
        }
       
        return mp[n];
    }
};