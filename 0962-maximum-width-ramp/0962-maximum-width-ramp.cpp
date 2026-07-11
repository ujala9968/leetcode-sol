class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[n-1] = nums[n-1];
        for(int i=n-2; i>=0;i--){
            ans[i]=max(nums[i],ans[i+1]);
        }
        int i=0;
        int j=1;
        int ans1 = 0;
        while(j<n && i<n){
            if(nums[i]<=ans[j]){
                ans1= max(ans1,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans1;
    }
};