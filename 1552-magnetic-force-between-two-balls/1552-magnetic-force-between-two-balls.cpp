class Solution {
public:
    bool isitpos(vector<int> position, int m, int mid) {
        int pos = position[0];
        int c = 1;
        for(int i = 1; i <position.size(); i++) {
            if(position[i] - pos >= mid) {
                pos = position[i];
                c++;
            }
            if(c == m) {
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l=1;
        int h = position[position.size()-1] - position[0];
        int ans;
         while(l <= h) {
            int mid = (l + h) / 2;
            if(isitpos(position, m, mid)) {
                ans = mid;
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }

        return ans;



        
    }
};