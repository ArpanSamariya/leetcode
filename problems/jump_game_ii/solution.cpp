class Solution {
public:
    int jmp = 0;
    
     int help(int start, int end, vector<int>& nums){
         int index;
        if(start == end){
            return start;
        }
        int mx = INT_MIN;
         cout<<start<<" "<<end<<endl;
        for(int i = start; i <= end and i < nums.size(); i++){
            if(i + nums[i] >= nums.size() -1) return i;
            if(mx <= (i+nums[i])){
                mx = i+nums[i];
                index = i;
            }
          
        }
         // cout<<"mx is "<<mx<<endl;
        return index;
    }
    
    int jump(vector<int>& nums) {
        int i = 0;
        
        if(nums.size() == 1)
            return 0;
        int g = 0;
        while(i < nums.size()){
            

         if(i+nums[i] >= nums.size() -1) return jmp+1;
        // for(int i =0; i < nums.size(); i++){
            // i += g;
            jmp++;
            // cout<<"i is "<<i<<endl;
            i = help(i, i + nums[i] , nums);
            cout<<i<<endl;
            if(i == nums.size() - 1 ) return jmp;
           
             // if( i >= nums.size()-1) return jmp+1;
            
            // cout<<"i is "<<i<<endl;
        }
       
        return jmp;
    }
};