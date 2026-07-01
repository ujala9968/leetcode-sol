class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int nas  = 0;
        int size = 0;
        int si=0;
        int ei = 0;
        int zerocount = 0;
        while(ei<nums.size()){
            if(nums[ei] ==0){
                zerocount++;
            }
            while(zerocount > k){
                if(nums[si] == 0){
                    zerocount--;
                }
                si++;
            }
            nas =max(nas , (ei-si+1));
            ei++;
        }
        return nas;
    }
};