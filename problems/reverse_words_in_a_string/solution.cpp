class Solution {
public:
    string reverseWords(string s) {
        // s.erase(remove(s.begin(), s.end(), ' '), s.end());
        stringstream  ss(s);
        string str = "";
        string i = "";
        int j = 0;
        while(!ss.eof()){
            ss >> i;
            if(j == 0){
                str = i;
                j++;
            }
            else
            str = i + " " + str;
            i = "";
            
        }
        // for(auto x = vs.rbegin(); x != vs.rend(); x++){
        //     cout<<*x<<" ";
        // }
        // str.erase(remove(str.begin(), str.end(), ' '), str.end());
        string ret = "";
        if(str[0] == ' ')
            for(int i = 1; i != str.length(); i++)
                ret += str[i];
        else
            ret = str;
        return ret;
    }
};