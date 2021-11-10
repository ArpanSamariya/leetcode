class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        vector<int> diff(prices.size(),0);
        
        for(int i = 1; i < prices.size() ; i++){
            diff[i] = prices[i] - prices[i-1];
        }
        for(int i = 0; i < diff.size(); i++){
            // cout<<diff[i]<<" ";
            if(diff[i] > 0){
                ret += diff[i];
            }
        }
        return ret;
    }
};