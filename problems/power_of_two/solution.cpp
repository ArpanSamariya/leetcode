class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while(n){
            if(n & 1){
                cnt++;
            }
            n = n >> 1;
            if(cnt > 1)return false;
        }
        
        if(cnt == 1)
        return true;
        
        return false;
    }
};