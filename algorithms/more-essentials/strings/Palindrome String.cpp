int Solution::isPalindrome(string S) {
    string str = "", revStr;
    // reverse string and raw string should be the same
    // remove all characters, except alphanumeric
    for( auto i:S ) {
        if(isalpha(i)) {
            str += tolower(i);
        }
        else if(isdigit(i))
            str += i;
        else
            ;
    }
    revStr = str;
    reverse(revStr.begin(), revStr.end());
    return str == revStr;
}
