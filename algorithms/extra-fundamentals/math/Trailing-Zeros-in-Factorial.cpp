int Solution::trailingZeroes(int A) {
    int num = A, countZero = 0;
    while( num / 5 ) {
        countZero += num/5;
        num /= 5;
    }
    return countZero;
}
/*
int Solution::trailingZeroes(int A) {
    int num = A, countZero = 0;
    for ( int i = 5; (num/i) > 0; i=i*5) {
        countZero += num/i;
    }
    return countZero;
}
*/
// both approaches work fine
