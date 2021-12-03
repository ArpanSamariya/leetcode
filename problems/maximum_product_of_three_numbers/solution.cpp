class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int sz = nums.size() - 1;
        // sort(nums.begin(), nums.end());
        // for(auto i : nums) cout<<i<<" ";
        // return max({ 
        //     nums[0]*nums[1]*nums[2], 
        //     nums[sz]*nums[1]*nums[0],
        //     nums[sz]*nums[sz-1]*nums[sz-2],
        // });
        
        int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        
        for(int i = 0;  i <= sz; i++){
            if(nums[i] <= min1){
                    min2 = min1;
                    min1 = nums[i];
            }else if (nums[i] <= min2)
            {
                min2 = nums[i];
            } 
            if(nums[i] >= max1){
               
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }else if(nums[i] >= max2){
                max3 = max2;
                max2 = nums[i];
            }else if(nums[i] >= max3)
            { max3 = nums[i];}
        }
        return max(min1*min2*max1, max1*max2*max3);
    }
};