int Solution::removeElement(vector<int> &A, int B) {
    int countB = 0, size = A.size();
    for (int i = 0; i < size; i++) { 
        if (A[i] != B) {
            A[countB++] = A[i];
        }
    }
    return countB;
}
