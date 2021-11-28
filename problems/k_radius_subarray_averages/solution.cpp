class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ret(nums.size(), -1);
        vector<long long unsigned> pref(nums.size(), 0);
        
        // cout<<nums.size()<<"*"<<2*k + 1;
        if(nums.size() < (2*k + 1)){
            // vector<int> tmp(1,-1);
            return ret;
        }
        if(k==0){
            return nums;
        }
        // pref.push_back(0);
        long long unsigned sm = 0;
        for(int i = 0; i < nums.size(); i++){
            sm += nums[i];
            pref[i] = sm;
        }
        // for(auto i : pref){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        ret[k] =  pref[2*k]/(2*k + 1);
        
        for(int i = k + 1; i < nums.size() - k; i++){
            // cout<<"\n"<<(pref[i+k] - pref[i-k])<<" ";
            ret[i] = (pref[i+k] - pref[i-k-1])/(2*k + 1);
            // cout<<ret[i]<<" ";
        }
        
        return ret;
    }
};