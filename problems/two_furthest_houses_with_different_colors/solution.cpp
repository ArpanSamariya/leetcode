class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int mx = 1;
        
        for(int i  = 0; i < colors.size() - 1; i++){
            for(int j = i + 1; j < colors.size(); j++){
                if(colors[i] != colors[j]){
                mx = max(mx, abs(i - j) );
                }
            }
        }
        return mx;
    }
};