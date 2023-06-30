vector<int> Solution::findPerm(const string A, int B) {
    vector<int> result;
    int low = 1;
    int high = B;

    for (int i = 0; i < A.size(); i++) {
        if (A[i] == 'I') {
          result.push_back(low);
          low++;
        } 
        else {
          result.push_back(high);
          high--;
        }
    }
    result.push_back(low);
    return result;
}
