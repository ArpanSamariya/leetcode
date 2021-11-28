class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ret;
        
        sort(nums.begin(), nums.end());
        
        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        for(int i = start; i < end; i++){
            ret.push_back(i);
        }
        return ret;
    }
};