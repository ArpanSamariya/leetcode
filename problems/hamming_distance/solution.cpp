class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int cnt = 0;
        while(z){
            if( z % 2 == 1) cnt++;
            z /= 2;
        }
        return cnt;
    }
};