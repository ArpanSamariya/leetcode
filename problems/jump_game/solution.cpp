class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        vector<bool> d (nums.size() ,false);
        int nearestTrue = nums.size() - 1;
        
        for(int i = nums.size() -1 ; i >= 0; i--){
            
            if(nums[i] + i >= nearestTrue){
                d[i] = true;
                nearestTrue = i;
                continue;
            }
        }
        return d[0];
    }
};