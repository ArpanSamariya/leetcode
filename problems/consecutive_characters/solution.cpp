class Solution {
public:
    int maxPower(string s) {
        int count = 1;
        int mx = 1;
        
        for(int i = 0; i < s.length(); i++){
            count = 1;
            while(i < s.length() and s[i] == s[i+1]){
                i++;
                count++;
            }
            mx = max(mx,count);
        }
        return mx;
    }
};