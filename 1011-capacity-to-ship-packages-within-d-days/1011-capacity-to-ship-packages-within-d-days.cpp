class Solution {
public:
    bool solve(vector<int> weights, int days,int mid){
        int curr = 0;
        int usedays = 1;
        for(int i=0;i<weights.size();i++){
            if(curr + weights[i] <= mid){
                curr += weights[i];
            }
            else{
                usedays += 1;
                curr = weights[i];
            }
            if(usedays>days){
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = 0;
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid = low + (high-low) /2;
            if(solve(weights,days,mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};