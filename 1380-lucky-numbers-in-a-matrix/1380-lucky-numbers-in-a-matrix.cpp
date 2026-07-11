class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& mat) {
        vector<int> vec;
        int r = mat.size();
        int c =mat[0].size();
        vector<int> row(r);
        vector<int> col(c);
        for(int i=0;i<r;i++){
            int minn = INT_MAX;
            for(int j=0;j<c;j++){
               minn= min(minn,mat[i][j]);
            }
            row[i] = minn;
        }
        for(int j=0; j<c;j++){
            int maxx = INT_MIN;
            for(int i=0; i<r;i++){
                maxx = max(maxx,mat[i][j]);
            }
            col[j]= maxx;
        }
        vector<int> ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j] == row[i] && mat[i][j] ==col[j]){
                    ans.push_back(mat[i][j]);
                }
            }
        }
        return ans;
    }
};