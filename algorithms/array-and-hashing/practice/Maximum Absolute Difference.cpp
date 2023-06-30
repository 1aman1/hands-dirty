int Solution::maxArr(vector<int> &A) {
    vector<int> plus = A, minus = A;
    if (A.size() == 1) {
        return 0;
    }
    // prep plus array with A[i] + i, and minus with A[i] - i
    // vectors are cloned so we can use any vector for termination condition
    for (int i = 0; i < plus.size(); i++) {
        plus[i] += i;
        minus[i] -= i;
    }
    //sort both the sequences, pluss'& minuss'
    sort(plus.begin(), plus.end()), sort(minus.begin(), minus.end());
    return max(plus[plus.size() - 1] - plus[0], minus[minus.size() - 1] - minus[0]);
}
