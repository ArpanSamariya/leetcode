class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ret;
        
        auto itr1 = nums1.begin();
        auto itr2 = nums2.begin();
        int i = 0;
        int j = 0;
        if(n == 0 ){
            return;
        }
        if(m == 0){
           for(int i = 0; i < nums2.size(); i++){
            nums1[i] = nums2[i];
         }
        }
        
        while( itr1 != nums1.end() and itr2 != nums2.end()){
            if( i < m and *itr1 < *itr2 ){
                ret.push_back(*itr1);
                itr1++;
                i++;
            } else {
                ret.push_back(*itr2);
                itr2++;
                j++;
            }
        }
        
        while(itr1 != nums1.end() and i < m){
            ret.push_back(*itr1);
            i++;
            itr1++;
        }
        
        while(itr2 != nums2.end() and j < n){
            ret.push_back(*itr2);
            j++;
            itr2++;
        }
        
        
        for(int i = 0; i < nums1.size(); i++){
            nums1[i] = ret[i];
        }
    }
};