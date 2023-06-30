vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> B;
    if (A.size() <= 0) {
        return B;
    }
    //deal with vacancies
    int start = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != 0) {
            start = i;
            break;
        }
    }

    for (int i = A.size() - 1; i >= start; i--) {
        if (A[i] != 9) {
            A[i]++;
            break;
        } 
        else if (A[i] == 9) {
            A[i] = 0;
            if (i == start) {
                A.push_back(1);
                reverse(A.begin(), A.end());
                break;
            }
        }
    }
    //deal with zzeroes
    if (start != 0) {
        A.erase(A.begin(), A.begin() + start);
    }
    return A;
}
