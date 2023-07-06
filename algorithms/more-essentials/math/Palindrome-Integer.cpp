int Solution::isPalindrome(int A) {
    if( A < 0 )
        return false;
    else {
        int rev = 0, copy = A;
        do {
            rev = rev*10 + (A%10);    
            A = A/10;
        } while(A != 0);
        if( rev == copy )
            return true;
        else 
            return false;
    }
}
