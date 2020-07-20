class Solution {
public:
    string addBinary(string a, string b) {

        int len = max(a.length(), b.length());
        if(a.length() == b.length()){
            a = "0" + a;
            b = "0" + b;
        }
        if(a.length() < b.length()){
           string s(b.length()-a.length() + 1,'0');
           a = s + a;  
            b = "0"+ b;
        }
        else if(b.length() < a.length()){
            string s(a.length()-b.length() + 1,'0');
            b = s + b;
            a = "0"+ a;
        }
        
        string c(len+1,'0');
        string ans(len+1,'0');
        // cout<<a<<" "<<b<<" "<<c<<" "<<ans<<" ";
        for(int i = len; i > 0 ; i--){
            // cout<<i<<" ";
            if(a[i]-'0' + b[i]-'0' + c[i]-'0' == 0){
                ans[i] = '0';
            }
            if(a[i]-'0' + b[i]-'0' + c[i]-'0' == 1){
                ans[i] ='1';
            }
            if(a[i]-'0' + b[i]-'0' + c[i]-'0' == 2){
                ans[i] = '0';
                c[i-1] = '1';
            }
            if(a[i]-'0' + b[i]-'0' + c[i]-'0' == 3){
                ans[i] = '1';
                c[i-1] = '1';
               
                
            }          
         
            // cout<<endl<<a[i]<<" "<<b[i]<<" "<<ans<<" "<<c;    
        }
        
        if(c[0] == '1'){
            ans[0] = '1';
        }
        else{
            string ret(len,'0');
            for(int i = 1,j=0; i < ans.length(); i++, j++){
                ret[j] = ans[i];
                
            }
            return ret;
            
        }
        return ans;
    }
};