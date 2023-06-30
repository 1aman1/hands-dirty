int Solution::removeDuplicates(vector<int> &A)
{
    A.erase(unique(A.begin(), A.end()), A.end());
    return A.size();
}
/*   OR
int Solution::removeDuplicates(vector<int> &A) {
    set<int> s( A.begin(), A.end() );
    A.assign( s.begin(), s.end() );
    return A.size();
}
*/
