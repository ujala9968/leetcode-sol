class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;

        for (int i = 0; i < chars.size(); i++) {
            char curr = chars[i];
            int count = 0;

            while (i < chars.size() && chars[i] == curr) {
                count++;
                i++;
            }

            chars[idx++] = curr;

            if (count > 1) {
                string s = to_string(count);

                for (char ch : s) {
                    chars[idx++] = ch;
                }
            }

            i--;   // because the for loop will increment i
        }

        return idx;
    }
};