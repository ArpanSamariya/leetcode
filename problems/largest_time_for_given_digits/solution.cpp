class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int hour = -1, min = -1;
        int first,second,third,fourth;
        int cur_hour, cur_min;
        sort(A.begin(), A.end());
        do{
            
            cur_hour = A[0]*10 + A[1];
            cur_min = A[2]*10 + A[3];
            
            if(cur_hour < 24 and cur_min < 60){
                if(hour < cur_hour){
                   
                        hour = cur_hour;
                        min = cur_min;
                        first = A[0];
                        second = A[1];
                        third = A[2];
                        fourth = A[3];
                    
                }
                if(hour == cur_hour)
                {
                     if(min < cur_min){
                        hour = cur_hour;
                        min = cur_min;
                        first = A[0];
                        second = A[1];
                        third = A[2];
                        fourth = A[3];  
                     }
                }
                
            }
          
        }while(next_permutation(A.begin(), A.end()));
        if(hour == -1 and min == -1){
            return "";
        }
        
        return to_string(first) + to_string(second) + ":" + to_string(third) + to_string(fourth); 
        
//         string ans = "";
//         sort(A.begin(), A.end());
//         int first = -1, l_pos = 0;
//         for(int i = 0; i < A.size(); i++)
//         {
//           if(A[i] <= 2){
//               if(first < A[i])
//               {
//                   first = A[i];
//                   l_pos = i;
//               }
//           }
            
//         }
//         A.erase(A.begin()+l_pos);
//         if(first == -1){
//             return ans;
//         }
        
//         //second position
//         sort(A.begin(), A.end());
//         int second = -1; l_pos = 0;
//         int cur = 0;
//         for(int i = 0; i < A.size(); i++)
//         {
//             cur = first * 10 + A[i];
//             if(cur <= 23)
//             {
//               if(second < A[i])
//               {
//                   second = A[i];
//                   l_pos = i;
//               }
//           }
            
//         }
//          A.erase(A.begin()+l_pos);
//         if(second == -1){
//             return ans;
//         }
        
//         //third
//          sort(A.begin(), A.end());
//         int third = -1;l_pos = 0;
//         for(int i = 0; i < A.size(); i++)
//         {
//           if(A[i] <= 5){
//               if(third < A[i])
//               {
//                   third = A[i];
//                   l_pos = i;
//               }
//           }
            
//         }
//          A.erase(A.begin()+l_pos);
//         if(third == -1){
//             return ans;
//         }
        
        
//         //fourth
        
//          sort(A.begin(), A.end());
//         int fourth = -1; l_pos = 0;
//         for(int i = 0; i < A.size(); i++)
//         {
//             cur = third* 10 + A[i];
//           if(cur <= 59){
//               if(fourth < A[i])
//               {
//                   fourth = A[i];
//                   l_pos = i;
//               }
//           }
            
//         }
//          A.erase(A.begin()+l_pos);
//         if(fourth == -1){
//             return ans;
//         }
        
//         ans += to_string(first) + to_string(second) + ":" + to_string(third) + to_string(fourth); 
//         return ans;
        
        
        
      return "";  
    }
};