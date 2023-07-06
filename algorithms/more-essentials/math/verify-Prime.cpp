int Solution::isPrime(int n) {
  if (n < 2) return 0;
  int upperLimit = (int)(sqrt(n));
  for (int i = 2; i <= upperLimit; i++) {
    if (i < n && n % i == 0) 
      return 0;
  }
  return 1;
}
