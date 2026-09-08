class Solution:
    def countCommas(self, n: int) -> int:
        c = 0
        t = 1000
        if n>= t:
            c+=(n-t+1)
            t *= 1000
        return c
        