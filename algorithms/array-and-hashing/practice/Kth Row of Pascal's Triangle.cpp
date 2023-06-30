/*
 A0->  1
 A1->  1 1
 A2->  1 2 1
 A3->  1 3 3 1
 for A, pascal triangle will have A+1 elements
*/
vector<int> Solution::getRow(int A) {
    vector<int> result;
        int value = 1, index;
        for( index = 0; index <= A ; index++){ 
            result.push_back(value);
            value = value * (A - index)/(index + 1);
        }
    return result;
}
