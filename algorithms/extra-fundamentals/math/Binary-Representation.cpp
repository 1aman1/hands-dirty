string Solution::findDigitsInBinary(int A) {
    string bitSequence;
    if ( A == 0)
          return "0";
    else {
      while( A > 0) {
          int rem = A % 2;
          A /= 2;
          if ( rem == 0 )
              sequence += "0";
          else
              sequence += "1";
      }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}
