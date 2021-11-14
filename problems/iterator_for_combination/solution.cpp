class CombinationIterator {
public:
    vector<string> comb;
    stack<string> st;
    CombinationIterator(string characters, int combinationLength) {
        
        long long unsigned int mask = 1 << characters.length();
        string tmp = "";
        long long unsigned int  curr; 
        int j = 0;
        for(long long unsigned int i = 1; i < mask; i++)
        {
             bitset<15> b1(i);
            if(b1.count() != combinationLength)
                continue;
            
            tmp = "";
            curr = i;
            j = 0;
            while(curr){
                if(curr&1) tmp += characters[j];
                j++;
                curr >>= 1;
            }
            if(tmp.length() == combinationLength){
                comb.push_back(tmp);
            }
        }
        
        sort(comb.begin(), comb.end());
        
        for(int i = comb.size() - 1; i >= 0; i--){
            st.push(comb[i]);
        }
    }
    
    string next() {
        string str;
        str = st.top();
        st.pop();
        return str;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */