class Solution {
public:
    vector<vector<int>> vv;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       vector<int> tmp;
       // tmp.push_back(0);
       helper(0, graph, tmp );  
       return vv;
    }
    void helper(int i,vector<vector<int>>& graph, vector<int> ret){
        
        ret.push_back(i);
        
        if(i == graph.size() -1){
            vv.push_back(ret);
        }
        
        for(int j = 0; j < graph[i].size(); j++){
            helper(graph[i][j], graph, ret);     
        }
    }
};