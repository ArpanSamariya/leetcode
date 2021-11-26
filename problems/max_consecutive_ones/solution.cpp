class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currSum = 0;
        int maxSum = 0;
        
        
        for(int i = 0; i < nums.size(); i++){
            currSum = 0;
            while(i< nums.size() and nums[i] == 1){
                currSum++;
                i++;
            }
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};