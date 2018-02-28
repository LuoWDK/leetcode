class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if (len1 > len2){
            return findMedianSortedArrays(nums2, nums1);
        }
        int lo = 0, hi = len1, halfLen = (len1 + len2 + 1) >> 1;
        int i, j;
        double left = 0.0, right = 0.0;
        bool flag = (len1 + len2) & 1;
        while(lo <= hi){
            i = (lo + hi) >> 1;
            j = halfLen - i;
            if (i < len1 && nums1[i] < nums2[j-1]){
                lo = i + 1;
            }
            else if (i > 0 && nums1[i-1] > nums2[j]){
                hi = i - 1;
            }
            else{
                if (i == 0){
                    left = nums2[j-1];
                }
                else if (j == 0){
                    left = nums1[i-1];
                }
                else{
                    left = max(nums1[i-1], nums2[j-1]);
                }
                if(flag)
                    return left;
                
                if (i == len1){
                    right = nums2[j];
                }
                else if (j == len2){
                    right = nums1[i];
                }
                else{
                    right = min(nums1[i], nums2[j]);
                }
                return (left+right) / 2.0;
            }
        }
    }
};
