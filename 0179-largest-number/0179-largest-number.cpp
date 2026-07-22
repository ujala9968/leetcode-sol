class Solution {
public:
    static bool cmp(string a, string b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {

        vector<string> arr;

        // Convert integers to strings
        for (int num : nums) {
            arr.push_back(to_string(num));
        }

        // Sort using custom comparator
        sort(arr.begin(), arr.end(), cmp);

        // If the largest element is "0", all elements are 0
        if (arr[0] == "0")
            return "0";

        // Concatenate the result
        string ans = "";
        for (string s : arr) {
            ans += s;
        }

        return ans;
    }
};