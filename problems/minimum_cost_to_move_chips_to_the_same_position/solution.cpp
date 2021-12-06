class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int ansz = 0;
        int anso = 0;
        int mod;
        for(int i =0; i< position.size(); i++){
            mod = position[i]%2;
            if(mod == 0)
            ansz++; 
            else
                anso++;
        }
        return min(ansz, anso);
    }
};