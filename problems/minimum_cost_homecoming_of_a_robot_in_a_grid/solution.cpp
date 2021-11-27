class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        
        int a = startPos[0];
        int b = startPos[1];
        
        int x = homePos[0];
        int y = homePos[1];
        
        int cst = 0;
        
        while(a!=x and b != y){
            // cout<<a<<","<<b<<"->"<<cst<<endl;
            if(a > x and b > y){
                // cout<<"This one a > x and b > y"<<endl;
                 cst += min(rowCosts[a-1], colCosts[b-1]);
                if(rowCosts[a-1] < colCosts[b-1])
                {
                    a--;
                } else {
                    b--;
                }
                
            }
            
            if(a > x and b < y){
                // cout<<"This one a > x and b < y"<<endl;
                 cst += min(rowCosts[a-1], colCosts[b+1]);
                if(rowCosts[a-1] < colCosts[b+1])
                {
                    a--;
                } else {
                    b++;
                }
                
            }            
            if(a < x and b > y){
                // cout<<"This one a < x and b > y"<<endl;
                 cst += min(rowCosts[a+1], colCosts[b-1]);
                if(rowCosts[a+1] < colCosts[b-1])
                {
                    a++;
                } else {
                    b--;
                }
                
            }
            if(a < x and b < y){
                // cout<<"This one a < x and b < y"<<endl;
                cout<<rowCosts[a+1]<<" "<<colCosts[b+1]<<endl;
                 cst += min(rowCosts[a+1], colCosts[b+1]);
                if(rowCosts[a+1] < colCosts[b+1])
                {
                    a++;
                } else {
                    b++;
                } 
            }
            
        }
        // cout<<"before a "<<cst<<endl;
        while(a!=x){
           
            if(a<x){
                a++; 
            } else {
                a--;
            }
             cst += rowCosts[a];
        }
        // cout<<"before b "<<cst<<endl;
        while(b != y){
            
            if(b<y){
                b++; 
            } else {
                b--;
            }
            cst += colCosts[b];
        }
        // cout<<"after bb "<<cst<<endl;
        // cout<<a<<" "<<b;
        return cst;
    }
};