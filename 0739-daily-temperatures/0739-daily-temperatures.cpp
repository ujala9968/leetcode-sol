
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first < temp[i]) {
                int prevIndex = st.top().second;
                st.pop();

                ans[prevIndex] = i - prevIndex;
            }

            st.push({temp[i], i});
        }

        return ans;
    }
};
