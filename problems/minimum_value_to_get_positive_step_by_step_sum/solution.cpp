class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int curr = 0;
        int tot = 0;
        for(int num : nums){
            curr = min(curr, tot += num );
        }
        return 1 - curr;
    }
};
/*
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int sum = 0;
        int add = 0;
        bool flag = true;
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
            if(sum < 1){
                add += 1 - (sum);
                sum = 1;
                flag = false;
            }
        }
        if(flag && add == 0){
            add = 1;
        }
        return add;
    }
};
*/