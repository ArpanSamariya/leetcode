class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> vp;
        int minDif = INT_MAX;
        
        for(int i = 0; i < arr.size() - 1; i++){
            if(abs(arr[i] - arr[i+1]) < minDif){
                minDif = abs(arr[i] - arr[i+1]);
            }
        }
        for(int i = 0; i < arr.size() - 1; i++){
            if(abs(arr[i] - arr[i+1]) == minDif){
                vector<int> v;
                v.push_back(arr[i]);
                v.push_back(arr[i+1]);
                vp.push_back(v);
            }
        }
        return vp;
    }
};