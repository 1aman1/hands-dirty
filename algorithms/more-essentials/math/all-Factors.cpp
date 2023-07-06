vector<int> Solution::allFactors(int val) {
    vector<int> result;
    
    int upperLim = (int)sqrt(val);
    //algo is utilising a fact that factors always exist in pairs i.e.,co-factors
    for( int i = 1; i <= upperLim; ++i ) {
        if( !(val % i ) ) {
            result.push_back(i);
            if( i != val /i )
                result.push_back(val / i);
        }
    }
    sort( result.begin(), result.end() );
    return result;
}
