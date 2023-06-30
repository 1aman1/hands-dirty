/*
NOTE:the order of traversing points is deterministic, hence the problem just reduces to figuring out how to calculate the distance between 2 points.
what only matters is X = abs(A-C) and Y = abs(B-D).
*/

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int total = 0;
    for (int i = 0; i < A.size() - 1; i++) { 
        total += max(abs((A[i + 1]) - (A[i])), abs((B[i + 1]) - (B[i])));
    }
    return total;
}
