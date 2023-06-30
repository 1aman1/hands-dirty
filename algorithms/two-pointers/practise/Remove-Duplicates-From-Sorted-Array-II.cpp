int Solution::removeDuplicates(vector<int> &A)
{
    for (auto itr = A.begin(); itr != A.end(); ++itr)
    {
        if (count(A.begin(), A.end(), *itr) > 2)
        {
            auto L = lower_bound(A.begin(), A.end(), *itr);
            // cout << L - A.begin();
            auto U = upper_bound(A.begin(), A.end(), *itr);
            // cout << U - A.begin();
            A.erase(L + 2, U);
        }
    }
    // print(A);
    return A.size();
}
