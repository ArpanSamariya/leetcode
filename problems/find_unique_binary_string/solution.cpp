// class Solution {
// public:
//     int n = 0;
//     string findDifferentBinaryString(vector<string>& nums) {
        
//         int max = pow(2, nums.size() + 1);
//         n = nums.size();
        
//         vector<int> ret(max, 0);
        
//         for(int i = 0 ; i < nums.size(); i++){
//             ret[ convert(nums[i]) ] = -1;
//         }
        
//         // cout<<"ret\n";
//         for(int i = 0; i < max; i++){
//             // cout<<ret[i]<< " ";
//             if(ret[i] == 0)
//             return back(i);
//         }
//         return "0";
//     }
    
//     int convert(string in){
        
        
//         int op = 0;
//         int two = 1;
//         for(int i = in.length() - 1 ; i >= 0 ; i--){
//             op += (in[i] - '0') * two;
//             two <<= 1;
//         } 
//         // cout<<in<< "=> " << op << endl;
//         return op;
//     }
    
//     string back(int in){
//         // cout<<in<< " ";
        
//         string str = "";
//         while(in){
//             str += (in % 2 ) + '0';
//             in = in/2;
//         }
//         reverse(str.begin(), str.end());
        
//         int dif = n - str.length();
//         // cout<<dif<<endl÷÷;
//         string pad = "";
        
//         while(dif > 0){
//             pad += "0";
//             dif--;    
//             // cout<<" curr len " << str.length()<< endl;
//         }
//         return pad + str;
//     }
    
// };


class Solution {
public:
    int n = 0;
    string findDifferentBinaryString(vector<string>& nums) {
       
        string ans = "";
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i][i] == '0'){
                ans += "1";
            }
            else 
                ans += "0";
        }
        return ans;
    }
};