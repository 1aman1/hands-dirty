int Solution::repeatedNumber(const vector<int> &A) {
    int size = A.size();
    vector<bool> lookup(size,0);
    
    for(int i = 0; i < size;i++){
        if( lookup[A[i]] == 0 )
            lookup[A[i]]=1;
        else
            return A[i];
    }
    return -1;
}
/*
int i,x=0;
    for(i=0;i<A.size();i++)
    {
        x^=A[i];
        x^=i;
    }
    return x;
}
*/
