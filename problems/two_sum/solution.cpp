class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int left = 0;
        vector<int> vc;
        map<int,int> mp;

        for(int i = 0 ; i < nums.size(); i++) {
           mp[nums[i]] = i;
        }
        
        for(int i = 0 ; i < nums.size(); i++) {
            auto itr = mp.find(target - nums[i]);
           if( itr != mp.end() and i != itr->second ){
               vc.push_back(i);
               vc.push_back(mp[target - nums[i] ]);
               return vc;
           }
               
        }
        
        
         return vc;
    }
        
};



/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int left = 0;
        vector<int> vc;

        for(int i = 0 ; i < nums.size() -1; i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target){
                    vc.push_back(i);
                    vc.push_back(j);
                    return vc;
                }
            }
        }
         return vc;
    }
        
};
*/