class Solution {
public:
    map<int,int> mp;
    vector<int> arr;
    int minCostClimbingStairs(vector<int>& cost) {
        arr = cost;
        return dp(cost.size());
    }
    int dp(int n){
        
        if( n == 0 ) return 0;
        if ( n == 1) return 0;
        
        if(mp.find(n) == mp.end()){
            mp[n] = min(dp(n-1) + arr[n-1], dp(n-2) + arr[n-2]);
        }
        return mp[n];
    }
};