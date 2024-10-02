// 88. Merge Sorted Array
// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

class Solution
{
public:
    void merge(vector<int> &nums1Main, int m, vector<int> &nums2, int n)
    {
        int nums1Len = m;
        int nums2Len = n;

        vector<int> nums1(nums1Main.begin(), nums1Main.begin() + nums1Len);

        int i = 0, j = 0, k = 0;
        while (i < nums1Len && j < nums2Len)
        {
            if (nums1[i] <= nums2[j])
            {
                nums1Main[k++] = nums1[i++];
            }
            else
            {
                nums1Main[k++] = nums2[j++];
            }
        }
        while (i < nums1Len)
        {
            nums1Main[k++] = nums1[i++];
        }
        while (j < nums2Len)
        {
            nums1Main[k++] = nums2[j++];
        }
    }
};