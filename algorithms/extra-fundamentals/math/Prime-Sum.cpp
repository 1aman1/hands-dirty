vector<int> Solution::primesum(int A) {
    vector<bool> primes(A);
    primes.assign(A, true);
    vector<int> result;
    
    for(int i = 2; i <= sqrt(A); i++){
        if(primes[i] == true){
            for(int j = i*i; j <= A; j += i){
                primes[j] = false;
            }
        }
    }
    
    for(int i = 2; i < A; i++){
        if(primes[i] == true){
            if(primes[A - i] == true){
                result.push_back(i);
                result.push_back(A-i);
                return result;
            }
        }
    }
}
