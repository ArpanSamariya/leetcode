class Solution {
public:
    string multiply(string num1, string num2) {
        int ln1 = num1.length();
        int ln2 = num2.length();
        vector<int> ans(ln1 + ln2 + 2, 0);
        string ret = "";
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        if(num1 == "0" || num2 == "0")
            return "0";
        
        int cAdd = 0;
        int cMul = 0;
        int mul = 0;
        
        
        for(int i = 0; i < ln1; i++){
            cMul = 0;
            for(int j = 0; j < ln2; j++){
                
                mul =  (num1[i] - '0') * (num2[j] - '0');
                ans[i+j+1] +=  mul / 10;
                ans[i+j] += mul % 10;
                
                if(ans[i+j] >= 10){
                    ans[i+j+1] += ans[i+j] / 10;
                    ans[i+j] = ans[i+j] % 10;
                } 
            }
        }
        int limit = ans.size() - 1;
        while(ans[limit] == 0){
            limit--;
        }
        for(int i = limit ; i >= 0 ; i--){
            ret += ans[i] + '0';
        }
        return ret;
        
    }
};