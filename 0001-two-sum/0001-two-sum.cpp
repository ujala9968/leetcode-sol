class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        for(int i=0;i<nums.size();i++){
            int searchh= target - nums[i];
            if(seen.find(searchh) != seen.end()){
                return { i,seen[searchh]};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};