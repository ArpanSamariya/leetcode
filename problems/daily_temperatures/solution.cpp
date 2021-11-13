class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> ret(temperatures.size(), 0);
       
        for(int i = temperatures.size() - 2 ; i >= 0; i--){
            int j = 1;
            while( i+j <  temperatures.size() ){
                if(temperatures[i+j] > temperatures[i] ){
                    ret[i] = j;
                    break;
                }
                if(ret[i+j] == 0){
                     ret[i] = 0;
                    break;
                }                
                j = j + ret[i+j];
            }
        }
        return ret;
    }
};