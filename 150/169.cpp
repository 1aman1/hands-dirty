class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0 ;
        int counter = 0;

        for ( const auto & num : nums ){
            if (count == 0){
                result = num;
            }
            counter += result == num ? 1 : -1;
        }
        
        return result;
    }
};