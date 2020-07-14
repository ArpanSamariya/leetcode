class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        int i = 31;
        while(n > 0){
            if(n % 2 == 0){
                m += 0<<i;
            }
            else{
                m += 1 << i; 
            }
            i--;
            n = n/2;
        }
        return m;
    }
};