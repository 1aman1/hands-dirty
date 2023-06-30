bool customFunc(int a, int b) {
	string A = to_string(a);
	string B = to_string(b);
	string AB = A + B;
	string BA = B + A;
	//customFunc returns -ve if 'this' ptr has lesser lexicographic value than the arg's value, 0 for equal, then +ve
	return AB.compare(BA) > 0 ? 1 : 0;
}

string Solution::largestNumber(const vector<int> &A) {
	vector<int> B(A.begin(), A.end());
	sort(B.begin(), B.end(), customFunc);
	string result;
	int count0 = 0;
	for (int i = 0; i < B.size(); i++) {
		if (B[i] == 0) {
			++count0;
		}
		result += to_string(B[i]);
	}
	if (count0 == B.size()) {
		return "0";
	}
	return result;
}
