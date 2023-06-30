int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int i = 0, j = 0, k = 0, result = INT_MAX;

    while (i < A.size() && j < B.size() && k < C.size())
    {
        int diff = abs(max(max(A[i], B[j]), C[k]) - min(min(A[i], B[j]), C[k]));
        if (diff < result)
        {
            result = diff;
        }
        if (A[i] == min(min(A[i], B[j]), C[k]))
            i++;
        else if (B[j] == min(min(A[i], B[j]), C[k]))
            j++;
        else if (C[k] == min(min(A[i], B[j]), C[k]))
            k++;
    }
    // return result
    return result;
}
