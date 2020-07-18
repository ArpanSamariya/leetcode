class Solution {
public:
    int numSub(string s) {
        long long int count = 0;
        int mod = 1000000007;
        long long int  ans1 = 0, ans2 = 0;
        for(int i = 0 ; i < s.length(); i++){
            count = 0;
            while(s[i] == '1'){
                count++;
                i++;
                if(i == s.length())
                    break;
            }
            
            ans1 += (count*(count+1)/2)%mod;
            
        }
        return ans1%mod;
    }
};