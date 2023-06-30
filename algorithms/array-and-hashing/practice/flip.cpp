vector<int> Solution::flip(string A) {
    vector<int> result;
    if (A.length() <= 0) {
        return result;
    }

    int i, L = -1, R = -1, zeroTracker = 0, currLeft = 0, maxI = INT_MIN;

    for (i = 0; i < A.size(); i ++) {
        if (A[i] == '0') {
            zeroTracker ++;
        } else// if (A[i] == '1') {
            zeroTracker --;
        }
		
        // kadane here
        if (zeroTracker > maxI && zeroTracker > 0) {
            maxI = zeroTracker;
            R = i;
            L = currLeft;
        }
        if (zeroTracker < 0) {
            zeroTracker = 0;
            currLeft = i + 1;
        }
    }
    if (L == -1 && R == -1) {
        return result;
    }
    else {
        result.push_back(L + 1);
        result.push_back(R + 1);
    }
    return result;
}
