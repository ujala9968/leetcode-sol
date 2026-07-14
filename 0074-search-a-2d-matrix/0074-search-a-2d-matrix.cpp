class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        //staircase method
        int r=0;
        int c=mat[0].size()-1;
        while(r<mat.size() && c>=0){
            if(mat[r][c] == target){
                return true;
            }
            else if(mat[r][c] <target){
                r++;
            }
            else{
                c--;
            }
        }
        return false;
    }
};