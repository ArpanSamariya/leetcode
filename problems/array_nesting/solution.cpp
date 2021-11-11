class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        
        long long currMax = 0;
        long long mx = 0;
        int j = 0;
        int new_j = 0;
        
        for(int i = 0 ; i < nums.size(); i++){
            j = i;
            currMax = 0;
            while(nums[j] != -1){
 
                new_j = nums[j];
                nums[j] = -1;
                j = new_j;
                currMax++;                
            }
            if( currMax > mx) mx = currMax;
        }
        return mx;
    }
};

/*
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        
        vector<int> ans(nums.size(), 0);
        vector<int> jump(nums.size(), 0);
        int mx = 1;
        
        for(int i = 0 ; i < nums.size(); i++) {
           unordered_set<int> mp;
            int currMax = 0;
            int j = i;
            
            while(mp.find(nums[j]) == mp.end()){
                // cout<<"current element in while " << nums[j] << endl;
                if(ans[nums[j]] == 0){
                    currMax++;
                    mp.insert(nums[j]);
                     ans[nums[j]] = currMax;
                    
                    j = nums[j];
                    // cout<<"next element in while " << nums[j] << endl;
                }
                else {
                    currMax += ans[nums[j]];
                    break;
                }
            }//mp ends
            mx = max(currMax,mx);
        }
        // for(int i : ans){
        //     cout<<i<< " ";
        // }
        // cout<<endl;
        return mx;
    }
};
*/