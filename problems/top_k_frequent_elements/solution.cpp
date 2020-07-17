class Solution {
public:
    static bool cmp(pair<int,int> a , pair<int,int> b){
        return (a.second > b.second);
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> ret;
        vector<pair<int,int>> vp;
        
        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
            // if(mp[nums[i]] == k)
            //     ret.push_back(nums[i]);
        }
        for(auto i = mp.begin(); i != mp.end(); i++){
            // cout<<i->first<<" "<<i->second<<endl;
            vp.push_back(make_pair(i->first, i->second));
            
        }
        
        sort(vp.begin(), vp.end(), cmp);
        
        for(int o = 0; o != k; o++){
            ret.push_back(vp[o].first);
        }
        return ret;
    }
};