vector<int> Solution::sieve(int A) {
    bool prime[A+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int ptr = 2; ptr*ptr <= A; ptr++) { 
        if (prime[ptr]) { 
            for (int i = ptr*ptr; i <= A; i += ptr) 
                prime[i] = false; 
        } 
    }
	
    vector<int> result;
    for (int ptr = 2; ptr <= A; ptr++) {
       if (prime[ptr]) 
            result.push_back(ptr);
    }
    return result;
}
