vector<int> Solution::repeatedNumber(const vector<int> &A) {
/*
sum1toN -> 1....N, sequence ->1....+A-B...N
AsqMINUSBsq = A^2 - B^2
*/
    long long sum1toN = (A.size() * (A.size() + 1)) / 2, sumOfSequence = 0, AsqMINUSBsq = 0;
    for (int i = 0; i < A.size(); i ++) {
        sumOfSequence += A[i];
        AsqMINUSBsq += (long long)(i + 1) * (long long)(i + 1) - ((long long)(A[i]) * (long long)(A[i]));
    }
       
    int AminusB = sum1toN - sumOfSequence, AplusB, a, b;
    AplusB = AsqMINUSBsq / AminusB;
    b = (AplusB + AminusB) / 2;
    a = AplusB - b;
    
    vector<int> result{a, b};
    return result;
}
