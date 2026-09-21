class Solution {
public:

    void solve(int n, int cur, vector<int>& list) {

        if(cur > n) {
            return;
        }

        list.push_back(cur);

        for(int i = 0; i <= 9; i++) {
            int next = cur * 10 + i;

            if(next > n) {
                break;
            }

            solve(n, next, list);
        }
    }

    vector<int> lexicalOrder(int n) {

        vector<int> list;

        for(int i = 1; i <= 9; i++) {

            if(i > n)
                break;

            solve(n, i, list);
        }

        return list;
    }
};