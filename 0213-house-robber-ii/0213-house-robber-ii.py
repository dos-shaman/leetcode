class Solution:
    def rob(self, nums: List[int]) -> int:
        nlen = len(nums)

        if nlen <= 3: 
            return max(nums)

        def robI(_nums):
            dp = [0] * (nlen - 1)
            dp[0], dp[1] = _nums[0], max(_nums[:2])

            for i in range(2, nlen - 1):
                dp[i] = max(dp[i - 1], dp[i - 2] + _nums[i])

            return dp[-1]

        return max(robI(nums[1:]), robI(nums[:-1]))