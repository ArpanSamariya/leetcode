class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> ret(nums.size()+1, 0);
        vector<int> ans;
        ret[0] = -1;

        
        for(int i = 0 ; i < nums.size(); i++){
            ret[nums[i]]--;
        }
        
        for(int i = 1; i < ret.size(); i++){
            if(ret[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};