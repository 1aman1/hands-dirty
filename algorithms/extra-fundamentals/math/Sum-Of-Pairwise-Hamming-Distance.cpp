int Solution::hammingDistance(const vector<int> &A) {
    long long total = 0;
    for (int i = 0; i < 32; i ++) {
        int tmp = 0;
        for (int j = 0; j < A.size(); j ++) {
            if (A[j] & 1 << i) {
                tmp ++;
            }
        }
        total += (2 *tmp *(A.size() - tmp)) % 1000000007;
    }
    return total%1000000007;
}
