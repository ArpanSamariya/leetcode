class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int currSum = 0;
        int steps = 0;
        int currCap = capacity;
        int i = 0;
        
        for(int i = 0 ; i < plants.size(); i++){
        
            if( currCap >= plants[i]){
                currCap -= plants[i];
                steps++;
            } else {
                steps += 2*(i) + 1;
                currCap = capacity;
                currCap -= plants[i];
            }
        }
        return steps;
    }
};