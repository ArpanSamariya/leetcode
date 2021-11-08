class Solution {
public:
    int numTrees(int n) {
	long double ans = 1;
	for (int k = 2; k <= n; k++)
		ans *= (n + k), ans /= k;
	return ans;
    }
};


/*
 int numTrees(int n) {
    // Table to store results of subproblems
    unsigned long int catalan[n + 1];
 
    // Initialize first two values in table
    catalan[0] = catalan[1] = 1;
 
    // Fill entries in catalan[] using recursive formula
    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }
 
    // Return last entry
    return catalan[n];
}
*/