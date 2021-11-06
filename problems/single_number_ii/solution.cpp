class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        
        if (nums.size() == 1){
            return nums[0];
            }
            

            
            
          
        


          
       
        
     


while(i < nums.size() - 3){
            cout<<i<<" ";
           if ( nums[i] != nums[i+1]){
            return nums[i];
            }
            
          //cout<<nums[i]<<nums[i+1]<<nums[i+2]<<endl;
            
        

          if(nums[i] == nums[i+1] and nums[i+1] == nums[i+2]){
            i = i + 3;  
          } else {
              
            i++;
              }
        }
        return nums[nums.size()-1];
    }
};