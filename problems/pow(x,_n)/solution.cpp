class Solution {
public:
   
    
    double myP(double base, double x, int n){
       
        if(n == 1)
            return x;
       if(n == 0)
            return 1;
       if(n % 2 == 0){
           return myP(base, x*x, n/2);
       }
            
        if(n % 2 == 1){
            return x*myP(base,x, n-1);
        }
        return 1.0;
            
        
    }
    double myPow(double x, int n) {
       if(n >= 0){
           return myP(x,x,n);
       }
        else{
            n = abs(n);
            double ans = myP(x,x,n);
            if(n != 0 && ans == 1 && abs(x) != 1 )
                return 0.00000;
                
            return 1/ans;
        }   
       
        
    }
};