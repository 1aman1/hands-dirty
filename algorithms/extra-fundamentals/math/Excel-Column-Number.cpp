int Solution::titleToNumber(string A) {
    if (A.size() <= 0) {
        return 0;
    }
    int sum = 0, size = A.size();
    for ( int i = 0; i < size; i++ ) {
        sum = 26 * sum + (int)(A[i] - '@') ; //@ comes prior to 'A' in ascii format
        // OR sum += pow(26, size -1 -i) * (int)(A[i] - 64);
    }
    return sum;
}
