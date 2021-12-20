class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int mxLn = INT_MIN;
        string curr = "";
        int st = 0;
        
        
        for(int i = 0; i < s.length(); i++){
            
            if(mp.find(s[i]) != mp.end() and mp[s[i]] >= st){
                mxLn = maxx(mxLn, i-st); 
                st = mp[s[i]] + 1;
                mp.erase(s[i]);
            }
            mp[s[i]] = i;
        }

        mxLn = maxx(mxLn, s.length() - st);
        return mxLn;
    }
    
    int maxx(int a, int b){
        return a > b ? a : b;
    }
};