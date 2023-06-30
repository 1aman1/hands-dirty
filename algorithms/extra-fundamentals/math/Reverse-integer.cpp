int Solution::reverse(int A) {
    long int rev = 0;
    
    do {
        rev = rev*10 + (A%10);    
        A = A/10;
    }while(A != 0);
    
    if( rev > INT_MAX || rev < INT_MIN ) {
        return 0;
    }
    return (int)rev;
}
