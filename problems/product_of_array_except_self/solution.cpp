// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> ret(nums.size(),0);
//         vector<int> left(nums.size(),0);
//         vector<int> right(nums.size(),0);
        

//         long long int pro = 1;
       
//         for(int i = 0; i < nums.size(); i++){
//             pro *= nums[i];
//             left[i] = pro;
//         }
        
//         pro = 1;
//         for(int i = nums.size() - 1; i >= 0; i--){
//             pro *= nums[i];
//             right[i] = pro;
//         }        
        
//         // for(auto i : left) cout<<i<<" ";
//         // cout<<endl;
//         // for(auto i : right) cout<<i<<" ";
        
//         for(int i = 1; i < nums.size() - 1; i++){
//             ret[i] = (left[i-1] * right[i+1]);
//         }
        
//         ret[0] = right[1];
//         ret[nums.size()-1] = left[nums.size()-2];
        
//         return ret;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(),0);
        // vector<int> left(nums.size(),0);
        // vector<int> right(nums.size(),0);
        

        long long int pro = 1;
        long long int left = 1;
        long long int right = 1;
                

        int cntZ = 0;
        int index = 0;
       
        for(int i = 0; i < nums.size(); i++){
           if(nums[i] == 0){
               cntZ++;
               index = i;
           }
               
        }
        if(cntZ > 1)
            return ret;
        
        if(cntZ == 1){
        for(int i = 0; i < index; i++){
            left *= nums[i];
        }   
        for(int i = index+1; i < nums.size(); i++){
            right *= nums[i];
        }  
        // cout<<left<< " "<<right;
        ret[index] = left * right;
        return ret;
        }
        // for(auto i : left) cout<<i<<" ";
        // cout<<endl;
        // for(auto i : right) cout<<i<<" ";
        
        for(int i = 0; i < nums.size(); i++){
           pro *= nums[i];
        }
        // cout<<pro;
        for(int i = 0; i < nums.size(); i++){
           ret[i] = pro/nums[i];
        }        
       
        
        return ret;
    }
};