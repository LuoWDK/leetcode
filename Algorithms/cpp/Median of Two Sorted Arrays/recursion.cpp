class Solution {
public:
    int findKth(vector<int>& nums1, int lo1, int hi1, vector<int>& nums2, int lo2, int hi2, int k){
        if (lo1 > hi1)
            return nums2[lo2 + k - 1];
        if (lo2 > hi2)
            return nums1[lo1 + k - 1];
        int m1 = (lo1 + hi1) >> 1;
        int m2 = (lo2 + hi2) >> 1;
        int halfLen = (m1 - lo1) + (m2 - lo2) + 1;
        if (nums1[m1] < nums2[m2]){
            if (k <= halfLen){
                return findKth(nums1, lo1, hi1, nums2, lo2, m2-1, k);
            }
            else{
                return findKth(nums1, m1+1, hi1, nums2, lo2, hi2, k-(m1-lo1)-1);
            }
        }
        else{
            if (k <= halfLen){
                return findKth(nums1, lo1, m1-1, nums2, lo2, hi2, k);
            }
            else{
                return findKth(nums1, lo1, hi1, nums2, m2+1, hi2, k-(m2-lo2)-1);
            }
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        bool flag = (len1 + len2) & 1;
        int halfLen = (len1+len2+1)>>1;
        double ans = (double)findKth(nums1, 0, len1-1, nums2, 0, len2-1, halfLen);
        if (!flag){
            double ans2 = (double)findKth(nums1, 0, len1-1, nums2, 0, len2-1, halfLen+1);
            ans += ans2;
            ans /= 2.0;
        }
        return ans;
    }
};
