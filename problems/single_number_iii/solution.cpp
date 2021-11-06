class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       unordered_set<int> ret;
        
        for(int i = 0 ; i < nums.size(); i++ ){
            if( ret.count(nums[i])){
                ret.erase(nums[i]);
            } else {
                ret.insert(nums[i]);
            }
        }
        return vector<int> (ret.begin(), ret.end());
    }
};

/*
 int cnt = 0;
        sort(nums.begin(), nums.end());
        vector<int> ret;
        
        if(nums.size() == 2 and nums[0] != nums[1]){
                return nums;
        }
        
        for(int i = 0 ; i < nums.size() - 1 ; i += 2){
            if(nums[i] == nums[i+1]){
                continue;
            }
            else {
                cnt++;
                ret.push_back(nums[i]);
                if(cnt == 2){
                    break;
                }
                i--;
            }
        }
        
        if(nums[nums.size()-1] != nums[nums.size()-2]){
             ret.push_back(nums[nums.size()-1]);
        }
        
        return ret;
        
*/