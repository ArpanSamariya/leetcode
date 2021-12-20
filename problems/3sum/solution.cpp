/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int> mp;
        map<vector<int>,int> mv;
        vector<vector<int>> vv;
        int target;
        
        if(nums.size() < 3){
            return vv;
        }
        sort(nums.begin(), nums.end());//nlogn
        
        if(nums[0] == 0 and nums[nums.size()-1] == 0){
            vector<int> v(3,0);
            vv.push_back(v);
            return vv;
        }
        
        for(int i = 0 ; i < nums.size(); i++){
            target = -1*nums[i];
            for(int j = i+1; j < nums.size(); j++){
                if(mp.find(target - nums[j]) != mp.end()){
                  vector<int> v {nums[i], nums[j], target - nums[j]};
                  sort(v.begin(), v.end());
                  mv[v]++;
                  // vv.push_back(v);
                }
            }
            mp[nums[i]] = i;
        }
        for(auto v : mv){
            vv.push_back(v.first);
        }
        return vv;
    }
};

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> res; 
        sort(num.begin(), num.end()); 
        
        // moves for a
        for (int i = 0; i < (int)(num.size())-2; i++) {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
                int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
                
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[lo]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
    }
};