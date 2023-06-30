bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int arr = 0, dep = 0;
    
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    
    while(arr < arrive.size()){
        K--;
        // position 'arr' for comparing the departure with next arrival
        arr++;
        // when all rooms are occupied, if a guest arrives before any departure, return failure
        if(K == 0){
            if(arrive[arr] >= depart[dep]){
                K++;
                dep++;
            }    
        }
        if(K < 0){
            return false;
        }
    }
    return true;
}
