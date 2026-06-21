class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        int size = m + n;
        int idx1 = (size / 2) - 1;
        int idx2 = size / 2;

        int ele1 = -1, ele2 = -1;
        int i = 0, j = 0, k = 0;

        while (i < m && j < n) {

            int curr;

            if (nums1[i] < nums2[j]) {
                curr = nums1[i++];
            } else {
                curr = nums2[j++];
            }

            if (k == idx1) ele1 = curr;
            if (k == idx2) ele2 = curr;

            k++;
        }

        while (i < m) {
            int curr = nums1[i++];

            if (k == idx1) ele1 = curr;
            if (k == idx2) ele2 = curr;

            k++;
        }

        while (j < n) {
            int curr = nums2[j++];

            if (k == idx1) ele1 = curr;
            if (k == idx2) ele2 = curr;

            k++;
        }

        if (size % 2)
            return ele2;

        return (ele1 + ele2) / 2.0;
    }
};