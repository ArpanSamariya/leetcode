class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minima = prices[0];
               

        for(int i = 0; i < prices.size(); i++){
            minima = min(minima, prices[i]);
            maxProfit = max(maxProfit,  prices[i] - minima);
        }
        
        return maxProfit;
    }
};

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ret = 0;
        int maxi = prices[prices.size() - 1];
        vector<int> maxTillNow(prices.size(),0);
        
        for(int i = prices.size() - 2; i >= 0 ; i--){
            maxTillNow[i] = maxi;
            if( prices[i] > maxi)
                maxi = prices[i];
        }
        for(int i = 0 ; i < prices.size(); i++){
            ret = std::max(ret,  maxTillNow[i] - prices[i]);
        }
        return ret;
    }
};
*/