class Solution {
public:
    bool check(vector<int>&nums, int mid ,int k){
        int c= 1;
        int sum = 0;
        for(int num : nums){
            if(sum+num > mid){
                c+=1;
                sum=num;
            }
            else{
                sum+=num;
            }
        }
        return c<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low<high){
            int mid = low + (high-low)/2;
            if(check(nums,mid,k)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        } 
        return low;
    }
};