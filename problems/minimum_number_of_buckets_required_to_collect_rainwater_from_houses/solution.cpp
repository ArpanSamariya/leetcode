class Solution {
public:
    int minimumBuckets(string street) {
        
        if(street == ".")
            return 0;
        if(street == "H")
            return -1;
        
        int len = street.length();
        int cnt = 0;
        
        if(street[0] == 'H' and street[1] == 'H')
            return -1;
        if(street[len - 1] == 'H' and street[len - 2] == 'H')
            return -1;
        
        if(street[0] == 'H' and street[1] == '.')
        {
            street[1] = 'B';
            cnt++;            
        }

         // if(street[0] == '.' and street[1] == 'H')
         //    cnt++;
        
        if(street[len - 1] == 'H' and street[len - 2] == '.'){
            cnt++;       
            street[len - 2] = 'B';
        }
            
        // cout<<cnt<<endl;
        for(int i = 1; i < len -1; i++){
            // cout<<street<<" "<<cnt<<endl;
            if(street[i] == 'H'){
                
                // if(street[i+1] == 'H' || street[i-1] == 'H' and (street[i+1] != '.' || street[i-1] == '.')
                //    and (street[i+1] != 'B' || street[i-1] != 'B'))
                //     return -1;
                
                if(street[i+1] == 'H' and street[i-1] == 'H'){
                        return -1;
                }
                
                if(street[i+1] == 'B' || street[i-1] == 'B')
                    continue;               
                
                if(street[i+1] == '.'){
                    cnt++;
                    street[i+1] = 'B';
                }else if(street[i-1] == '.'){
                    cnt++;
                    street[i-1] = 'B';
                }
            }
        }
        // cout<<street;
        return cnt;
    }
};