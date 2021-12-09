class Solution {
public:
    vector<int> v;
    bool ans = false;
    bool canReach(vector<int>& arr, int start) {
        v = arr;
        helper(start);
        return ans;
    }
    
    void helper(int index){

        if(index < 0 || index > v.size() - 1){
            return;
        }
        if(v[index] == 0 || ans){
            ans = true;
            return;
        }
        if(v[index] == -1) return;

        int curr = v[index];
        v[index] = -1;
        
        helper(index + curr);
        helper(index - curr);
    }
};

/*
class Solution {
public:
    vector<int> v;
    bool ans = false;
    bool canReach(vector<int>& arr, int start) {
        v = arr;
        vector<int> visited(arr.size(), 0);
        
        helper(start,visited);
        return ans;
    }
    
    void helper(int index, vector<int>& visited){
        
        // cout<<index<<" ";
        if(index < 0 || index > v.size() - 1){
            return;
        }
        if(v[index] == 0 || ans){
            ans = true;
            return;
        }
        if(visited[index] >= 2) return;
        
        visited[index]++;
        
        // cout<<v[index]<<"->"<<visited[index]<<endl;

        helper(index + v[index],visited);
       if((index - v[index]) >= 0 and 
          v[index - v[index]] + (index - v[index]) == index ) return;
        helper(index - v[index],visited);
    }
};
*/