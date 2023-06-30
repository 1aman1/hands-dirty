int Solution::gcd(int A, int B) {
    if( A < B ) 
        swap( A, B);
    
    if( B == 0 ) 
        return A;
    else
        return gcd(A%B, B);
}
/*
while( A ) {
        int cap = B;
        B = A;
        A = cap % A;
    }
    return B;
}
*/
