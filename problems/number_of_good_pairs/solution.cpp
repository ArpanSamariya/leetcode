class Solution {
public:

// int nCr(int n, int r) 
// { 
//     long long p = 1, k = 1; 

//     if (n - r < r) 
//         r = n - r; 
  
//     if (r != 0) { 
//         while (r) { 
//             p *= n; 
//             k *= r; 
//            long long m = __gcd(p, k); 
//             p /= m; 
//             k /= m; 
  
//             n--; 
//             r--; 
//         } 
//     }
  
//     else
//         p = 1; 
//     return p; 
 
// } 
    int nCr(int n, int k) 
{ 
    int C[k+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;  // nC0 is 1 
  
    for (int i = 1; i <= n; i++) 
    { 

        for (int j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 
  
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> mp;
        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
        }
       long long  int result =0;
        for(auto i = mp.begin(); i != mp.end(); i++){
            result += nCr(i->second,2);
        }
        
    return result;
    }
    
};