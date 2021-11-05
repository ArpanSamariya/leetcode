class Solution {
public:
    int arrangeCoins(int n) {
        unsigned long i = 0;
        unsigned long t = n;
        while(
            i*(i+1) < 2*t
        ){
            i++;
        }
        if(i*(i+1) == 2*t)
              return i;
        return i-1;
    }
};