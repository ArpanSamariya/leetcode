class Solution {
public:
    int monotoneIncreasingDigits(int n) {

        string Nstr = to_string(n);
        vector<int> op;
        for(int i = 0 ; i < Nstr.length(); i++){
            op.push_back(0);
        }
        
        for(int i = 0 ; i < Nstr.length()-1; i++) {
   
            if(Nstr[i] <= Nstr[i+1]) {
                
                op[i] = Nstr[i]-'0';
                op[i+1] = Nstr[i+1]-'0';
                
            } else {

                int j = i;
                op[i] = Nstr[i] - '0' - 1;
                while( j!= 0 and Nstr[j] == Nstr[j-1]){

                    op[j] = 9;
                    op[j-1] =  Nstr[i] - '0' - 1;
                    j--;
                   if(j == 0) 
                        break;
                }
                
                for(int j = i+1; j < Nstr.length(); j++){
                    op[j] = 9;
                }
                break;
            }
        }
        int ret = op[0];
        for(int i = 1; i < op.size(); i++){
            ret = ret * 10 + op[i];
        }
        
        
        return ret;
    }
};