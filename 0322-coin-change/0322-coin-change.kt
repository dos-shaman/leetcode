class Solution {
    fun coinChange(coins: IntArray, amount: Int): Int {

    val dp = IntArray(amount + 1) { amount + 1 }
    dp[0] = 0

    for (coin in coins) {
        for (i in coin..amount) {
            dp[i] = minOf(dp[i], dp[i - coin] + 1)
        }
    }
    return if (dp[amount] > amount) -1 else dp[amount]
    }
}