class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int mxP = 1;
        int mnP = 1;
        int mxN = 1, mnN =1;
        int localMax = nums[0];
        
        for(int i = 0 ; i < nums.size(); i++){
            
           mnN = min({nums[i], mnP*nums[i], mxP*nums[i]}); 
           mxN = max({nums[i], mxP*nums[i], mnP*nums[i]});
           mxP = mxN;
           mnP = mnN;
           // cout<<nums[i]<<" "<<mnP<<" "<<mxP<<endl;
           localMax = max(mxP, localMax); 
        }
        return localMax;
    }
    //     int curr;
    //     int mxP = nums[0];
    //     int localMax;
    //     for(int i = 0 ; i < nums.size(); i++){
    //         curr = nums[i];
    //         localMax = curr;
    //         for(int j = i+1; j <  nums.size(); j++){
    //            curr *= nums[j]; 
    //            localMax = max(localMax, curr); 
    //         }
    //        mxP = max(mxP, localMax);
    //     }
    //     return mxP;
    // }
};