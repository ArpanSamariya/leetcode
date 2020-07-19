class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, rem = 0;
        ans += numBottles;
        while(numBottles >= numExchange ){
            ans += numBottles / numExchange;
            rem += numBottles % numExchange;
            numBottles = numBottles /  numExchange;
            numBottles += rem;
            rem = 0;
            
        }
        return ans;
    }
};