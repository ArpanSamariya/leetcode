class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mp;
    RangeFreqQuery(vector<int>& arr) {

        int t;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        
        // vector<int> res = mp[value];
        
        int cnt = 0;
        int i = 0;
       
        int l = lower_bound(mp[value].begin(), mp[value].end(), left) - mp[value].begin(); // >=
        int r = upper_bound(mp[value].begin(), mp[value].end(), right) - mp[value].begin(); // >
      
        return r - l;
    }
};

/*
class RangeFreqQuery {
public:
     unordered_map<int, vector<int>> mp;
    RangeFreqQuery(vector<int>& arr) {

        int t;
        for(int i = 0; i < arr.size(); i++){
            t = arr[i];
            
            auto itr = mp.find(t);
            if( itr != mp.end()) {
                (itr->second).push_back(i);
            
            } else {
                vector<int> tmp(1,i);
                mp.insert({t, tmp});
            }
        }
    }
    
    int query(int left, int right, int value) {
        
         vector<int> res = mp[value];
        int cnt = 0;
        int i = 0;
       
        int l = lower_bound(res.begin(), res.end(), left) - res.begin();
        int r = upper_bound(res.begin(), res.end(), right) - res.begin();
      
        return r - l;
    }
};
*/


/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */