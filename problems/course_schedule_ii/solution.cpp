class Solution {
public:
    
    bool cal(vector<int> graph[], int course, vector<int> &taken, vector<int> &ans, set<int> &s, set<int> path){
        
        bool ret = true;
        if(taken[course] == 0){
            
            if(path.find(course) == path.end())
            {
            // bool completed = false;
            // bool ret = true;
            int com = 0;
            path.insert(course);
            for(int i = 0 ; i < graph[course].size(); i++){
                
                ret = ret && cal(graph, graph[course][i], taken, ans,s, path);
                if(ret == false)
                    return false;
            }
            
            taken[course] = 1;
            ans.push_back(course);
            s.erase(course);           
            }
            else
                return false;
        }
        return ret;
    }
        
        
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> graph[n];
        int x,y, maxi,mini;
        set<int>s, path;
        // bool flag = true;
        for(int i = 0 ; i < prerequisites.size(); i++){
            x = prerequisites[i][0];
            y = prerequisites[i][1];
           //  maxi = max(x,y);
           //  mini = min(x,y);
           //  if(sp.find(make_pair(maxi,mini)) != sp.end())
           //      flag = false;
           // else{
           //     sp.insert(make_pair(maxi,mini));
           // }
            
            graph[x].push_back(y);
        }
        vector<int> taken(n,0);
        vector<int> ans;
        vector<int> emp;
        
        for(int i = 0 ; i < n ; i++){
            if(graph[i].size() == 0)
            {
                 taken[i] = 1;
                ans.push_back(i);
            }
            else
                s.insert(i);
        }
        
            while(!s.empty()){
            if(cal(graph, *s.begin() , taken, ans, s, path) == false)
            {
                return emp;
            }
            }
        
        
        
        return ans;
        
    }
};