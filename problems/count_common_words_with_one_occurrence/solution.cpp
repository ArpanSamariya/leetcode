class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        
        map<string,int> mp1;
        map<string,int> mp2;
        
        for(int i = 0 ; i < words1.size(); i++){
            mp1[words1[i]]++;
        }
        
        for(int i = 0 ; i < words2.size(); i++){
            mp2[words2[i]]++;
        }
            
         
        int cnt = 0;
        for(auto m : mp1){
            // cout<<m.first << " -> " << m.second<<endl;
            if(m.second == mp2[m.first] and m.second == 1 ){
                cnt++;
            }
        }
        return cnt;
        
    }
};