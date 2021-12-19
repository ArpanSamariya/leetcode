class Solution {
public:
    string ans = "";
    int I = 0;
    string decodeString(string s) {
        int st,end,cnt;
        for(I = 0; I < s.length(); I++){
            if(s[I] >= '0' and s[I] <= '9'){
                ans += sti(s,I);
            }else{
            ans += s[I];    
            }
        }
        return ans;
    }
    
    string sti (string s, int st){
        while(s[I] >= '0' and s[I] <= '9'){
            I++;
        }
        int end = I;
        int cnt = stoi(s.substr(st,end));
        I++;
        string curr = "";
        while(s[I] != ']'){
            if(s[I] >= '0' and s[I] <= '9'){
                curr += sti(s,I);
            }
            //work.
            if(s[I] >= 'a' and s[I] <= 'z'){
             curr += s[I];   
            }
            I++;
        }
        return helper(curr,cnt);
        
    }
    
    string helper(string str, int cnt){
        // cout<<"str in helper "<<str<< " "<<cnt<<endl;
        string ret = "";
        while(cnt--){
            ret += str;
        }
        return ret;
    }
};