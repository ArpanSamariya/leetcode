class Solution {
public:

    int searchInsert(vector<int>& nums, int target) {
        // return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while(1){
            
            mid = ( left + right ) / 2;
            // cout<<left << " " << right << endl;
            if(right < left)
                return left;
            
            // if(mid < 0 || left < 0 || right < 0)
            //     return 0;
            // if(left == right){
            //     if(nums[left] < target)
            //     return left + 1;
            //     return left;
            // }
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if ( nums[mid] > target) {
                right = mid - 1;
            }
        }
    }
};