int Solution::diffPossible(vector<int> &A, int diffK) {
    int i = 0;
    int j = i + 1;
 
    while (i < A.size() && j < A.size() && i < j) {
        if (A[j] - A[i] == diffK) {
            return 1;
        } 
        else if ( diffK < A[j] - A[i] ) {
            if (j == i + 1) {
                j++;
            }
            i++;
        }
        else // if ( diffK > A[j] - A[i] ) {
            j++;
    }
    return 0;
}
