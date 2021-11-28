class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        map<int,int> mp;
        int ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());
        int i = mp[nums[0]];
        int j = mp[nums[nums.size() -1]];
        int n = nums.size();
        
        return min({max(i, j ) + 1, n - min(i,j) , 1+min(i,j) + n - max(i,j)});
         // return min({max(i + 1, j + 1), max(n - i, n - j), i + 1 + n - j, j + 1 + n - i});
    }
};