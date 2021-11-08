class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxSum = nums[0];
        int currSum = nums[0];

        
        for(int i = 1; i < nums.size(); i++){
           currSum = max( nums[i], currSum + nums[i] );
           maxSum = max(maxSum, currSum); 
        }
        return maxSum;
    }
};


/*

    int maxSubArray(vector<int>& nums) {
        
        int maxSum = INT_MIN;
        int sum = 0;

        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
             if(sum > maxSum){
                maxSum = sum;
            }
            if ( sum < 0 ) {
                sum = 0;
            }
           
        }
        return maxSum;
    }
    
*/