class Solution {
public:

    void solve(vector<int>& nums, int i,
               vector<vector<int>>& ans,
               vector<int>& l1) {

        // Base case
        if (i == nums.size()) {
            ans.push_back(l1);
            return;
        }

        // Not pick
        solve(nums, i + 1, ans, l1);

        // Pick
        int ele = nums[i];
        l1.push_back(ele);

        solve(nums, i + 1, ans, l1);

        // Backtrack
        l1.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> l1;

        solve(nums, 0, ans, l1);

        return ans;
    }
};