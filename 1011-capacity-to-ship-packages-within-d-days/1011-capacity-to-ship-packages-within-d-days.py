class Solution:
    def shipWithinDays(self, weights, days):

        low = max(weights)
        high = sum(weights)

        while low < high:

            mid = (low + high) // 2

            days_used = 1
            current = 0

            for weight in weights:

                if current + weight > mid:
                    days_used += 1
                    current = weight
                else:
                    current += weight

            if days_used <= days:
                high = mid
            else:
                low = mid + 1

        return low
        