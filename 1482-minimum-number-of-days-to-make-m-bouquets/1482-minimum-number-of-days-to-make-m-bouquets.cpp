class Solution {
public:
    int check(vector<int>& bloomDay, int day, int k) {
        int bouquets = 0;
        int consecutive_flowers = 0;
        
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                consecutive_flowers++;
                if (consecutive_flowers == k) {
                    bouquets++;
                    consecutive_flowers = 0;
                }
            } else {
                consecutive_flowers = 0;
            }
        }
        return bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // If we don't even have enough flowers in total
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }

        int start = 1;
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int res = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            // If we can make at least m bouquets on 'mid' day
            if (check(bloomDay, mid, k) >= m) {
                res = mid;       // Save the day
                end = mid - 1;   // Try to find a smaller day
            } else {
                start = mid + 1; // Need more days
            }
        }   
        return res;    
    }
};