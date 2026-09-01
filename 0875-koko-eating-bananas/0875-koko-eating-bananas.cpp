class Solution {
public:
    bool solve(vector<int> piles, int h,int mid){
        int currhour=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i] <= mid){
                currhour ++;
            }
            else if(piles[i]%mid == 0){
                currhour =currhour + piles[i] /mid;
            }
            else{
                currhour = currhour + (piles[i]/mid)+1;
            }
            if(currhour > h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int ans =0;
        int high = *max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid = low + (high-low) /2; //speed of eating banana by kokko
            if(solve(piles,  h,mid)){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;

    }
};