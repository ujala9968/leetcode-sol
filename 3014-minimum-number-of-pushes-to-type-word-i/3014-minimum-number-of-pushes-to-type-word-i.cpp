class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;

        // Count frequency of each character
        for(int i = 0; i < word.length(); i++) {
            mp[word[i]]++;
        }

        // Store frequencies
        vector<int> freq;

        for(auto x : mp) {
            freq.push_back(x.second);
        }

        // Most frequent characters should get minimum pushes
        sort(freq.rbegin(), freq.rend());

        // Calculate minimum pushes
        int ans = 0;

        for(int i = 0; i < freq.size(); i++) {
            ans += freq[i] * ((i / 8) + 1);
        }

        return ans;
    }
};