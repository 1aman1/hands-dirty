int Solution::solve(string A) {
    // substring counter
    int count = 0;
    for ( int i = 0 ; i < A.size(); ++i) {
        char low = tolower(A[i]);
        if( low == 'a' || low == 'e' || low == 'i' || low == 'o' || low == 'u')
            count += A.size() - i;
        count %= 10003;
    }
    return count;
}
