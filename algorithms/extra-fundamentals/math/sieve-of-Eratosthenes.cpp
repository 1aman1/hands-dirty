vector<int> Solution::sieve(int A)
{
    bool prime[A + 1];
    memset(prime, true, sizeof(prime));
    // prime number entries in array would be true, non prime-false

    for (int ptr = 2; ptr * ptr <= A; ptr++)
    {
        // if prime[ptr] is true, mark for all the multiples in subsequence that are greater than or equal to ptr^2
        // entries before that have already been marked
        if (prime[ptr])
        {
            for (int i = ptr * ptr; i <= A; i += ptr)
                prime[i] = false;
        }
    }
    vector<int> result;
    for (int ptr = 2; ptr <= A; ptr++)
    {
        if (prime[ptr])
            result.push_back(ptr);
    }
    return result;
}
