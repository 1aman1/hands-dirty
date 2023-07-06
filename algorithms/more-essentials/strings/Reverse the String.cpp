void Solution::reverseWords(string &A) {
    string word, revSeq;
    /*
    string stream aids by associating a string object with a stream
    to read from the string as if it were a stream,by using '>>' operator
    this op catches the stream word by word i.e., sequence separated using comma'
    */
    stringstream ss(A);
    
    while( ss >> word ) {
        revSeq = word + " " +revSeq;
    }    
    
    /*
    the sequence catches an extra space in the end which can be removed by
    using substr
    */
    A = revSeq.substr(0, revSeq.size()-1);
}
