class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int cnt = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'R')
                cnt++;
            if(s[i] == 'L')
                cnt--;
            if(cnt == 0)
                ans++;
        }
        return ans;
    }
};