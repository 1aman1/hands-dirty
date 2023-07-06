int Solution::cpFact(int A, int B) {
    do {
        A /= __gcd(A, B);
    } while( __gcd(A, B) != 1 );
    return A;
}
// A % X ==  0 -> A = NX, gcd ( NX, B)
