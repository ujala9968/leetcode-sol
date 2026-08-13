class Solution:
    def searchMatrix(self, mat: List[List[int]], target: int) -> bool:
        r = len(mat)
        c = len(mat[0])
        l=0
        h = r*c-1
        while(l<=h):
            mid =l+(h-l)//2
            row = mid //c
            col = mid % c
            if mat[row][col] == target:
                return True
            elif mat[row][col] < target:
                l = mid +1
            else:
                h = mid -1
        return False

       


        

        