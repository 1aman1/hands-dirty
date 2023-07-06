string Solution::convertToTitle(int A) {
    string B;
    char c;
    while( A > 0 ) {
        c = ((A - 1) % 26) + 65;
        B += c; //rightmost character is captured first, hence the sequence constructed is reverse of original
        A = (A - 1)/ 26;
    }
    reverse(B.begin(), B.end());
    return B;
}
