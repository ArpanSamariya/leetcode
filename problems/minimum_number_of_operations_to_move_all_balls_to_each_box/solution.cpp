class Solution {
public:
    
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.length(),0);
        for(int i = 0; i < boxes.length(); i++){
            for(int j = 0 ; j < boxes.size(); j++){
                if(boxes[j] == '1'){
                    ans[i] += abs(j-i);
                }
            }
        }
        return ans;
    }
};